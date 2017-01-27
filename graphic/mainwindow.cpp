#include "mainwindow.h"

#include "controller/impegnicontroller.h"
#include "controller/clienticontroller.h"
#include "controller/myexception.h"
#include "logic/vectorday.h"
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent):QWidget(parent){
    setWindowTitle("Clendar for your buisness");

    //dichiarazioni oggetti impegni
    gestisciCliente=new QPushButton("Gestione Clienti");
    calendar=new QCalendarWidget(this);

    listaImpegni=new QListWidget(this);
    listaImpegni->setItemDelegate(new MyDelegate(listaImpegni));//imposto il delegato per come è fatto il sott'oggetto

    startImpegno=new MyDateTimeEdit(this);
    startImpegno->setCalendarPopup(true);
    endImpegno=new MyDateTimeEdit(this);
    endImpegno->setCalendarPopup(true);
    descr=new QTextEdit(this);

    type=new TypeComboBox(this);//combobox dei tipi di appuntamento
    cliente=new QComboBox(this);//richiama una funzione del controller dei clienti che restituisce i clienti e popola la box

    //aggiungi cliente---------------------------------------------------
    aggiungiImpegno=new QPushButton("Aggiungi quest' Impegno");
    cancellaImpegno=new QPushButton("Cancella quest' Impegno");

    //connessione agli slot
    connect(cancellaImpegno,SIGNAL(clicked()),this,SLOT(eliminaImpegno()));
    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(aggiornaitem(QDate)));
    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(aggiornaDate(QDate)));
    connect(gestisciCliente,SIGNAL(clicked()),this,SLOT(openGestCli()));
    connect(aggiungiImpegno,SIGNAL(clicked()),this,SLOT(addImpegno()));

    //struttura dati-----------------------------------------------------------------------------------------------------------
    //dichiarazione struttura clienti
    clientecontrol=new ClientiController(this);
    clientecontrol->settaListaClienti();

    //dichiarazione del controller di impegni contente la stuttura dati
    err=new QErrorMessage(this);

    l_startImpegno=new QLabel("Orario di Inizio Nuovo Impegno");
    l_endImpegno=new QLabel("Orario di Fine Nuovo Impegno");
    l_descr=new QLabel("Descrizione Nuovo Impegno");
    l_cliente=new QLabel("Cliente Nuovo Impegno");
    l_type=new QLabel("Tipo Nuovo Impegno");

    prepareLayout();//funzione ch e imposta layout e stile

    try{
        controller=new ImpegniController(this,clientecontrol,new VectorDay());
        controller->AggiornaItemLista(calendar->selectedDate());
    }
    catch(MyException e){
        err->showMessage(e.getText());
    }
    //Label-------------------------------------------------------------------------------------

}

void MainWindow::closeEvent(QCloseEvent*ev){
    ev->accept();
    delete this;
}

void MainWindow::prepareLayout(){
    dx=new QVBoxLayout();
    sx=new QVBoxLayout();
    layoutinsimp=new QHBoxLayout();
    layoutImpegni=new QHBoxLayout();
    layout=new QVBoxLayout();

    //Impostazione layout-------------------------------------------------------------------
    this->resize(800,600);
    this->setMaximumSize(900,600);

    descr->setMaximumHeight(100);
    calendar->setMaximumSize(400,380);
    listaImpegni->setMaximumSize(400,380);
    descr->setMaximumWidth(400);

    layoutImpegni->addWidget(calendar);
    layoutImpegni->addWidget(listaImpegni);

    sx->addWidget(l_startImpegno);
    sx->addWidget(startImpegno);
    sx->addWidget(l_endImpegno);
    sx->addWidget(endImpegno);

    dx->addWidget(l_descr);
    dx->addWidget(descr);
    dx->addWidget(cancellaImpegno);
    dx->addWidget(gestisciCliente);

    sx->addWidget(l_type);
    sx->addWidget(type);
    sx->addWidget(l_cliente);
    sx->addWidget(cliente);

    sx->addWidget(aggiungiImpegno);

    layoutinsimp->addLayout(sx);
    layoutinsimp->addLayout(dx);
    layout->addLayout(layoutImpegni);
    layout->addLayout(layoutinsimp);
    setLayout(layout);

    setStyleSheet("QPushButton{"
                  "background-color: #FF9040;"
                    "border-width: 2px;"
                    "border-radius: 6px;"
                    "font: bold 14px;"
                    "min-width: 10em;"
                    "padding: 6px;"
                  "}"
                    "MainWindow{"
                    "background-color:#80B0D0;"
                  "}"
                  "QComboBox {"
                  "border: 1px solid gray;"
                  "border-radius: 3px;"
                  "padding: 3px 3px 3px 3px;"
                  "}"

                  "QComboBox::drop-down {"
                  "border-radius: 3px;"
                  "}"
                  );
}

void MainWindow::eliminaImpegno(){
    QDate a(calendar->selectedDate());
    try{
    controller->rimuoviImpegno(listaImpegni->currentRow(),a);}
    catch(MyException ecc){
        err->showMessage(ecc.getText());
    }
    aggiornaitem(a);
}

void MainWindow::aggiornaitem(const QDate& a){//dico al controller che deve aggiungere gli impegni di quel giorno(verrà sostituito da uno slot diretto)
    listaImpegni->clear();
    controller->AggiornaItemLista(a);
}
void MainWindow::openGestCli(){
    gest=new GestioneCliente(clientecontrol,controller);
    clientecontrol->addViewClienti(gest);
    clientecontrol->refreshListaClienti();
    gest->show();
}
void MainWindow::addItemToList(QString descrizione, QString start,QString stop,QString cliente){
    QListWidgetItem* test;
    test=new QListWidgetItem;
    test->setData(Qt::DisplayRole,descrizione);
    test->setData(Qt::UserRole + 1, start.append(" - ").append(stop).append(" - ").append(cliente));
    listaImpegni->addItem(test);
}

void MainWindow::addImpegno(){
    if(startImpegno->dateTime()>=endImpegno->dateTime()){
        err->showMessage("Hai inserito la data di partanza che è piu grande di quella di terminazione! -> riprova");
        return;
    }


    int tipo=type->itemData(type->currentIndex()).toInt();
    try{
        if(tipo==0)
            controller->AggiungiImpegno(tipo,startImpegno->dateTime(),endImpegno->dateTime(),descr->toPlainText().toStdString());
        else{
            if(cliente->currentIndex()>cliente->count() ||cliente->currentIndex()<0){//controllo se c'è il cliente
                err->showMessage("Non c'è nessun cliente, ne deve prima selezionare uno.");
                return;
            }
            controller->AggiungiImpegno(tipo,startImpegno->dateTime(),endImpegno->dateTime(),descr->toPlainText().toStdString(),clientecontrol->getCliente(cliente->currentIndex()));
        }
    }
    catch(MyException ecc){
        err->showMessage(ecc.getText());
    }

        //faccio apparire un messaggio di allerta in caso di eccezzione perchè esisteva già
        //err->showMessage("Non puoi inserire questo impegno, sei gia impegnato in quel periodo");
    listaImpegni->clear();
    controller->AggiornaItemLista(startImpegno->dateTime().date());
}
void MainWindow::settaClienteCombo(QString nome,int value)const{
    cliente->addItem(nome,value);
}
void MainWindow::clearClientiCombo()const{
    cliente->clear();
}

void MainWindow::aggiornaDate(const QDate& a){
    startImpegno->setDate(a);
    endImpegno->setDate(a);
}

MainWindow::~MainWindow(){
    gest->close();
    delete gest;
    delete err;
    //cancello le strutture dati
    delete clientecontrol;
    delete controller;

    //cancello i widget al quale non sono riuscito a mettere il parent
    delete l_startImpegno;
    delete l_endImpegno;
    delete l_descr;
    delete l_cliente;
    delete l_type;
    delete dx;
    delete sx;
    delete layoutinsimp;
    delete layoutImpegni;
    delete layout;

}

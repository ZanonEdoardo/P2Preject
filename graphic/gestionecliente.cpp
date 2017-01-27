#include "gestionecliente.h"
#include "controller/impegnicontroller.h"
#include "controller/clienticontroller.h"
#include<QVBoxLayout>
#include <QString>


GestioneCliente::GestioneCliente(ClientiController* client, ImpegniController* imp){
    setWindowTitle("Clendar for your buisness - Gestione clienti");

    impegni=imp;

    addCliente=new QPushButton("Aggiungi Cliente",this);
    removeCliente= new QPushButton("Rimuovi Cliente",this);
    listaClienti=new QListWidget(this);
    Nome=new QTextEdit(this);
    Money=new MoneyEdit(this);
    Extra=new MoneyEdit(this);
    Conto=new QLabel("Calcola Il conto conto",this);
    Da=new MyDateTimeEdit(this);
    A=new MyDateTimeEdit(this);

    CalcolaConto=new QPushButton("Calcola conto",this);
    clientController=client;

    l_Nome=new QLabel("Nome nuovo cliente",this);
    l_Money=new QLabel("Tassazione oraria nuovo cliente   (euro/ora)",this);
    l_extra=new QLabel("Extra nuovo cliente   (euro/ora)",this);

    //connect
    connect(addCliente,SIGNAL(clicked()),this,SLOT(aggiungiCliente()));
    connect(CalcolaConto,SIGNAL(clicked()),this,SLOT(calcConto()));
    connect(removeCliente,SIGNAL(clicked()),this,SLOT(rimuoviCliente()));

    prepareLayout();
}

void GestioneCliente::prepareLayout(){
    layoutdx=new QVBoxLayout();
    layoutoriz=new QHBoxLayout();

    layoutdx->addWidget(l_Nome);
    layoutdx->addWidget(Nome);
    layoutdx->addWidget(l_Money);
    layoutdx->addWidget(Money);
    layoutdx->addWidget(l_extra);
    layoutdx->addWidget(Extra);
    layoutdx->addWidget(addCliente);
    layoutdx->addWidget(removeCliente);
    layoutdx->addWidget(Conto);
    layoutdx->addWidget(Da);
    layoutdx->addWidget(A);
    layoutdx->addWidget(CalcolaConto);

    layoutoriz->addWidget(listaClienti);
    layoutoriz->addLayout(layoutdx);
    setLayout(layoutoriz);

    setStyleSheet("QPushButton{"
                  "background-color: #FF9040;"
                    "border-width: 2px;"
                    "border-radius: 6px;"
                    "font: bold 14px;"
                    "min-width: 10em;"
                    "padding: 6px;"
                  "}"
                    "GestioneCliente{"
                    "background-color:#80B0D0;"
                  "}"
                  "QTextEdit{"
                  "border-width: 2px;"
                  "border-radius: 6px;"
                  "}"
                  );
}

void GestioneCliente::aggiungiCliente()const{
    clientController->addCliente((Nome->toPlainText().toStdString()),Money->text().toFloat(),Extra->text().toFloat());
    clientController->refreshListaClienti();
    clientController->settaListaClienti();
}
void GestioneCliente::rimuoviCliente()const{
    if(listaClienti->currentRow()>=listaClienti->count() || listaClienti->currentRow()<0){
        Conto->setText("Devi prima selezionare il cliente");
        return;
    }
    clientController->removeCliente(listaClienti->currentRow());//ritorno la posizione nella lista, che corrisponde a quella del vettore e la passo alla funzione nel controller
    //riaggiorno la lista dei clienti dall'altra parte
}
void GestioneCliente::addItemLista(const QString& nome,int pos)const{

    listaClienti->insertItem(pos,new QListWidgetItem(nome,listaClienti));
}
void GestioneCliente::svuotaItemLista()const{
    listaClienti->clear();
}
void GestioneCliente::calcConto()const{
    if(listaClienti->currentRow()>=listaClienti->count() || listaClienti->currentRow()<0){
        Conto->setText("Devi prima selezionare il cliente");
        return;
    }
    float result=impegni->Conto(Da->dateTime(),A->dateTime(),clientController->getCliente(listaClienti->currentRow()));
    QString text="Il conto di ";
    text.append(QString::fromStdString(clientController->getCliente(listaClienti->currentRow())->getNome()));
    text.append(" e' di: ");
    text.append(QString::number(result));
    text.append(" euro");
    Conto->setText(text);
}
GestioneCliente::~GestioneCliente(){
    delete layoutdx;
    delete layoutoriz;
}

#include "impegnicontroller.h"
#include "graphic/mainwindow.h"
#include "logic/appuntamento.h"
#include "logic/personale.h"
#include "logic/tempodedicato.h"
#include <QFile>
#include "controller/myexception.h"

ImpegniController::ImpegniController(MainWindow* a,ClientiController*c,VectorDay *vett) :view(a),struttura(vett){
    load(c);
}

void ImpegniController::AggiornaItemLista(const QDate& data){
    //getimpegniday(data)) che ritorna la lista
    try{
        Lista& Impegni=struttura->getImpegnoDay(data);
        Lista::Iteratore it=Impegni.begin();
        Lista::Iteratore end=Impegni.end();
        ImpegnoLavorativo* imp;
        while(it!=end){
            if(imp=dynamic_cast<ImpegnoLavorativo*>(Impegni[it]))
                view->addItemToList(QString::fromStdString(imp->getDescription()),imp->getStart().toString(),imp->getEnd().toString(),QString::fromStdString(imp->getNomeCliente()));
           else
                view->addItemToList(QString::fromStdString(Impegni[it]->getDescription()),Impegni[it]->getStart().toString(),Impegni[it]->getEnd().toString(),"Personale");

            it++;
        }
    }
    catch(MyException e){
        return;
    }

    //faccio un while richiamando la funzione utilizzando l'iteratore di lista
}
void ImpegniController::AggiungiImpegno(int type,QDateTime start,QDateTime stop,std::string descr,const Cliente* clien){//aggiunge un impegno alla struttura dati
    QString FileName="saveImpegni.txt";
    QFile file(FileName);
    if(!file.open(QIODevice::Append|QIODevice::Text))
        throw

        ("Errore nell'apertura del file, l'impegno non verrà salvato") ;//eccezzione
    QTextStream out(&file);

    Impegno* imp;
    switch(type){
    case 0:
        imp=new Personale(start,stop,descr);
        break;
    case 1:
        imp=new Appuntamento(start,stop,descr,*clien);
        break;
    case 2:
        imp=new TempoDedicato(start,stop,descr,*clien);
        break;
    }
    try{ struttura->addAndSave(imp,out);}//si poteva inserire
    catch(MyException ecc){
        delete imp;
        throw ecc;
    }
}
float ImpegniController::Conto(const QDateTime& da ,const QDateTime& a, Cliente* cli){
   return struttura->getMoney(da,a,*cli);
}
void ImpegniController::rimuoviImpegno(int pos,const QDate data)const{
    QString FileName="saveImpegni.txt";
    struttura->remove(pos,data);
    QFile file(FileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
             throw MyException("Errore nell'apertura del file,Impossibile rimuovere l'impegno definitivamente");//eccezzione
    QTextStream out(&file);

    struttura->resave(out);
}
void ImpegniController::load(ClientiController* clienti)const{
    //preparo il file
    QString FileName="saveImpegni.txt";
    QFile file(FileName);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return;//throw MyException("Errore nell'apertura del file, Impossibile caricare gli impegni") ;//eccezzione
    QTextStream in(&file);
    QString type=in.readLine();

    //dichiaro le variabili
    Impegno* imp;
    const QString sformat="yyyy-MM-dd hh:mm:ss";
    QString from,to,descr,cliente;//dichiarazioni delle variabili che contengono i valori
    //ciclo che carica tutti gli elementi dal file

    while(!type.isNull()){
        from=in.readLine();
        to=in.readLine();
        descr=in.readLine();

        //devo prendere i valori e creare l'elemento dopo lo swtch
        switch(type.toInt()){
        case 0:
            cliente=in.readLine();
            imp=new Appuntamento(QDateTime::fromString(from,sformat),QDateTime::fromString(to,sformat),descr.toStdString(),*clienti->getCliente(cliente.toInt()));
            break;
        case 1:
            cliente=in.readLine();
            imp=new TempoDedicato(QDateTime::fromString(from,sformat),QDateTime::fromString(to,sformat),descr.toStdString(),*clienti->getCliente(cliente.toInt()));
            break;
        case 2:
            imp=new Personale(QDateTime::fromString(from,sformat),QDateTime::fromString(to,sformat),descr.toStdString());
            break;
        }
        struttura->add(imp);
        type=in.readLine();
    }
}
ImpegniController::~ImpegniController(){
    delete struttura;
}

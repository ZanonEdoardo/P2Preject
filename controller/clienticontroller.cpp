#include "clienticontroller.h"
#include "graphic/mainwindow.h"
#include "graphic/gestionecliente.h"
#include <QFile>
#include <QTextStream>


ClientiController::ClientiController(MainWindow*b):clientiVect(new QVector<Cliente*>),view(0),mainview(b){
        loadClienti();
}

void ClientiController::settaListaClienti()const{
    //scorro il vettore e li inserisco 1 ad 1
    mainview->clearClientiCombo();
    for(int i=0;i<clientiVect->size();++i)
        mainview->settaClienteCombo(QString::fromStdString(clientiVect->at(i)->getNome()),i);
}
Cliente* ClientiController::getCliente(int pos)const {//ritorna il cliente in quella posizione del vettore
    return clientiVect->at(pos);
}

void ClientiController::addViewClienti(GestioneCliente* w){
    view=w;
}
bool ClientiController::addCliente(std::string nome,float prezzo,float extra)const{
    clientiVect->push_back(new Cliente(clientiVect->size(),nome,prezzo,extra));
    //bisognerebbe farlo aggiungere alla combo
    //salvo ogni volta il tutto
    return save();
}
bool ClientiController::loadClienti()const{
    QString FileName="saveClienti.txt";
    QFile file(FileName);

    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return false;

    QTextStream in(&file);
    QString nome=in.readLine();
    while(!nome.isNull()){
        clientiVect->push_back(new Cliente(clientiVect->size(),nome.toStdString(),in.readLine().toFloat(),in.readLine().toFloat()));
        nome=in.readLine();
    }
    file.close();
    return true;//usato alla creazione del controller-potrebbe essere messo privato
}
bool ClientiController::save()const{
    QString FileName="saveClienti.txt";
    QFile file(FileName);
     if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
         return false;

    QTextStream out(&file);

    for(int i=0;i<clientiVect->size();++i){
        clientiVect->at(i)->Save(out);
    }

    file.close();
    return true;//usato alla distruzione del controller- potrebbe essere messo privato
}
ClientiController::~ClientiController(){
    //faccio un for che elimina tutti gli elementi di clienti vect
    for(int i=0;i<clientiVect->size();++i)
        delete clientiVect->at(i);
    //elimino il Qvector
    delete clientiVect;
}
bool ClientiController::refreshListaClienti()const{
    if(view!=0){
        view->svuotaItemLista();
        for(int i=0;i<clientiVect->size();++i)
            view->addItemLista(QString::fromStdString(clientiVect->at(i)->getNome()),i);
        return true;
    }
    return false;
}
void ClientiController::removeCliente(int pos)const{
    clientiVect->remove(pos);//automaticamente ricompatta il vettore
    refreshListaClienti();
    settaListaClienti();//nella main view
    save();
}

#include "vectorday.h"
#include <QFile>
#include "appuntamento.h"
#include "tempodedicato.h"
#include <QDebug>
#include "controller/myexception.h"

VectorDay::VectorDay():Capacity(366),Size(0),StartFrom(QDate(2015,9,1)),vett(new Lista[366]){}//da aggiungere il giorno di partenza

//Metodi pubblici
int VectorDay::capacity()const{return Capacity;}

int VectorDay::size()const{return Size;}

void VectorDay::add(Impegno* a){

    if(exist(a))//controllo se già esiste
        throw MyException("Esiste già un impegno in questa fascia oraria");//lancio l'eccezzione di esiste già!

     int pos=TrovaPos(*a);

    while(pos>= Capacity)
        allarga();

    vett[pos].add(a);

    if(Size<=pos)
        Size=pos+1;

}//aggiunge un elmento alla fine

void VectorDay::addAndSave(Impegno* a,QTextStream& out){
    add(a);
    a->Save(out);
}

void VectorDay::remove(const Impegno& a){
    vett[TrovaPos(a)].remove(a);//la Size rimane uguale perche' a fini statistici, se quel giorno e' gia stato usato  potrei riusarlo a breve
    //inoltre potrebbero esserci altri impegni in quel giorno
}//rimuove un elemento

//metodi privati
void VectorDay::allarga(){//il costruttore di copia, copia solo campo per campo i puntatori, e poi tutti gli oggetti lista vengono eliminati, no consivisione di memoria degli oggetti della lista
    Lista *nuovoVett=new Lista[Capacity*2];
    for(int i=0;i<Capacity;i++){
        nuovoVett[i]=vett[i];
    }
    Capacity=Capacity*2;
    delete vett;
    vett=nuovoVett;
}

int VectorDay::TrovaPos(const Impegno& a)const{
    return StartFrom.daysTo(a.getStart());
}


float VectorDay::getMoney(QDateTime da,const  QDateTime a,const Cliente & cliente) const{
    int pos=StartFrom.daysTo(da);
    float result=0;
    while(da<=a){
        if(pos>=Size)
            break;
        result=result+vett[pos].getMoney(cliente);
        da=da.addDays(1);
        pos++;
    }
    return result;
}

Lista& VectorDay::getImpegnoDay(const QDate& day)const{
    int pos=StartFrom.date().daysTo(day);
    if (pos>=Size){
        throw MyException("eccezzione");//eccezione devo dirgli di non fare nulla
    }
    else
        return vett[pos];//possibile errore
}

bool VectorDay::exist(Impegno* imp) const{
    int pos=TrovaPos(*imp);

    if(pos>=Size)
        return false;

    Lista::Iteratore it,en;
    it=vett[pos].begin();
    en=vett[pos].end();

    while(it!=en){
        if(vett[pos][it]->getStart() >= imp->getStart() && vett[pos][it]->getStart() <= imp->getEnd())
            return true;
        it++;
    }
    return false;
}

void VectorDay::remove(int pos,const QDate& data){
    vett[StartFrom.date().daysTo(data)].remove(pos);
}

void VectorDay::resave(QTextStream& out)const{
    Lista::Iteratore it,en;

    for(int pos=0;pos<Size;pos++)//al posto di capacity Size, ma devo capire come fare a tenere la Size con  l'ultimo elemento
    {
        it=vett[pos].begin();
        en=vett[pos].end();

        while(it!=en){
            vett[pos][it]->Save(out);
            it++;
        }
    }
}

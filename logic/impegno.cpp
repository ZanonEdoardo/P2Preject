#include "impegno.h"

Impegno::Impegno():Start(),End(),Description("-"),Riferimenti(0){
}

Impegno::Impegno(const QDateTime& Startp, const QDateTime & Endp,const string& Descriptionp ,const Professionista& pro):Start(Startp),End(Endp),Description(Descriptionp),Prof(pro),Riferimenti(0){}
Impegno::Impegno(const QDateTime& Startp, const QDateTime & Endp,const string& Descriptionp):Start(Startp),End(Endp),Description(Descriptionp),Riferimenti(0){}

Impegno::Impegno(const Impegno& a):Start(a.Start),End(a.End),Description(a.Description),Prof(a.Prof),Riferimenti(0){}

//method
int Impegno::getDurata() const{//return number of hour
    return (Start.secsTo(End)/60)/60;
}
string Impegno::getDescription() const { //return description
    return Description;
}
Impegno::~Impegno(){}
bool Impegno::EqualTo(const Impegno& a ){
    return (Start==a.Start && End==a.End);
}

QDateTime Impegno::getStart()const{ return Start;}//ritorno una copia perchè non voglio possa essere modificata(potrei passarlo come riferimento costante)
QDateTime Impegno::getEnd()const{return End;}
void Impegno::Modify(const QDateTime& Startp, const QDateTime & Endp,const string& Descriptionp){
    Start=Startp;
    End=Endp;
    Description=Descriptionp;
}//da terminare
void Impegno::Modify(const QDateTime& Startp, const QDateTime & Endp){
    Start=Startp;
    End=Endp;
}//da terminare


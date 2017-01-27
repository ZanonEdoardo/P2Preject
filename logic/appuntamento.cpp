#include "appuntamento.h"


Appuntamento::Appuntamento(){}

Appuntamento::Appuntamento(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c,const Professionista& pro):ImpegnoLavorativo(Startp,Endp,secr, c,pro){}
Appuntamento::Appuntamento(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c):ImpegnoLavorativo(Startp,Endp,secr, c){}

Appuntamento::Appuntamento(const Appuntamento& a):ImpegnoLavorativo(a.Start,a.End,a.Description,a.client,a.Prof){}

void Appuntamento::Save(QTextStream& out)const{
    const QString sformat="yyyy-MM-dd hh:mm:ss";
    out<<0<<endl<<Start.toString(sformat)<<endl<<End.toString(sformat)<<endl<<QString::fromStdString(Description)<<endl<<client.getID()<<endl;
}

float Appuntamento::getMoney()const {
    return getDurata()*(client.getTassazzione()+client.getExtra());
}
Appuntamento::~Appuntamento(){}

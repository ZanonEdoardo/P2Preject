#include "tempodedicato.h"

TempoDedicato::TempoDedicato(){}

TempoDedicato::TempoDedicato(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c,const Professionista& pro):ImpegnoLavorativo(Startp,Endp,secr, c,pro){}
TempoDedicato::TempoDedicato(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c):ImpegnoLavorativo(Startp,Endp,secr, c){}


TempoDedicato::TempoDedicato(const TempoDedicato& a):ImpegnoLavorativo(a.Start,a.End,a.Description,a.client,a.Prof){}
TempoDedicato::~TempoDedicato(){}
void TempoDedicato::Save(QTextStream& out)const{
    const QString sformat="yyyy-MM-dd hh:mm:ss";
        out<<1<<endl<<Start.toString(sformat)<<endl<<End.toString(sformat)<<endl<<QString::fromStdString(Description)<<endl<<client.getID()<<endl;
}

float TempoDedicato::getMoney() const {
    return getDurata()*client.getTassazzione();
}


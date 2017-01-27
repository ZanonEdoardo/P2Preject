#include "impegnolavorativo.h"

ImpegnoLavorativo::ImpegnoLavorativo(){}

ImpegnoLavorativo::ImpegnoLavorativo(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c,const Professionista& prof):Impegno(Startp,Endp,secr,prof),client(c){}
ImpegnoLavorativo::ImpegnoLavorativo(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c):Impegno(Startp,Endp,secr),client(c){}

ImpegnoLavorativo::ImpegnoLavorativo(const ImpegnoLavorativo& a):Impegno(a.Start,a.End,a.Description,a.Prof) ,client(a.client){}


std::string ImpegnoLavorativo::getNomeCliente()const{
    return client.getNome();
}

 void ImpegnoLavorativo::DeleteFrom()const{}

ImpegnoLavorativo::~ImpegnoLavorativo(){}

bool ImpegnoLavorativo::ClienteMatch(const Cliente& a)const {
    return a==client;
}

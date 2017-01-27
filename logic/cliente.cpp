#include "cliente.h"

//vorrei poter evitare di metterlo, perchè vorrei che cliente non venga mai costruito così
Cliente::Cliente():Tassazzione(0){}

Cliente::Cliente(const Cliente& a):Persona(a.ID,a.Nome),Tassazzione(a.Tassazzione),ExtraAppuntamenti(a.ExtraAppuntamenti){}

Cliente::Cliente(int IDp,const std::string& Nomep,float Tassazzionep,float ExtraAppuntamentip):Persona(IDp,Nomep),Tassazzione(Tassazzionep),ExtraAppuntamenti(ExtraAppuntamentip){
    //qui denytro dovrei controllollare che i tre campi diano diversi da quelli default
}
Cliente::Cliente(const std::string& Nomep,float Tassazzionep,float ExtraAppuntamentip):Persona(Nomep),Tassazzione(Tassazzionep),ExtraAppuntamenti(ExtraAppuntamentip){
    //costruttore per i nuovi, che non hanno un id di salvataggio assegnato
}

float Cliente::getTassazzione() const {return Tassazzione;}
float Cliente::getExtra() const {return ExtraAppuntamenti;}

void Cliente::Save(QTextStream& out)const{
    out<<QString::fromStdString(Nome)<<endl<<Tassazzione<<endl<<ExtraAppuntamenti<<endl;
}
bool Cliente::operator==(const Cliente& a)const{
    return Nome==a.Nome && ID==a.ID && Tassazzione==a.Tassazzione;
}
Cliente::~Cliente(){}

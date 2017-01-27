#include "personale.h"

Personale::Personale(){}

Personale::Personale(const Personale& a):Impegno(a.Start,a.End,a.Description,a.Prof){}

Personale::Personale(const QDateTime& a,const QDateTime& b,const string& c,const Professionista& d):Impegno(a,b,c,d){}
Personale::Personale(const QDateTime& a,const QDateTime& b,const string& c):Impegno(a,b,c){}

void Personale::Save(QTextStream& out) const {
    const QString sformat="yyyy-MM-dd hh:mm:ss";
        out<<2<<endl<<Start.toString(sformat)<<endl<<End.toString(sformat)<<endl<<QString::fromStdString(Description)<<endl;
}

void Personale::DeleteFrom()const{}

Personale::~Personale(){}

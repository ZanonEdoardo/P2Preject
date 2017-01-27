#ifndef APPUNTAMENTO_H
#define APPUNTAMENTO_H

#include "impegnolavorativo.h"
#include <QTextStream>
class Appuntamento:public ImpegnoLavorativo{
    public:
        Appuntamento();
        Appuntamento(const Appuntamento&);
        Appuntamento(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c,const Professionista&);
        Appuntamento(const QDateTime& Startp,const QDateTime& Endp,const string& secr,const Cliente& c);
        virtual ~Appuntamento();

        void Save(QTextStream&)const;

        float getMoney()const ;
};

#endif // APPUNTAMENTO_H

#ifndef TEMPODEDICATO_H
#define TEMPODEDICATO_H

#include "impegnolavorativo.h"

class TempoDedicato: public ImpegnoLavorativo{
    public:
        TempoDedicato();
        TempoDedicato(const QDateTime&,const QDateTime&,const string&,const Cliente&,const Professionista&);
        TempoDedicato(const QDateTime&,const QDateTime&,const string&,const Cliente&);

        TempoDedicato(const TempoDedicato&);
        virtual ~TempoDedicato();
        void Save(QTextStream&)const;
        float getMoney() const ;
};

#endif // TEMPODEDICATO_H

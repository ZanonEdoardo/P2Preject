#ifndef PERSONALE_H
#define PERSONALE_H

#include "impegno.h"

class Personale: public Impegno{

    public:
        Personale();
        Personale(const Personale&);
        Personale(const QDateTime&,const QDateTime&,const string&,const Professionista&);
        Personale(const QDateTime&,const QDateTime&,const string&);

        void Save(QTextStream&) const ;
        void DeleteFrom() const;
        virtual ~Personale();
};

#endif // PERSONALE_H

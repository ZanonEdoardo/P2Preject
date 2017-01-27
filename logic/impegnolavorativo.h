#ifndef IMPEGNOLAVORATIVO_H
#define IMPEGNOLAVORATIVO_H

#include "impegno.h"
#include "cliente.h"
#include "professionista.h"

class ImpegnoLavorativo: public Impegno{
    protected:
        Cliente client;
    public:

        virtual void Save(QTextStream& )const=0;
        void DeleteFrom()const;
        virtual float getMoney() const=0;
        std::string getNomeCliente()const;
        bool ClienteMatch(const Cliente&)const ;
        virtual ~ImpegnoLavorativo();

        ImpegnoLavorativo();
        ImpegnoLavorativo(const QDateTime&,const QDateTime&,const string&,const Cliente&, const Professionista&);
        ImpegnoLavorativo(const QDateTime&,const QDateTime&,const string&,const Cliente&);

        ImpegnoLavorativo(const ImpegnoLavorativo&);

};

#endif // IMPEGNOLAVORATIVO_H

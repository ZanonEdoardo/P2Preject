#ifndef IMPEGNO_H
#define IMPEGNO_H


#include <QDateTime>
#include <string>
#include "professionista.h"
#include <QTextStream>

using std::string;

class Impegno{
    protected:
        QDateTime Start;
        QDateTime End;
        string Description;
        Professionista Prof;


    public:
        int Riferimenti;//per il momento pubblico, poi vedrò come fare (non dovrebbe piu servire)
        //costructor
        Impegno();
        Impegno(const QDateTime& Startp, const QDateTime & Endp,const string& Descriptionp);//temporaneo
        Impegno(const QDateTime& Startp, const QDateTime & Endp,const string& Descriptionp ,const Professionista& pro );
        Impegno(const Impegno&);

        //method
        int getDurata() const; //return number of hour
        QDateTime getStart()const;
        QDateTime getEnd()const;
        void Modify(const QDateTime& Startp, const QDateTime & Endp,const string& Descriptionp);
        void Modify(const QDateTime& Startp, const QDateTime & Endp);
        bool EqualTo(const Impegno& a );//non posso riscrivere l'operatore == perchè classe astratta, inoltre non controllo l'uguaglianza perfetta, ma solo la compatibilità per motivi di comodità
        //lo implemento quì percè mi bastano data, ora e professionista
        string getDescription() const ; //return description
        virtual void Save(QTextStream&) const =0;// virtual method pure
        virtual void DeleteFrom() const=0;
        virtual ~Impegno();
};

#endif // IMPEGNO_H

#ifndef VECTORDAY_H
#define VECTORDAY_H

#include "lista.h"
#include "controller/clienticontroller.h"

class VectorDay
{
    private:
        int Capacity;
        int Size;
        QDateTime StartFrom;
        Lista *vett;

        //metodi privati
        void allarga();
        int TrovaPos(const Impegno&)const;


        //save verrà fatto dai singoli oggetti in maniera polimorfa

    public:
        VectorDay();

        //metodi
        int capacity()const;//ritorna il numero di spazi totali
        int size()const;//ritorna il numero di elementi attuali

        void add(Impegno*);
        void remove(const Impegno&);//rimuove un elemento
        float getMoney( QDateTime,const  QDateTime,const Cliente&) const;
        Lista& getImpegnoDay(const QDate&)const;//ritorna gli impegni di quel giorno
        bool exist(Impegno*) const;//ritorna true se esiste gia un'impegno che si sofvappone, false altrimenti

        void remove(int,const QDate& );//rimuove l'elemento richiesto in quella determinata posizione
        void resave(QTextStream&)const;
        void addAndSave(Impegno* ,QTextStream&);
};

#endif // VECTORDAY_H

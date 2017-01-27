#ifndef LISTA_H
#define LISTA_H

#include "impegno.h"
#include "personale.h"
#include "cliente.h"

class Lista
{
    friend class Iteratore;
    private:
        class Nodo;
        class smartp {
            public:
                Nodo* Puntatore;
                smartp(Nodo* p = 0); //costruttore 0 1 e convers //s0
                smartp (const smartp&); // costruttore di copia //s1
                ~smartp(); //distruttore//s2
                smartp& operator= (const smartp&); //s3
                Nodo& operator* () const; //s4
                Nodo* operator->() const; //s5
                bool operator==(const smartp&) const; //s6
                bool operator!=(const smartp&) const; //s7
        };
        class Nodo{
            public:
                smartp next;
                Impegno* info;
                int riferimenti;

                Nodo();
                Nodo(Impegno*,smartp);
                ~Nodo();//distruttore
        };
        smartp first;

        //metodi privati
        void DeleteFromNode(smartp);//delete ricorsiva dei nodi della lista

    public:
        class Iteratore{
            friend class Lista;
            private:
                smartp punt;
            public:
                Iteratore& operator=(const Iteratore& i_ric);
                bool operator==( Iteratore i_ric) const;// 6
                bool operator!=( Iteratore i_ric) const;// 7
                Iteratore& operator++();
                Iteratore  operator++(int);
        };

        //metodi di lista che usano iteratore
        Iteratore begin() const ;
        Iteratore end() const ;
        Impegno* operator[](Iteratore i) const;

        //costruttori di lista
        Lista();
        ~Lista();

        //Metodi generali
        float getMoney(const Cliente&) const;//ritorna per quel cliente i soldi
        void addList(const Lista&);//con condivisione di memoria
        void add(Impegno*);
        void remove(const Impegno&);
        bool remove(int);//ritorna true <=> ha eliminato l'elemento in posizione pos

        //save(); c'è se non aggiorno ogni volta, ma solo alla chiusura

};

#endif // LISTA_H

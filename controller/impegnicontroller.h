#ifndef IMPEGNICONTROLLER_H
#define IMPEGNICONTROLLER_H

#include "logic/impegno.h"
#include "logic/vectorday.h" //dentro a vector è inclusa anche lista
#include "graphic/mainwindow.h"
#include <QDateTime>

class MainWindow;
class ImpegniController
{
    private:
        MainWindow *view;
        VectorDay *struttura;
        void load(ClientiController*)const;

    public:
        ImpegniController(MainWindow*,ClientiController*,VectorDay* );
        void AggiungiImpegno(int ,QDateTime,QDateTime,std::string,const Cliente* =0);//aggiunge un impegno alla struttura dati
        float Conto(const QDateTime&,const QDateTime&, Cliente*);
        void rimuoviImpegno(int pos,const QDate a)const;
        void AggiornaItemLista(const QDate&);//aggiorna gli item nella lista degli impegni giornalieri
        ~ImpegniController();
};


#endif // IMPEGNICONTROLLER_H

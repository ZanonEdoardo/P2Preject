#ifndef GESTIONECLIENTE_H
#define GESTIONECLIENTE_H

#include <QWidget>
#include <QPushButton>
#include<QListWidget>
#include<QListWidgetItem>
#include<QTextEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include "mydatetimeedit.h"

#include "moneyedit.h"

class ImpegniController;
class ClientiController;
class GestioneCliente:public QWidget
{
    Q_OBJECT
    private slots:
        void aggiungiCliente()const;
        void rimuoviCliente()const;
        void calcConto()const;

    private:
        ImpegniController* impegni;
        ClientiController* clientController;

        //widget
        QPushButton* addCliente;
        QPushButton* removeCliente;
        QListWidget* listaClienti;
        QTextEdit*  Nome;
        MoneyEdit* Money;
        MoneyEdit* Extra;
        QLabel* Conto;
        MyDateTimeEdit* Da;
        MyDateTimeEdit* A;
        QPushButton* CalcolaConto;
        QLabel* l_Nome;
        QLabel* l_Money;
        QLabel* l_extra;

        //layout
        QVBoxLayout* layoutdx;
        QHBoxLayout* layoutoriz;
        //function
        void prepareLayout();

    public:
        GestioneCliente(ClientiController* =0,ImpegniController* =0);
        void addItemLista(const QString&,int)const;
        void svuotaItemLista()const;
        ~GestioneCliente();
};

#endif // GESTIONECLIENTE_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTextEdit>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>
#include "mydatetimeedit.h"
#include "typecombobox.h"
#include "mydelegate.h"
#include "gestionecliente.h"
#include "logic/vectorday.h"
#include <QErrorMessage>

class ImpegniController;//dichiarazioni incomplete (incluse nel file cpp)
class ClientiController;
class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        void addItemToList(QString,QString,QString,QString);
        void settaClienteCombo(QString ,int)const;
        ~MainWindow();
        void clearClientiCombo()const;

    private slots:
        void aggiornaitem(const QDate& a);
        void openGestCli();
        void addImpegno();
        void eliminaImpegno();
        void aggiornaDate(const QDate& a);

    private:

        virtual void closeEvent(QCloseEvent*);
        //controller
        ImpegniController* controller;
        ClientiController* clientecontrol;

        //------------------------------
        QPushButton* gestisciCliente;
        QCalendarWidget* calendar;
        QListWidget* listaImpegni;

        //Item per l'inserimento degli impegni
        QPushButton* aggiungiImpegno;
        QPushButton* cancellaImpegno;
        MyDateTimeEdit* startImpegno;
        MyDateTimeEdit* endImpegno;
        QTextEdit* descr;
        TypeComboBox* type;
        QComboBox* cliente;//assegno il nome del cliente ed il puntatore contenuto nella struttura dati

        //label
        QLabel* l_startImpegno;
        QLabel* l_endImpegno;
        QLabel* l_descr;
        QLabel* l_cliente;
        QLabel* l_type;


        //layout
        QVBoxLayout* dx;
        QVBoxLayout* sx;
        QHBoxLayout* layoutinsimp;
        QHBoxLayout* layoutImpegni;
        QVBoxLayout* layout;

        //sub-view
        GestioneCliente* gest;
        QErrorMessage* err;

        //function
        void prepareLayout();
};

#endif // MAINWINDOW_H

#ifndef CLIENTICONTROLLER_H
#define CLIENTICONTROLLER_H

#include <QVector>
#include "logic/cliente.h"

class GestioneCliente;
class MainWindow;
class ClientiController
{
    //a main window non serve accedere dato che non tocco le sue proprieta' in teoria
    private:
        QVector<Cliente*>* clientiVect;
        GestioneCliente *view;
        MainWindow* mainview;

    public:
        ClientiController( MainWindow*);

        void addViewClienti(GestioneCliente*);
        void settaListaClienti()const;
        void removeCliente(int)const;//da fare
        bool addCliente(std::string,float,float)const;
        Cliente* getCliente(int) const ;
        bool loadClienti()const;
        bool refreshListaClienti()const;
        bool save()const;
        ~ClientiController();
};

#endif // CLIENTICONTROLLER_H

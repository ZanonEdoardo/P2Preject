#ifndef QLISTCLIENTEITEM_H
#define QLISTCLIENTEITEM_H
#include <QListWidgetItem>

class QListClienteItem: public QListWidgetItem
{
    private:
        int value;

    public:
        QListClienteItem(const QString&,int,QListWidget*);
        int getValue()const;//torna la posizione del cliente(il valore intero che ho aggiunto)

    /*questo oggetto serve a contenere anche la posizione del Qvector dell'item così mi è piu semplice fare operazioni su quel cliente*/
};

#endif // QLISTCLIENTEITEM_H

#include "qlistclienteitem.h"

QListClienteItem::QListClienteItem(const QString& text,int valore,QListWidget *parent):QListWidgetItem(text,parent),value(valore){}

int QListClienteItem::getValue()const {return value;}

#include "graphic/mainwindow.h"
#include <QApplication>
#include "logic/vectorday.h"
#include <QVector>
#include "controller/impegnicontroller.h"
#include "controller/clienticontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //dichiarazione view sempre aperta
    MainWindow* w=new MainWindow;
    w->show();

    return a.exec();
}

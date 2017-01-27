#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <QString>

class MyException
{
    private:
        QString Testo;
    public:
        MyException(const QString& text);
        QString getText() const;
};

#endif // MYEXCEPTION_H

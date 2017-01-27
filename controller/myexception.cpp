#include "myexception.h"


MyException::MyException(const QString& text):Testo(text){}

QString MyException::getText() const{
    return Testo;
}


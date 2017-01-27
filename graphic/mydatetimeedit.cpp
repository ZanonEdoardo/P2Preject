#include "mydatetimeedit.h"

MyDateTimeEdit::MyDateTimeEdit(QWidget* parent):QDateTimeEdit(QDateTime::currentDateTime(),parent){
    setMinimumHeight(22);
    setStyleSheet(
                            "border-width: 2px;"
                            "border-radius: 6px;"
                           );
}


#include "typecombobox.h"

TypeComboBox::TypeComboBox(QWidget* parent):QComboBox(parent){
    addItem("Personale",0);
    addItem("Appuntamento",1);
    addItem("Tempo Dedicato",2);

    setStyleSheet( "border: 1px solid gray;"
                            "border-radius: 3px;"
                            "padding: 3px 3px 3px 3px;");
}


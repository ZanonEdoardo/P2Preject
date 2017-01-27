#include "moneyedit.h"

MoneyEdit::MoneyEdit(QWidget* parent):QLineEdit(parent){
    setInputMask("000.00");
    setStyleSheet("border-width: 2px;"
                  "border-radius: 6px;");
    insert("000.00");
}

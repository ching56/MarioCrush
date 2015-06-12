#include "stone1.h"
#include <QString>

stone1::stone1(QWidget *parent, int type, int row, int col):stone(parent, row, col){button->setText(QString::number(type));}

void stone1::crush()
{
    delete this;
    emit superCrush(0,0,0);
}


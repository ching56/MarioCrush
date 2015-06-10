#include "stone1.h"
#include <QString>

stone1::stone1(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(QString::number(1));}

void stone1::crush()
{
    delete this;
}


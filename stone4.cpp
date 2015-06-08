#include "stone4.h"
#include <QString>

stone4::stone4(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(QString::number(4));}

void stone4::crush()
{

}


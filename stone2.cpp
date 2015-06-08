#include "stone2.h"
#include <QString>

stone2::stone2(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(QString::number(2));}

void stone2::crush()
{

}

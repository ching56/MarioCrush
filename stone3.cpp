#include "stone3.h"
#include <QString>

stone3::stone3(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(QString::number(3));}

void stone3::crush()
{

}

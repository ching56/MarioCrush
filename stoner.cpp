#include "stoner.h"

stoneR::stoneR(QWidget *parent,int type ,int row, int col):stone(parent, row, col){button->setText(QString::number(type));}

void stoneR::crush()
{
        delete this;
        emit superCrush(2,row,col);
}

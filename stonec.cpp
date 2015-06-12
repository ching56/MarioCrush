#include "stonec.h"


stoneC::stoneC(QWidget *parent,int type ,int row, int col):stone(parent, row, col){button->setText(QString::number(type));}

void stoneC::crush()
{
        delete this;
        emit superCrush(1,row,col);
}

#include "stoneb.h"

stoneB::stoneB(QWidget *parent,int type ,int row, int col):stone(parent, row, col){button->setText(QString::number(type));}

void stoneB::crush()
{
        delete this;
        emit superCrush(6,row,col);
}

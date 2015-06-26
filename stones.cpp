#include "stones.h"

stoneS::stoneS(QWidget *parent,int row, int col):stone(parent, row, col){button->setText(QString::number(5));}

void stoneS::crush()
{

            emit superCrush(5,row,col);
}

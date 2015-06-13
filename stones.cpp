#include "stones.h"

stoneS::stoneS(QWidget *parent,int row, int col):stone(parent, row, col){button->setText(0);}

void stoneS::crush()
{
            emit superCrush(5,row,col);
}

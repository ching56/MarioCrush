#include "stones.h"

stoneS::stoneS(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(S);}

void stoneS::crush()
{
        delete this;
        emit superCrush(5,row,col);
}

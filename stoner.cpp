#include "stoner.h"

stoneR::stoneR(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(R);}

void stoneR::crush()
{
        delete this;
        emit superCrush(2,row,col);
}

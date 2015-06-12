#include "stonec.h"


stoneC::stoneC(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(C);}

void stoneC::crush()
{
        delete this;
        emit superCrush(1,row,col);
}

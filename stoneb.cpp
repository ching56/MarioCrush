#include "stoneb.h"

stoneB::stoneB(QWidget *parent, int row, int col):stone(parent, row, col){button->setText(B);}

void stoneB::crush()
{
        delete this;
        emit superCrush(6,row,col);
}

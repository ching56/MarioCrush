#include "stonec.h"
#include <QDebug>

stoneC::stoneC(QWidget *parent,int type ,int row, int col):stone(parent, row, col){button->setText(QString::number(type));bg->setStyleSheet("background-color: rgb(102, 204, 255);");qDebug()<<row<<col;}

void stoneC::crush()
{   qDebug()<<"colCrush";
    emit superCrush(1,row,col);
}

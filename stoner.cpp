#include "stoner.h"
#include <QDebug>
stoneR::stoneR(QWidget *parent,int type ,int row, int col):stone(parent, row, col){button->setText(QString::number(type));bg->setStyleSheet("background-color: rgb(102, 204, 255);");}

void stoneR::crush()
{           qDebug()<<"rowCrush";
            emit superCrush(2,row,col);

}

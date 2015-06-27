#include "stoneb.h"
#include <QDebug>
stoneB::stoneB(QWidget *parent,int type ,int row, int col):stone(parent, row, col){button->setText(QString::number(type));bg->setStyleSheet("background-color: rgb(102, 204, 255);");}

void stoneB::crush()
{           qDebug()<<"bombCrsuh";
            emit superCrush(6,row,col);
}

stoneB::~stoneB()
{

}

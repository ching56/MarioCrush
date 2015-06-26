#include "stone1.h"
#include <QDebug>
#include "game.h"

stone1::stone1(QWidget *parent, int type, int row, int col):stone(parent, row, col){button->setText(QString::number(type));}

void stone1::crush()
{
    qDebug()<<"emit score";
    emit getPoint();
    delete this;
}


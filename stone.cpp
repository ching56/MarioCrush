#include "stone.h"
#include <QPushButton>
#include <QDebug>
#include <QString>

stone::stone(QWidget *parent, int row, int col): QObject(parent),isClicked(false),isMoved(false),isCrush(false)
{
    bg = new QLabel(parent);
    button = new QPushButton(parent);
    button->setGeometry(20+row*45,185+col*45,45,45);
    bg->setGeometry(20+row*45,185+col*45,45,45);
    bg->setStyleSheet("background-color: rgb(179, 179, 179);");
    bg->hide();
    button->setFlat(true);
    button->setStyleSheet("border:1px solid;background: transparent;");
    button->setIconSize(button->size());
    connect(button,SIGNAL(clicked()),this,SLOT(button_clicked()));
}

stone::~stone()
{
    delete bg;
    delete button;
}

void stone::stMove(int row, int col)
{
    button->setGeometry(20+row*45,185+col*45,45,45);
    bg->setGeometry(20+row*45,185+col*45,45,45);
    isMoved = true;
}

void stone::button_clicked()
{
    isClicked = isClicked?false:true;
    emit click();

}


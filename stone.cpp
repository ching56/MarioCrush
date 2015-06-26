#include "stone.h"
#include <QToolButton>
#include <QDebug>
#include <QString>

stone::stone(QWidget *parent, int row, int col): QObject(parent),isClicked(false),isMoved(false),isCrush(false),row(row),col(col)
{
    bg = new QLabel(parent);
    button = new QToolButton(parent);
    button->setGeometry(20+row*45,185+col*45,45,45);
    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    bg->setGeometry(20+row*45,185+col*45,45,45);
    bg->setStyleSheet("background-color: rgb(179, 179, 179);");
    bg->hide();
    button->setStyleSheet("border:0px solid;background: transparent;");
    button->setIconSize(button->size());
    connect(button,SIGNAL(clicked()),this,SLOT(button_clicked()));
}

stone::~stone()
{
    delete bg;
    delete button;
}

void stone::stMove(int r, int c)
{
    button->setGeometry(20+r*45,185+c*45,45,45);
    bg->setGeometry(20+r*45,185+c*45,45,45);
    isMoved = true;
    row = r;
    col = c;
}

void stone::button_clicked()
{
    isClicked = isClicked?false:true;
    emit click();

}


#include "startscreen.h"
#include "ui_startscreen.h"

startscreen::startscreen(QMainWindow *parent) :
    QMainWindow(parent),ui(new Ui::startscreen)
{
    ui->setupUi(this);
    gamewindow = NULL;
    resultwindow = new result(this);
}

startscreen::~startscreen()
{
    emit(gamewindow->star,gamewindow->score);
    delete ui;
}


void startscreen::on_botton_start_clicked()
{
    gamewindow = new game(this,resultwindow);
    this->setCentralWidget(gamewindow);
    connect(resultwindow,SIGNAL(reset()),this,SLOT(resetgame()));
}

void startscreen::resetgame()
{
    resultwindow->hide();
    if(gamewindow != NULL)
        delete gamewindow;
    gamewindow = new game( this,resultwindow);
    this->setCentralWidget(gamewindow);

}


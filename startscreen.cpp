#include "startscreen.h"
#include "ui_startscreen.h"

startscreen::startscreen(QMainWindow *parent) :
    QMainWindow(parent),ui(new Ui::startscreen)
{
    ui->setupUi(this);
    gamewindow = NULL;
    resultwindow = new result(this);
    connect(resultwindow,SIGNAL(quit(int,int)),this,SLOT(reemit(int,int)));
}

startscreen::~startscreen()
{
    delete ui;
}

void startscreen::reemit(int star, int score)
{
    emit quit(star,score);
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


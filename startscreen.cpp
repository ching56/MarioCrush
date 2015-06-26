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
    delete ui;
}


void startscreen::on_botton_start_clicked()
{
    gamewindow = new game(this,resultwindow);
    this->setCentralWidget(gamewindow);
}


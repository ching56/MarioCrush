#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent,result *res) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
}

game::~game()
{
    delete ui;
}

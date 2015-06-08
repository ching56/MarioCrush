#include "game.h"
#include "ui_game.h"
#include <cstdlib>
#include <QDebug>

game::game(QWidget *parent,result *res) :
    QWidget(parent),
    ui(new Ui::game),
    score(0),star(0),move(0)
{
    srandom(time(NULL));

    ui->setupUi(this);
    for(int i=0;i<11;i++)
        for(int j=0;j<8;j++){
            int rand=random()%4;
            if(rand==0)
            st[j][i]=new stone1(this,j,i);
            if(rand==1)
            st[j][i]=new stone2(this,j,i);
            if(rand==2)
            st[j][i]=new stone3(this,j,i);
            if(rand==3)
            st[j][i]=new stone4(this,j,i);
            connect(st[j][i],SIGNAL(click()),this,SLOT(stone_clicked()));
        }

}

game::~game()
{
    delete ui;
}

void game::stone_clicked()
{

}

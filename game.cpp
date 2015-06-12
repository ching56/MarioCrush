#include "game.h"
#include "ui_game.h"
#include <cstdlib>
#include <QDebug>
#include <string>

game::game(QWidget *parent,result *res) :
    QWidget(parent),
    ui(new Ui::game),
    score(0),star(0),move(0)
{
    srandom(time(NULL));
    ui->setupUi(this);
    bool redo=false;

    for(int i=0;i<11;i++)
        for(int j=0;j<8;j++){
            st[j][i] = randStone(j,i);
        }
    do{
        redo=false;
    for(int j=0;j<11;j++)
        for(int i=0;i<6;i++)
            if(st[i][j]->button->text()==st[i+1][j]->button->text() &&
               st[i][j]->button->text()==st[i+2][j]->button->text())
            {
                delete st[i][j];
                st[i][j]=NULL;
                st[i][j] = randStone(i,j);
                i--;
            }
    for(int j=0;j<9;j++)
        for(int i=0;i<8;i++)
            if(st[i][j]->button->text()==st[i][j+1]->button->text() &&
               st[i][j]->button->text()==st[i][j+2]->button->text())
            {
                delete st[i][j];
                st[i][j]=NULL;
                st[i][j] = randStone(i,j);
                i--;
            }
    for(int j=0;j<11;j++)
        for(int i=0;i<6;i++)
            if(st[i][j]->button->text()==st[i+1][j]->button->text() &&
               st[i][j]->button->text()==st[i+2][j]->button->text())
                redo=true;
    for(int j=0;j<8;j++)
        for(int i=0;i<8;i++)
            if(st[i][j]->button->text()==st[i][j+1]->button->text() &&
               st[i][j]->button->text()==st[i][j+2]->button->text())
                redo=true;
    }while(redo);

    for(int i=0;i<11;i++)
        for(int j=0;j<8;j++){
            connect(st[j][i],SIGNAL(click()),this,SLOT(stone_clicked()));
            connect(st[i][j],SIGNAL(superCrush(int type,int row,int col)),this,SLOT(superCrush(int index,int row,int col)));
        }
}

game::~game()
{
    delete ui;
}

bool game::checkCrush()
{
    bool anyCrush = false;
    std::string type[8][11];
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){
            type[i][j] = typeid(*st[i][j]).name();
            if(type[i][j] == typeid(stoneb).name())
                type[i][j] = typeid(st)
        }
    //check row in 3
    for(int j=0;j<11;j++)
        for(int i=0;i<6;i++){
            if( i==0 )
                    if( type[i][j] == type[i+1][j]
                    && type[i][j] == type[i+2][j]
                    && type[i][j] != type[i+3][j]){
                        for(int k=i;k<i+3;k++){
                            st[k][j]->isCrush=true;
                            st[k][j]->crushNum=3;
                            }
                        anyCrush = true;
                    }
            if( i==5 )
                    if(type[i][j] == type[i+1][j]
                    && type[i][j] == type[i+2][j]
                    && type[i][j] != type[i-1][j]){
                        for(int k=i;k<i+3;k++){
                            st[k][j]->isCrush=true;
                            st[k][j]->crushNum=3;
                            //if the crushNum != 0
                        }
                        anyCrush = true;
                    }
            if(i != 0 && i !=5)
            if(type[i][j] == type[i+1][j]
              && type[i][j] == type[i+2][j]
              && type[i][j] != type[i-1][j]
              && type[i][j] != type[i+3][j]){
                for(int k=i;k<i+3;k++){
                    st[k][j]->isCrush=true;
                    st[k][j]->crushNum=3;
                    //if the crushNum != 0
                }
                anyCrush = true;
            }
    }

    //check row in 4
    for(int j=0;j<11;j++)
        for(int i=0;i<5;i++){
            if(i==0)
                if( type[i][j] == type[i+1][j]
                    && type[i][j] == type[i+2][j]
                    && type[i][j] == type[i+3][j]
                    && type[i][j] != type[i+4][j]){
                    for(int k=i;k<i+4;k++){
                        st[k][j]->isCrush=true;
                        st[k][j]->crushNum=2;
                        //if the crushNum != 0
                    }
                    anyCrush = true;
                }

            if(i==4 )
                if (type[i][j] == type[i+1][j]
                    && type[i][j] == type[i+2][j]
                    && type[i][j] == type[i+3][j]
                    && type[i][j] != type[i-1][j]){
                    for(int k=i;k<i+4;k++){
                        st[k][j]->isCrush=true;
                        st[k][j]->crushNum=2;
                        //if the crushNum != 0
                    }
                    anyCrush = true;
                }
                if(i != 0 && i != 4)
                    if(type[i][j] == type[i+1][j]
                    && type[i][j] == type[i+2][j]
                    && type[i][j] == type[i+3][j]
                    && type[i][j] != type[i+4][j]
                    && type[i][j] != type[i-1][j]){
                for(int k=i;k<i+4;k++){
                    st[k][j]->isCrush=true;
                    st[k][j]->crushNum=2;
                    //if the crushNum != 0
                }
                anyCrush = true;
            }
    }

    //check row in 5
    for(int j=0;j<11;j++)
        for(int i=0;i<4;i++){
            if(i==0){
                if( type[i][j] == type[i+1][j]
                    && type[i][j] == type[i+2][j]
                    && type[i][j] == type[i+3][j]
                    && type[i][j] == type[i+4][j]){
                for(int k=i;k<i+5;k++){
                    st[k][j]->isCrush=true;
                    st[k][j]->crushNum=5;
                    //if the crushNum != 0
                }
                anyCrush = true;
                }
            }
    }

    //check col in 3
    for(int j=0;j<9;j++)
        for(int i=0;i<8;i++){
            if( j==0 )
                 if(type[i][j] == type[i][j+1]
                    && type[i][j] == type[i][j+2]
                    && type[i][j] != type[i][j+3]){
                    for(int k=j;k<j+3;k++){
                        if(st[i][k]->isCrush && (st[i][k]->crushNum == 3||st[i][k]->crushNum == 4)){
                        st[i][k]->crushNum=6;
                        }else{
                            st[i][k]->crushNum=3;
                        }
                        st[i][k]->isCrush=true;
                    }
                    anyCrush = true;
                 }
             if (j==8)
                 if (type[i][j] == type[i][j+1]
                    && type[i][j] == type[i][j+2]
                    && type[i][j] != type[i][j-1]){
                     for(int k=j;k<j+3;k++){
                         if(st[i][k]->isCrush && (st[i][k]->crushNum == 3||st[i][k]->crushNum == 4)){
                         st[i][k]->crushNum=6;
                         }else{
                             st[i][k]->crushNum=3;
                         }
                         st[i][k]->isCrush=true;
                     }
                     anyCrush = true;
                 }
            if(j != 0 && j != 8)
                    if(type[i][j] == type[i][j+1]
                    && type[i][j] == type[i][j+2]
                    && type[i][j] != type[i][j-1]
                    && type[i][j] != type[i][j+3]){
                for(int k=j;k<j+3;k++){
                    if(st[i][k]->isCrush && (st[i][k]->crushNum == 3||st[i][k]->crushNum == 4)){
                    st[i][k]->crushNum=6;
                    }else{
                        st[i][k]->crushNum=3;
                    }
                    st[i][k]->isCrush=true;
                }
                anyCrush = true;
            }
    }
    //check col in 4
    for(int j=0;j<8;j++)
        for(int i=0;i<8;i++){
            if(j==0)
                if ( type[i][j] == type[i][j+1]
                    && type[i][j] == type[i][j+2]
                    && type[i][j] == type[i][j+3]
                    && type[i][j] != type[i][j+4]){
                    for(int k=j;k<j+4;k++){
                        st[i][k]->isCrush=true;
                        st[i][k]->crushNum=1;
                        //if the crushNum != 0
                    }
                    anyCrush = true;
                }
            if(j==7)
                if (type[i][j] == type[i][j+1]
                    && type[i][j] == type[i][j+2]
                    && type[i][j] == type[i][j+3]
                    && type[i][j] != type[i][j-1]){
                    for(int k=j;k<j+4;k++){
                        st[i][k]->isCrush=true;
                        st[i][k]->crushNum=1;
                        //if the crushNum != 0
                    }
                    anyCrush = true;
                }
            if(j != 0 && j != 7)
                    if(type[i][j] == type[i][j+1]
                    && type[i][j] == type[i][j+2]
                    && type[i][j] == type[i][j+3]
                    && type[i][j] != type[i][j-1]
                    && type[i][j] != type[i][j+4]){
                for(int k=j;k<j+4;k++){
                    st[i][k]->isCrush=true;
                    st[i][k]->crushNum=1;
                    //if the crushNum != 0
                }
                anyCrush = true;
            }
    }
    //check col in 5
    for(int j=0;j<6;j++)
        for(int i=0;i<8;i++){
            if(j==0 && type[i][j] == type[i][j+1]
                    && type[i][j] == type[i][j+2]
                    && type[i][j] == type[i][j+3]
                    && type[i][j] == type[i][j+4]){
                    for(int k=j;k<j+5;k++){
                    st[i][k]->isCrush=true;
                    st[i][k]->crushNum=5;
                    //if the crushNum != 0
                }
                anyCrush = true;
            }
    }
    int makeList[8][11];
    //record
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){
            makeList[i][j]=0;
            if(st[i][j]->isCrush && st[i][j]->crushNum != 3 && st[i][j]->isMoved)
                makeList[i][j] = st[i][j]->crushNum;
        }
    //crush
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++)
            if(st[i][j]->isCrush){
                st[i][j]->crush();
                st[i][j] = NULL;
            }
    //make
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){
            if(makeList[i][j] != 0){
                    stone[i][j] = genSpecial(makeList[i][j],i,j);
            }
        }
    //reset isMove, isCrush?
    qDebug()<<"crush!";
    return anyCrush;
}

void game::refresh()
{   qDebug()<<"refresh";
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++)
            st[i][j]->isMoved = false;
    for(int j=10;j>-1;j--)
    for(int i=7;i>-1;i--){
        if(st[i][j]==NULL){
        for(int k=j;k>-1;k--){
            if(st[i][k]!=NULL && st[i][k+1]==NULL){
                qDebug()<<"should be..."<<i<<k;
                st[i][k+1] = st[i][k];
                st[i][k] = NULL;
                st[i][k+1]->stMove(i,k+1);
                k+=2;
            }
        }
        }
    }
}

void game::fillRandStone()
{
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++)
            if(st[i][j]==NULL){
                st[i][j] = randStone(i,j);
                qDebug()<<"FILL";
            }
    for(int i=0;i<11;i++)
        for(int j=0;j<8;j++){
            connect(st[j][i],SIGNAL(click()),this,SLOT(stone_clicked()));
            connect(st[i][j],SIGNAL(superCrush(int type,int row,int col)),this,SLOT(superCrush(int index,int row,int col)));
        }
}

stone *game::randStone(int row ,int col)
{
    int type = 0;
    stone* ptr;

    type = random()%4;
    switch(type){
        case 0:
        ptr = new stone1(this,row,col);
        break;
        case 1:
        ptr = new stone2(this,row,col);
        break;
        case 2:
        ptr = new stone3(this,row,col);
        break;
        case 3:
        ptr = new stone4(this,row,col);
        break;
    }
    qDebug()<<"stone gen!";
    ptr->button->show();
    return ptr;
}

stone *game::genSpecial(int type,int row, int col)
{
    stone* ptr;
    switch(type){
        case 1:
        ptr = new stoneC(this,row,col);
        break;
        case 2:
        ptr = new stoneR(this,row,col);
        break;
        case 5:
        ptr = new stoneS(this,row,col);
        break;
        case 6:
        ptr = new stoneB(this,row,col);
        break;
        default:
        qDebug()<<"error switch!";
    }
    qDebug()<<"Specialstone gen!";
    ptr->button->show();
    return ptr;
}

void game::stone_clicked()
{
    int rec_i[2]={0};
    int rec_j[2]={0};
    int boolCount = 0;
    for(int i=0;i<8;i++)
        for(int j=0;j<11;j++){
            if(st[i][j]->isClicked){
                 rec_i[boolCount]=i;
                 rec_j[boolCount]=j;
                 boolCount++;
          }
        }
    if(boolCount==1){
        for(int i=0;i<8;i++)
            for(int j=0;j<11;j++){
                if(st[i][j]->isClicked)st[i][j]->bg->show();
                if(!st[i][j]->isClicked)st[i][j]->bg->hide();
            }
        return;
    }else{

    bool isNearby = false;
    if(rec_i[1]-rec_i[0]==1 && rec_j[0]==rec_j[1])isNearby=true;
    if(rec_i[1]==rec_i[0] && rec_j[1]-rec_j[0]==1)isNearby=true;

    if(isNearby){
        stone *temp;

        //exchange , if no isCrush produce exchange again.

        temp = st[rec_i[0]][rec_j[0]];
        st[rec_i[0]][rec_j[0]] = st[rec_i[1]][rec_j[1]];
        st[rec_i[1]][rec_j[1]] = temp;
        st[rec_i[0]][rec_j[0]]->stMove(rec_i[0],rec_j[0]);
        st[rec_i[1]][rec_j[1]]->stMove(rec_i[1],rec_j[1]);

        if(checkCrush()/*exchange and crush*/){
        //(move)
            refresh();
            fillRandStone();
            while(checkCrush()){
                refresh();
                fillRandStone();
            }
        //make stone in proper position
        //(move)
        //load downward and fill the blank with new stone
        //(move)
        //loop the crush and make process until no crushable stone
        }else{
            temp = st[rec_i[0]][rec_j[0]];
            st[rec_i[0]][rec_j[0]] = st[rec_i[1]][rec_j[1]];
            st[rec_i[1]][rec_j[1]] = temp;
            st[rec_i[0]][rec_j[0]]->stMove(rec_i[0],rec_j[0]);
            st[rec_i[1]][rec_j[1]]->stMove(rec_i[1],rec_j[1]);
            st[rec_i[0]][rec_j[0]]->isMoved = false;
            st[rec_i[1]][rec_j[1]]->isMoved = false;
        }

    }

   for(int i = 0;i<2;i++)
        st[rec_i[i]][rec_j[i]]->isClicked=false;

    }
    for(int i=0;i<8;i++)
        for(int j=0;j<11;j++){
            if(st[i][j]->isClicked)st[i][j]->bg->show();
            if(!st[i][j]->isClicked)st[i][j]->bg->hide();
        }
}

void game::superCrush(int index, int row, int col)
{

}

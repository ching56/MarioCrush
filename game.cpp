#include "game.h"
#include "ui_game.h"
#include <cstdlib>
#include <QDebug>
#include <string>

game::game(QWidget *parent,result *res) :
    QWidget(parent),
    ui(new Ui::game),
    score(0),star(0),move(0),starCrushType(0)
{
    srandom(time(NULL));
    ui->setupUi(this);
    bool redo=false;
    st1[0].addPixmap(QPixmap(":/boo.png"));
    st1[1].addPixmap(QPixmap(":/flower.png"));
    st1[2].addPixmap(QPixmap(":/turtle.png"));
    st1[3].addPixmap(QPixmap(":/mushroom.png"));

    stc[0].addPixmap(QPixmap(":/colboommushroom.png"));
    stc[1].addPixmap(QPixmap(":/colflowermushroom.png"));
    stc[2].addPixmap(QPixmap(":/colturtlemushroom.png"));
    stc[3].addPixmap(QPixmap(":/colmushroommushroom.png"));

    str[0].addPixmap(QPixmap(":/rowboomushroom.png"));
    str[1].addPixmap(QPixmap(":/rowflowermushroom.png"));
    str[2].addPixmap(QPixmap(":/rowturtlemushroom.png"));
    str[3].addPixmap(QPixmap(":/rowmushroommushroom.png"));

    stb[0].addPixmap(QPixmap(":/boobomb.png"));
    stb[1].addPixmap(QPixmap(":/flowerbomb.png"));
    stb[2].addPixmap(QPixmap(":/turtlebomb.png"));
    stb[3].addPixmap(QPixmap(":/mushroombomb.png"));

    sts.addPixmap(QPixmap(":/star.png"));

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
    //for debug

    delete st[0][0];
    delete st[1][0];
    delete st[2][1];
    delete st[2][2];
    delete st[3][0];

    st[0][0] = new stone1(this,1,0,0);
    st[1][0] = new stone1(this,1,1,0);
    st[2][1] = new stone1(this,1,2,1);
    st[2][2] = new stone1(this,1,2,2);
    st[3][0] = new stone1(this,1,3,0);


    //for debug end
    for(int i=0;i<11;i++)
        for(int j=0;j<8;j++){
            connect(st[j][i],SIGNAL(click()),this,SLOT(stone_clicked()));
            connect(st[j][i],SIGNAL(superCrush(int ,int ,int )),this,SLOT(superCrush(int ,int ,int )));
            for(int k=1;k<5;k++){
                if(st[j][i]->button->text() == QString::number(k))
                    st[j][i]->button->setIcon(st1[k-1]);
            }
        }
    qDebug()<<"->constructor";
}

game::~game()
{
    delete ui;
}

bool game::checkCrush()
{
    bool anyCrush = false;
    QString type[8][11];
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){
            type[i][j] = st[i][j]->button->text();
        }
    qDebug()<<"->checkCrush.checkRow in 3";
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
    qDebug()<<"->checkCrush.checkRow in 4";
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
    qDebug()<<"->checkCrush.checkRow in 5";
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
    qDebug()<<"->checkCrush.checkCol in 3";
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
    qDebug()<<"->checkCrush.checkCol in 4";
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
    qDebug()<<"->checkCrush.checkCol in 5";
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
    int listType[8][11];
    //record
    qDebug()<<"->checkCrush.record makelist";
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){
            makeList[i][j]=0;
            if(st[i][j]->isCrush && st[i][j]->crushNum != 3 && st[i][j]->isMoved)
                makeList[i][j] = st[i][j]->crushNum;
                listType[i][j] = st[i][j]->button->text().toInt();
        }

    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){

            if(st[i][j] != NULL)
            if(st[i][j]->isMoved && st[i][j]->button->text() == "5"){
                for(int k=0;k<11;k++)
                    for(int l=0;l<8;l++){
                        if(st[l][k] != NULL)
                        if(st[l][k]->isMoved &&st[l][k]->button->text() != "5"){
                            qDebug()<<"->checkCrush.starCrush";
                            starCrushType = st[l][k]->button->text().toInt();
                            anyCrush = true;
                            st[i][j]->crush();
                            qDebug()<<"end starCrush";
                        }
                    }
            }

        }
    //crush
    qDebug()<<"->checkCrush.crush";
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++)
            if(st[i][j] != NULL)
            if(st[i][j]->isCrush){
                qDebug()<<"crush "<<i<<j;
                st[i][j]->crush();
                st[i][j] = NULL;
                qDebug()<<"finished crush";
            }
    //make
    qDebug()<<"->checkCrush.make";
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){
            if(makeList[i][j] != 0){
                    st[i][j] = genSpecial(makeList[i][j],listType[i][j],i,j);
                    qDebug()<<"genSpecial";
            }
        }
    //reset isMove, isCrush?
    if(anyCrush)qDebug()<<"crush!";
    return anyCrush;
}

void game::refresh()
{   qDebug()<<"refresh";
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++){
            if(st[i][j] != NULL)
            st[i][j]->isMoved = false;
        }
    for(int j=10;j>-1;j--)
    for(int i=7;i>-1;i--){
        if(st[i][j]==NULL){
        for(int k=j;k>-1;k--){
            if(st[i][k]!=NULL && st[i][k+1]==NULL){
                st[i][k+1] = st[i][k];
                st[i][k] = NULL;
                st[i][k+1]->stMove(i,k+1);
                st[i][k+1]->row = i;
                st[i][k+1]->col = k+1;
                k+=2;
            }
        }
        }
    }
    qDebug()<<"refresh end";
}

void game::fillRandStone()
{
    qDebug()<<"fill";
    for(int j=0;j<11;j++)
        for(int i=0;i<8;i++)
            if(st[i][j]==NULL){
                st[i][j] = randStone(i,j);
            }
    for(int i=0;i<11;i++)
        for(int j=0;j<8;j++){
            connect(st[j][i],SIGNAL(click()),this,SLOT(stone_clicked()));
            connect(st[j][i],SIGNAL(superCrush(int ,int ,int )),this,SLOT(superCrush(int,int ,int )));
        }
}

stone *game::randStone(int row ,int col)
{
    int type = 0;
    stone* ptr;

    type = random()%4+1;
    ptr = new stone1(this,type,row,col);
    qDebug()<<"stone gen!";
    ptr->button->show();
    return ptr;
}


stone *game::genSpecial(int which,int type,int row, int col)
{
    stone* ptr = NULL;
    switch(which){
        case 1:
        ptr = new stoneC(this,type,row,col);
        break;
        case 2:
        ptr = new stoneR(this,type,row,col);
        break;
        case 5:
        ptr = new stoneS(this,row,col);
        break;
        case 6:
        ptr = new stoneB(this,type,row,col);
        break;
        default:
        ptr = NULL;
        qDebug()<<"error switch!";
    }
    qDebug()<<"Specialstone gen";
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
    qDebug()<<"->stone_clicked.nearby";
    if(isNearby){
        stone *temp;

        //exchange , if no isCrush produce exchange again.

        temp = st[rec_i[0]][rec_j[0]];
        st[rec_i[0]][rec_j[0]] = st[rec_i[1]][rec_j[1]];
        st[rec_i[1]][rec_j[1]] = temp;
        st[rec_i[0]][rec_j[0]]->stMove(rec_i[0],rec_j[0]);
        st[rec_i[0]][rec_j[0]]->row = rec_i[0];
        st[rec_i[0]][rec_j[0]]->col = rec_j[0];
        st[rec_i[1]][rec_j[1]]->stMove(rec_i[1],rec_j[1]);
        st[rec_i[1]][rec_j[1]]->row = rec_i[1];
        st[rec_i[1]][rec_j[1]]->col = rec_j[1];
        qDebug()<<"->checkCrush";
        if(checkCrush()/*exchange and crush*/){
        //(move)
            qDebug()<<"->in check if";
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
            st[rec_i[0]][rec_j[0]]->row = rec_i[0];
            st[rec_i[0]][rec_j[0]]->col = rec_j[0];
            st[rec_i[1]][rec_j[1]]->stMove(rec_i[1],rec_j[1]);
            st[rec_i[1]][rec_j[1]]->row = rec_i[1];
            st[rec_i[1]][rec_j[1]]->col = rec_j[1];
            st[rec_i[0]][rec_j[0]]->isMoved = false;
            st[rec_i[1]][rec_j[1]]->isMoved = false;
        }

    }
   qDebug()<<"->stone_clicked.reset isMoved";
   for(int i = 0;i<2;i++)
        st[rec_i[i]][rec_j[i]]->isClicked=false;

    }
    for(int i=0;i<8;i++)
        for(int j=0;j<11;j++){
            if(st[i][j]->isClicked)st[i][j]->bg->show();
            if(!st[i][j]->isClicked)st[i][j]->bg->hide();
        }
}

void game::superCrush(int type, int row, int col)
{

    if(type == 0)return;
    qDebug()<<"superCrush!"<<type<<row<<col;
    delete st[row][col];
    st[row][col] = NULL;
    if(type == 1){
        //col crush
        for(int i=0;i<11;i++){
            if(st[row][i] != NULL){
                    qDebug()<<" in supercrush loop"<<row<<i;
               st[row][i]->crush();
               st[row][i] = NULL;

            }
        }
    }else if(type == 2){
        //row crush
        for(int i=0;i<8;i++){
            if(st[i][col] != NULL){
               st[i][col]->crush();
               st[i][col] = NULL;
               qDebug()<<"in rowCrush loop"<<i<<col;
            }
        }
    }else if(type == 5){
        //star crush
        if(starCrushType == 0)
               qDebug()<<"error in starCrush";
        for(int i=0;i<8;i++)
            for(int j=0;j<11;j++)
                if(st[i][j] != NULL)
                if(st[i][j]->button->text() == QString::number(starCrushType)){
                   st[i][j]->crush();
                   st[i][j] = NULL;
                   qDebug()<<"starCrush"<<i<<j;
                }
        starCrushType = 0;
    }else if(type == 6){
        //bomb crush
        for(int i=0;i<9;i++){
            if((row-1+i%3)>-1 && (row-1+i%3) <8 && (col-1+i/3) > -1 && (col-1+i/3) < 11)
            if(st[row-1+i%3][col-1+i/3] != NULL){
                st[row-1+i%3][col-1+i/3]->crush();
                st[row-1+i%3][col-1+i/3] = NULL;
            }
        }
    }
    qDebug()<<"out superCrush loop";
}

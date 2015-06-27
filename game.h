#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <Qtimer>
#include "stone.h"
#include "result.h"
#include "stone1.h"
#include "stoneb.h"
#include "stonec.h"
#include "stoner.h"
#include "stones.h"
#include "result.h"
namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent,result *res);
    int star;
    ~game();
        int score;
signals:
    void quit(int star , int score);
private:
    Ui::game *ui;
    stone *st[8][11];
    int times;
    int move;
    int starCrushType;
    QIcon st1[4];
    QIcon stc[4];
    QIcon str[4];
    QIcon stb[4];
    QIcon sts;
    bool checkCrush();
    void refresh();
    void fillRandStone();
    stone* randStone(int row, int col);
    stone* genSpecial(int which, int type, int row, int col);
    QTimer* timer2;
    result *res;
private slots:
    void moveclock();
    void scorePlus();
    void stone_clicked();
    void superCrush(int type,int row,int col);
};

#endif // GAME_H

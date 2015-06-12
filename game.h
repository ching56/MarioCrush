#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "stone.h"
#include "result.h"
#include "stone1.h"
#include "stoneb.h"
#include "stonec.h"
#include "stoner.h"
#include "stones.h"

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent,result *res);
    ~game();

private:
    Ui::game *ui;
    stone *st[8][11];
    int score;
    int star;
    int move;
    int starCrushType;
    bool checkCrush();
    void refresh();
    void fillRandStone();
    stone* randStone(int row, int col);
    stone* genSpecial(int which, int type, int row, int col);
private slots:
    void stone_clicked();
    void superCrush(int type,int row,int col);
};

#endif // GAME_H

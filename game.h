#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "stone.h"
#include "result.h"
#include "stone1.h"
#include "stone2.h"
#include "stone3.h"
#include "stone4.h"

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
private slots:
    void stone_clicked();
};

#endif // GAME_H

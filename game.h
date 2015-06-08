#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "stone.h"
#include "result.h"

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
    stone st[8][12];
};

#endif // GAME_H

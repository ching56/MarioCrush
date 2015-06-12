#ifndef STONER_H
#define STONER_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stoneR :public stone
{
    Q_OBJECT
public:
    stoneR(QWidget *parent,int type ,int row, int col);
    void crush();
};

#endif // STONER_H

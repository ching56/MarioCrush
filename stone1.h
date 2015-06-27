#ifndef STONE1_H
#define STONE1_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stone1 :public stone
{
    Q_OBJECT
public:
    stone1(QWidget *parent,int type ,int row, int col);
    ~stone1();
    void crush();
signals:
    void getPoint();
};

#endif // STONE1_H

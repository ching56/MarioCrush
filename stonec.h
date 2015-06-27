#ifndef STONEC_H
#define STONEC_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stoneC :public stone
{
    Q_OBJECT
public:
    stoneC(QWidget *parent,int type ,int row, int col);
    void crush();
    ~stoneC();

};

#endif // STONEC_H

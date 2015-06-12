#ifndef STONES_H
#define STONES_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stoneS : public stone
{
    Q_OBJECT
public:
    stoneS(QWidget *parent, int row, int col);
    void crush();
signals:
    void superCrush(int type,int row,int col);
};

#endif // STONES_H

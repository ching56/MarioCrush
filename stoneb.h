#ifndef STONEB_H
#define STONEB_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stoneB : public stone
{
    Q_OBJECT
public:
    stoneB(QWidget *parent,int type ,int row, int col);
    void crush();
};

#endif // STONEB_H

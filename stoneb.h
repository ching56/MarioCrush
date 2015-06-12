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
    stoneB(QWidget *parent, int row, int col);
    void crush();
signals:
    void superCrush(int type,int row,int col);
};

#endif // STONEB_H

#ifndef STONE2_H
#define STONE2_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stone2 : public stone
{
        Q_OBJECT
public:
    stone2(QWidget *parent, int row, int col);
    void crush();
};

#endif // STONE2_H

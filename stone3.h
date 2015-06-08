#ifndef STONE3_H
#define STONE3_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stone3 : public stone
{
        Q_OBJECT
public:
    stone3(QWidget *parent, int row, int col);
private:
    void crush();
};

#endif // STONE3_H

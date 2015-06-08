#ifndef STONE4_H
#define STONE4_H
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "stone.h"

class stone4 : public stone
{
        Q_OBJECT
public:
    stone4(QWidget *parent, int row, int col);
private:
    void crush();
};

#endif // STONE4_H

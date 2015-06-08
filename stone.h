#ifndef STONE_H
#define STONE_H

#include <QObject>
#include <QPushButton>
class stone : public QWidget
{
    Q_OBJECT
public:
    stone();
private:
    QPushButton button;

};

#endif // STONE_H

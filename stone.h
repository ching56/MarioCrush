#ifndef STONE_H
#define STONE_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
class stone : public QObject
{
    Q_OBJECT
public:
    stone(QWidget *parent, int row, int col);
signals:
    void click();
protected:
    QPushButton *button;
    QLabel *bg;
    bool isClicked;
    virtual void crush();
protected slots:
    void button_clicked();
};

#endif // STONE_H

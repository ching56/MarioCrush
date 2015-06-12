#ifndef STONE_H
#define STONE_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
class stone : public QObject
{
    Q_OBJECT
    friend class game;
public:
    stone(QWidget *parent, int row, int col);
    ~stone();
    virtual void crush()=0;
    void stMove(int row, int col);
signals:
    void click();
protected:
    QPushButton *button;
    QLabel *bg;
    bool isClicked;
    bool isMoved;
    bool isCrush;
    int crushNum;
    int row;
    int col;
protected slots:
    void button_clicked();
};

#endif // STONE_H

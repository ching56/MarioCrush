#ifndef STONE_H
#define STONE_H

#include <QObject>
#include <QToolbutton>
#include <QLabel>
class stone : public QObject
{
    Q_OBJECT
    friend class game;
public:
    stone(QWidget *parent, int row, int col);
    virtual ~stone();
    virtual void crush()=0;
    void stMove(int r, int c);
signals:
    void click();
    void superCrush(int type,int row,int col);
protected:
    QToolButton *button;
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

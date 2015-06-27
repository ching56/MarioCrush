#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <QMainWindow>
#include "game.h"
#include "result.h"

namespace Ui {
class startscreen;
}

class startscreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit startscreen(QMainWindow *parent = 0);
    ~startscreen();
signals:
        void quit(int star , int score);
private slots:
    void reemit(int star, int score);
    void on_botton_start_clicked();
    void resetgame();

private:
    Ui::startscreen *ui;
    game *gamewindow;
    result *resultwindow;
};

#endif // STARTSCREEN_H

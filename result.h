#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class result;
}
QLabel & operator++(QLabel &,int);
class result : public QDialog
{
    Q_OBJECT

public:
    int score;
    explicit result(QWidget *parent = 0);
    ~result();
    void getScore(int score);
signals:
    void reset();
    void quit(int star , int score);
private slots:
    void on_botton_start_clicked();
    void on_botton_start_2_clicked();

private:
    QLabel* Text;
    Ui::result *ui;
    QWidget* parent;
};

#endif // RESULT_H

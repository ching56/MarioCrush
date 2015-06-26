#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();
    void getScore(int score);
signals:
    void reset();
private slots:
    void on_botton_start_clicked();

    void on_botton_start_2_clicked();

private:
    QLabel* Text;
    Ui::result *ui;
};

#endif // RESULT_H

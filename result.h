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

private:
    QLabel* Text;
    Ui::result *ui;
};

#endif // RESULT_H

#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();

private:
    Ui::result *ui;
};

#endif // RESULT_H

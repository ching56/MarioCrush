#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    Text = ui->label;
    ui->s1->hide();
    ui->s2->hide();
    ui->s3->hide();
}

result::~result()
{
    delete ui;
}

void result::getScore(int score)
{
    if(score>1000){
        Text->setText("<span style=\" color:#ffffff;\">Try again</span>");
        ui->s1->show();
    }
    if(score>2000){
        Text->setText("<span style=\" color:#ffffff;\">Not Bad</span>");
        ui->s2->show();
    }
    if(score>3000){
        Text->setText("<span style=\" color:#ffffff;\">AWASOME!</span>");
        ui->s3->show();
    }

}

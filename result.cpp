#include "result.h"
#include "ui_result.h"
#include <QDebug>
QLabel& operator++(QLabel& l,int){
    if(l.text() == "<span style=\" color:#ffffff;\">Try again</span>")
        l.setText("<span style=\" color:#ffffff;\">Not Bad</span>");
    else if(l.text() == "<span style=\" color:#ffffff;\">Not Bad</span>")
        l.setText("<span style=\" color:#ffffff;\">AWASOME!</span>");
    qDebug()<<"OVERLOADING!!!";
    return l;
}

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
    qDebug()<<"in result";
    if(score>1000){
        Text->setText("<span style=\" color:#ffffff;\">Try again</span>");
        ui->s1->show();
    }
    if(score>2000){
        (*Text)++;
        ui->s2->show();
    }
    if(score>3000){
        (*Text)++;
        ui->s3->show();
    }

}

void result::on_botton_start_clicked()
{
    emit reset();
}

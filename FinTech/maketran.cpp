#include "maketran.h"
#include "ui_maketran.h"

makeTran::makeTran(QWidget *parent, const QString &username)
    : QDialog(parent)
    , ui(new Ui::makeTran)
{
    ui->setupUi(this);
}

makeTran::~makeTran()
{
    delete ui;
}

void makeTran::on_pushButton_clicked()
{
    hide();

}


void makeTran::on_pushButton_2_clicked()
{
    hide();
}


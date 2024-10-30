#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->logInImage->setPixmap(pix);

}

Dialog::~Dialog()
{
    delete ui;
}

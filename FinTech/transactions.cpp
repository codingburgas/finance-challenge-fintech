#include "transactions.h"
#include "ui_transactions.h"
#include "cards.h"
#include "mainwindow.h"


Transactions::Transactions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transactions)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->Logo->setPixmap(pix);
    QPixmap pix1("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Home.png");
    ui->Home->setPixmap(pix1.scaled(40,40));
    QPixmap pix2("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/File.png");
    ui->fileImg->setPixmap(pix2.scaled(40,40));
    QPixmap pix4("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Card.png");
    ui->Card->setPixmap(pix4.scaled(40,40));
    QPixmap pix5("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/account_circle.png");
    ui->account_2->setPixmap(pix5);
    QPixmap pix6("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/logOut.png");
    ui->logOut_2->setPixmap(pix6);
    QPixmap pix7("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/settings.png");
    ui->settings_2->setPixmap(pix7);
}

Transactions::~Transactions()
{
    delete ui;
}

void Transactions::on_pushButton_5_clicked()
{
    hide();
    Cards cards;
    cards.setModal(true);
    cards.exec();
}


void Transactions::on_pushButton_clicked()
{

}


void Transactions::on_logOutBut_2_clicked()
{
    hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}

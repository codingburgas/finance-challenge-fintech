#include "cards.h"
#include "ui_cards.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <qtSql>
#include <QSqlDatabase>
#include "transactions.h"

Cards::Cards(QWidget *parent, const QString &username)
    : QDialog(parent)
    , ui(new Ui::Cards)
    , username(username)
{
    ui->setupUi(this);
    ui->label_username_cards->setText("Welcome " + username);
    qDebug() << "Username in Cards:" << username;
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
    QPixmap pix10("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/visa-card2.png");
    ui->visaCard->setPixmap(pix10);
    QPixmap pix11("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/emptyVisa.png");
    ui->emptyVisa_4->setPixmap(pix11);
    QPixmap pix12("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/emptyVisa.png");
    ui->emptyVisa_5->setPixmap(pix12);
    QPixmap pix13("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/emptyVisa.png");
    ui->emptyVisa_6->setPixmap(pix13);
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");

    DB_Connection.setDatabaseName("C:/Users/Nikolay/Documents/finance-challenge-fintech/DBTest.db");
    if(!DB_Connection.open())
    {
        qDebug() << "Not Connected";
    }
    else
    {
        qDebug() << "connected";
    }
}

Cards::~Cards()
{
    delete ui;
}

void Cards::on_pushButton_6_clicked()
{
    hide();
    Transactions *transactions = new Transactions(username);
    transactions->show();

    //hide();
   //Transactions transactions(nullptr);
   // transactions.setModal(true);
   //transactions.exec();
}


void Cards::on_pushButton_clicked()
{
    hide();
    Balance balance(nullptr);
    balance.setModal(true);
    balance.exec();
}


void Cards::on_logOutBut_clicked()
{
    hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}
void Cards::on_pushButton_5_clicked()
{

}
void Balance::on_label_b_linkActivated(const QString &link)
{

}

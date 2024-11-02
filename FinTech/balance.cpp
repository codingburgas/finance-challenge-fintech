#include "balance.h"
#include "mainwindow.h"
#include "ui_balance.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <qtSql>
#include <QSqlDatabase>
#include "transactions.h"
#include "cards.h"

Balance::Balance(const QString &username, QWidget *parent)  // Constructor with username
    : QDialog(parent)
    , ui(new Ui::Balance)
{
    ui->setupUi(this);

    // Set the label to show the username
   ui->label_username->setText(username);
    ui->label_b->setText("Welcome, " + username);
   ui->label_card->setText(username + "'s cards");

    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->Logo->setPixmap(pix);
    QPixmap pix1("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Home.png");
    ui->Home->setPixmap(pix1.scaled(40,40));
    QPixmap pix2("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/File.png");
    ui->fileImg->setPixmap(pix2.scaled(40,40));
    QPixmap pix4("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Card.png");
    ui->Card->setPixmap(pix4.scaled(40,40));
    QPixmap pix5("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/account_circle.png");
    ui->account->setPixmap(pix5);
    QPixmap pix6("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/logOut.png");
    ui->logOut->setPixmap(pix6);
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");

    DB_Connection.setDatabaseName("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/DBTest.db");
    if(!DB_Connection.open())
    {
        qDebug() << "Not Connected";
    }
    else
    {
        qDebug() << "connected";
    }
    QPixmap pix7("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/settings.png");
    ui->settings->setPixmap(pix7);
    QPixmap pix8("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/options.png");
    ui->option->setPixmap(pix8.scaled(361,161));
    QPixmap pix9("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/visaCard.png");
    ui->visaCard->setPixmap(pix9.scaled(321,191));
}

Balance::~Balance()
{
    delete ui;
}




void Balance::on_label_b_linkActivated(const QString &link)
{

}



void Balance::on_pushButton_3_clicked()
{
    hide();
    Transactions transactions;
    transactions.setModal(true);
    transactions.exec();
}


void Balance::on_pushButton_5_clicked()
{
    hide();
    Cards cards;
    cards.setModal(true);
    cards.exec();
}


void Balance::on_pushButton_7_clicked()
{
    hide();
    Transactions transactions;
    transactions.setModal(true);
    transactions.exec();
}


void Balance::on_pushButton_9_clicked()
{

}


void Balance::on_logOutBut_clicked()
{
    hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}


void Balance::on_pushButton_8_clicked()
{
    hide();
    Cards cards;
    cards.setModal(true);
    cards.exec();
}


void Balance::on_pushButton_6_clicked()
{
    hide();
    Cards cards;
    cards.setModal(true);
    cards.exec();
}


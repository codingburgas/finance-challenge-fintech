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

Balance::Balance(const QString &username, QWidget *parent)  // Constructor with username
    : QDialog(parent)
    , ui(new Ui::Balance)
{
    ui->setupUi(this);

    // Set the label to show the username
   ui->label_username->setText("Welcome, " + username);

    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->Logo->setPixmap(pix);
    QPixmap pix1("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Home.png");
    ui->Home->setPixmap(pix1.scaled(40,40));
    QPixmap pix2("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/File.png");
    ui->fileImg->setPixmap(pix2.scaled(40,40));
    QPixmap pix3("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/dollarSign.png");
    ui->dollarSign->setPixmap(pix3.scaled(40,40));
    QPixmap pix4("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Card.png");
    ui->Card->setPixmap(pix4.scaled(40,40));
    QPixmap pix5("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/account_circle.png");
    ui->account->setPixmap(pix5);
    QPixmap pix6("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/logOut.png");
    ui->logOut->setPixmap(pix6);
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

Balance::~Balance()
{
    delete ui;
}




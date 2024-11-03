#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QSqlQuery>
#include "dialog.h"
#include "balance.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->logInImage->setPixmap(pix);

    QPixmap pix2("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/account_circle1.png");
    ui->iconImage->setPixmap(pix2);

    QPixmap pix3("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Lock.png");
    ui->lockImage->setPixmap(pix3);

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

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_registerButton_clicked()
{
    hide();
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_pushButton_clicked()
{
    QString UserName = ui->txt_username->text();
    QString Password = ui->txt_password->text();


        QSqlQuery QueryGetUser(DB_Connection);
        QueryGetUser.prepare("SELECT * FROM Users WHERE Username ='" + UserName + "' AND Password ='" + Password + "'");
        if(QueryGetUser.exec())
        {
            int UserFindCount = 0;
            while(QueryGetUser.next())
            {
                UserFindCount = UserFindCount + 1;

            }
            if(UserFindCount == 1)
            {
                this->hide();
                Balance *balance = new Balance(UserName, this);
                balance->show();
            }
            else if(UserFindCount == 0)
            {
                QMessageBox::information(this,"Test", "Please Check Your Username and Password.");

            }
        }
        else
        {
            QMessageBox::information(this,"Test", "Please Check Your Username and Password.");

        }
    }





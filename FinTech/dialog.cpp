#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <qtSql>
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->logInImage->setPixmap(pix);
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
}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_regButton_clicked()
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO Users(ID,Username,Password,FirstName,LastName, currentBalance) VALUES(:ID,:Username,:Password,:FirstName,:LastName, :currentBalance)");
    QueryInsertData.bindValue(":ID", ui->txt_id->text());
    QueryInsertData.bindValue(":Username", ui->txt_username->text());
    QueryInsertData.bindValue(":Password", ui->txt_password->text());
    QueryInsertData.bindValue(":FirstName", ui->txt_Fname->text());
    QueryInsertData.bindValue(":LastName", ui->txt_Lname->text());
    QueryInsertData.bindValue(":currentBalance",0);
    if (!QueryInsertData.exec()) {
        qDebug() << "Insert query failed: " << QueryInsertData.lastError().text();
       QSqlDatabase::database().rollback();
   } else {
      QSqlDatabase::database().commit();
       qDebug() << "Data inserted successfully";
    }

    QSqlDatabase::database().commit();
    DB_Connection.close();
}




void Dialog::on_backToLogIn_clicked()
{
    hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}



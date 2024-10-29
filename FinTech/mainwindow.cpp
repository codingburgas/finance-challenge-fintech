#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "secDiealog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Nikolay/Documents/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->logInImage->setPixmap(pix);

    QPixmap pix2("C:/Users/Nikolay/Documents/finance-challenge-fintech/FinTech/assets/account_circle.png");
    ui->iconImage->setPixmap(pix2);

    QPixmap pix3("C:/Users/Nikolay/Documents/finance-challenge-fintech/FinTech/assets/Lock.png");
    ui->lockImage->setPixmap(pix3);

     mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Nikolay/Desktop/sqTest.db");

    if(mydb.open())
        qDebug() << "Connected";
    else
         qDebug() << "Failed to open the database";
}

MainWindow::~MainWindow()
{
    mydb.close();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Retrieve data from the UI input fields
    QString username = ui->txt_username->text();
    QString password = ui->txt_password->text();

    // Check for empty fields
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::information(this,"Error", "Enter both username and password!");
        return;
    }

    // Clear any previous query in case of reuse
    QSqlQuery qry;

    // Prepare the query with the correct number of placeholders
    qry.prepare("INSERT INTO users (name, age) VALUES (?, ?)");

    // Bind values to the placeholders
    qry.addBindValue(username); // Bind username to the first placeholder
    qry.addBindValue(30);       // Bind a dummy age value to the second placeholder

    // Execute the query and handle success/failure
    if (qry.exec()) {
        ui->txt_username->setText("Data saved successfully!");
        qDebug() << "Data saved: Username -" << username;
    } else {
        qDebug() << "Database insert error: " << qry.lastError().text(); // Use .text() for clarity
    }
}



void MainWindow::on_registerButton_clicked()
{
    SecDiealog -> show();
}


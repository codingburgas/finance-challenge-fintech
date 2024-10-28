#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPushButton>

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

    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Nikolay/Documents/finance-challenge-fintech/demodb.db");

    if(!mydb.open())
        ui->pushButton->setText("Fatal");
    else
        ui->pushButton->setText("Connected");
}

MainWindow::~MainWindow()
{
    delete ui;
}


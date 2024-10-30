#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->logInImage->setPixmap(pix);

    QPixmap pix2("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/account_circle.png");
    ui->iconImage->setPixmap(pix2);

    QPixmap pix3("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Lock.png");
    ui->lockImage->setPixmap(pix3);
}

MainWindow::~MainWindow()
{
    mydb.close();
    delete ui;
}

void MainWindow::on_registerButton_clicked()
{
    hide();
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}


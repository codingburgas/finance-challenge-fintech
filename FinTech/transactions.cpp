#include "transactions.h"
#include "ui_transactions.h"
#include "cards.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

Transactions::Transactions(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transactions)
    , username(username)
{
    ui->setupUi(this);

      ui->label_username_t->setText(username);
    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->Logo_2->setPixmap(pix);
    QPixmap pix1("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Home.png");
    ui->Home_2->setPixmap(pix1.scaled(40,40));
    QPixmap pix2("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/File.png");
    ui->fileImg_2->setPixmap(pix2.scaled(40,40));
    QPixmap pix4("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Card.png");
    ui->Card_2->setPixmap(pix4.scaled(40,40));
    QPixmap pix5("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/account_circle.png");
    ui->account_2->setPixmap(pix5);
    QPixmap pix6("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/logOut.png");
    ui->logOut_2->setPixmap(pix6);
    QPixmap pix7("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/settings.png");
    ui->settings_2->setPixmap(pix7);

    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("C:/Users/Nikolay/Documents/finance-challenge-fintech/DBTest.db");



    if (!DB_Connection.open()) {
        qDebug() << "Not Connected";
        QMessageBox::critical(this, "Database Connection Error", DB_Connection.lastError().text());
    } else {
        qDebug() << "Connected";
         fetchAndDisplayTransactions();
        // Fetch and display currentBalance
        QSqlQuery query;
        query.prepare("SELECT currentBalance FROM Users WHERE Username = :username");
        query.bindValue(":username", username);

        if (query.exec()) {
            if (query.next()) {
                double balance = query.value(0).toDouble();
                ui->label_21->setText(QString("$%1").arg(balance, 0, 'f', 2));
            } else {
                ui->label_21->setText("Balance not found.");
            }
        } else {
            qDebug() << "Query execution error: " << query.lastError();
            ui->label_21->setText("Error retrieving balance.");
        }


    }

}

Transactions::~Transactions()
{
    delete ui;
}

void Transactions::on_pushButton_5_clicked()
{
    hide();
    Cards cards(nullptr, username);
    cards.setModal(true);
    cards.exec();
}


void Transactions::on_pushButton_clicked()
{

    hide();
    Balance balance(username);
    balance.setModal(true);
    balance.exec();
}


void Transactions::on_logOutBut_2_clicked()
{
    hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}
void Transactions::fetchAndDisplayTransactions() {
    qDebug()<<username;
    QLayoutItem *child;
    while ((child = ui->transactionLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            child->widget()->deleteLater();
        }
        delete child;
    }

    QSqlQuery query(this->DB_Connection);
    query.prepare("SELECT [Transaction], Amount, Category, Date FROM Transactions "
                  "WHERE userId = (SELECT ID FROM Users WHERE Username = :username) ORDER BY Date DESC");
    query.bindValue(":username", username);

    if (query.exec()) {
        while (query.next()) {
            QString transactionName = query.value(0).toString();
            double amount = query.value(1).toDouble();
            QString category = query.value(2).toString();
            QString date = query.value(3).toString();

            // Create widgets for each transaction detail
            QLabel *transactionLabel = new QLabel(transactionName);
            QLabel *amountLabel = new QLabel(QString::number(amount, 'f', 2));
            QLabel *categoryLabel = new QLabel(category);
            QLabel *dateLabel = new QLabel(date);

            // Style the labels
            transactionLabel->setStyleSheet("font-size: 30px; font-family: inter; margin-left: 60px;");
            amountLabel->setStyleSheet("font-size: 30px; font-family: inter; color: #8B1F1F; margin-left: 90px;");
            categoryLabel->setStyleSheet("font-size: 30px; font-family: inter; color: #6750A4; margin-left: 70px;");
            dateLabel->setStyleSheet("font-size: 30px; font-family: inter;");

            // Layout for a single transaction row
            QHBoxLayout *transactionRow = new QHBoxLayout();
            transactionRow->addWidget(transactionLabel);
            transactionRow->addWidget(amountLabel);
            transactionRow->addWidget(categoryLabel);
            transactionRow->addWidget(dateLabel);

            ui->transactionLayout->addLayout(transactionRow);
        }
    } else {
        qDebug() << "Query execution error: " << query.lastError();
    }

}

void Transactions::on_pushButton_7_clicked()
{
    hide();
    Balance balance(username);
    balance.setModal(true);
    balance.exec();
}

void Transactions::on_pushButton_2_clicked()
{
    hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}


#include "balance.h"
#include "mainwindow.h"
#include "ui_balance.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "transactions.h"
#include "cards.h"
#include "maketran.h"
#include <QVector>



Balance::Balance(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Balance)
    , username(username)
{
    ui->setupUi(this);

    ui->label_username->setText(username);
    ui->label_b->setText("Welcome, " + username + "!");
    ui->label_card->setText(username + "'s cards!");

    // Load logos and icons
    QPixmap pix("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/image 1.png");
    ui->Logo->setPixmap(pix);
    QPixmap pix1("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Home.png");
    ui->Home->setPixmap(pix1.scaled(40, 40));
    QPixmap pix2("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/File.png");
    ui->fileImg->setPixmap(pix2.scaled(40, 40));
    QPixmap pix4("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Card.png");
    ui->Card->setPixmap(pix4.scaled(40, 40));
    QPixmap pix5("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/account_circle.png");
    ui->account->setPixmap(pix5);
    QPixmap pix6("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/logOut.png");
    ui->logOut->setPixmap(pix6);
    QPixmap pix7("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/settings.png");
    ui->settings->setPixmap(pix7);
    QPixmap pix8("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/options.png");
    ui->option->setPixmap(pix8.scaled(361, 161));
    QPixmap pix9("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/visa-card2.png");
    ui->visaCard->setPixmap(pix9.scaled(321, 191));
    QPixmap pix10("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Tv.png");
    ui->Tv->setPixmap(pix10);
    QPixmap pix11("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/cart.png");
    ui->cart->setPixmap(pix11);
    QPixmap pix12("C:/Users/simeo/Documents/school projects/finance-challenge-fintech/FinTech/assets/Compass.png");
    ui->Compas->setPixmap(pix12);

    // Setup database connection
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("C:/Users/Nikolay/Documents/finance-challenge-fintech/DBTest.db");

    if (!DB_Connection.open()) {
        qDebug() << "Not Connected";
        QMessageBox::critical(this, "Database Connection Error", DB_Connection.lastError().text());
    } else {
        qDebug() << "Connected";

        // Fetch and display currentBalance
        QSqlQuery query;
        query.prepare("SELECT currentBalance FROM Users WHERE Username = :username");
        query.bindValue(":username", username);

        if (query.exec()) {
            if (query.next()) {
                double balance = query.value(0).toDouble();
                ui->label_money->setText(QString("$%1").arg(balance, 0, 'f', 2));
            } else {
                ui->label_money->setText("Balance not found.");
            }
        } else {
            qDebug() << "Query execution error: " << query.lastError();
            ui->label_money->setText("Error retrieving balance.");
        }
    }
    fetchAndDisplayTransactions();
}


Balance::~Balance()
{
    delete ui;
}




void Balance::on_pushButton_3_clicked() {
    hide();
    Transactions transactions(username);
    transactions.setModal(true);
    transactions.exec();
}

void Balance::on_pushButton_5_clicked() {
    hide();
    Cards cards(nullptr, username);
    cards.setModal(true);
    cards.exec();
}

void Balance::on_pushButton_7_clicked() {
    hide();
    Transactions transactions(username);
    transactions.setModal(true);
    transactions.exec();
}

void Balance::on_pushButton_9_clicked() {
    makeTran *maketran = new makeTran(this, username);
    maketran->setAttribute(Qt::WA_DeleteOnClose);
    connect(maketran, &makeTran::balanceUpdated, this, &Balance::updateBalance);
    maketran->show();

}

void Balance::on_logOutBut_clicked() {
    hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}

void Balance::on_pushButton_8_clicked() {
    hide();
    Cards cards(nullptr, username);
    cards.setModal(true);
    cards.exec();
}

void Balance::on_pushButton_6_clicked() {
    hide();
    Cards cards(nullptr, username);
    cards.setModal(true);
    cards.exec();
}

void Balance::on_label_b_linkActivated(const QString &link) {}

void Balance::on_label_username_linkActivated(const QString &link) {}

void Balance::updateBalance() {
    QSqlQuery query(DB_Connection);
    query.prepare("SELECT currentBalance FROM Users WHERE Username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        double balance = query.value(0).toDouble();
        ui->label_money->setText(QString("$%1").arg(balance, 0, 'f', 2));
        fetchAndDisplayTransactions();
    }
}

void Balance::fetchAndDisplayTransactions() {


    QSqlQuery userQuery;
    int userId = -1;

    userQuery.prepare("SELECT ID FROM Users WHERE Username = :username");
    userQuery.bindValue(":username", username);

    if (userQuery.exec() && userQuery.next()) {
        userId = userQuery.value(0).toInt();
    } else {
        qDebug() << "User ID query execution error: " << userQuery.lastError();
        return; // Exit if we couldn't retrieve the user ID
    }

    if (userId != -1) {
        QSqlQuery transactionQuery;
        transactionQuery.prepare("SELECT [Transaction], Amount, Category, Date "
                                 "FROM Transactions "
                                 "WHERE userId = :userId "
                                 "ORDER BY Date DESC LIMIT 4");
        transactionQuery.bindValue(":userId", userId);

        QVector<Transaction> transactions;
        if (transactionQuery.exec()) {
            while (transactionQuery.next()) {
                Transaction tran;
                tran.name = transactionQuery.value(0).toString();
                tran.amount = transactionQuery.value(1).toDouble();
                tran.category = transactionQuery.value(2).toString();
                tran.date = transactionQuery.value(3).toString();
                transactions.append(tran);
            }
        } else {
            qDebug() << "Transaction query execution error: " << transactionQuery.lastError();
        }

        displayTransactions(transactions);
    } else {
        qDebug() << "User ID not found for username: " << username;
    }


}

void Balance::displayTransactions(const QVector<Transaction> &transactions) {
    // Clear existing labels
    ui->label_transaction1->clear();
    ui->label_transaction2->clear();
    ui->label_transaction3->clear();
    ui->label_transaction4->clear();
    ui->label_amount1->clear();
    ui->label_amount2->clear();
    ui->label_amount3->clear();
    ui->label_amount4->clear();
    ui->label_category1->clear();
    ui->label_category2->clear();
    ui->label_category3->clear();
    ui->label_category4->clear();
    ui->label_date1->clear();
    ui->label_date2->clear();
    ui->label_date3->clear();
    ui->label_date4->clear();

    // Display "No transactions found" if the list is empty
    if (transactions.isEmpty()) {
        ui->label_transaction1->setText("-");
        return;
    }

    // Display each transaction
    for (int i = 0; i < transactions.size() && i < 4; ++i) {
        const Transaction &tran = transactions[i];
        switch (i) {
        case 0:
            qDebug() << tran.name;
            ui->label_transaction1->setText(tran.name);
            ui->label_amount1->setText(QString::number(tran.amount, 'f', 2));
            ui->label_category1->setText(tran.category);
            ui->label_date1->setText(tran.date);
            break;
        case 1:
            ui->label_transaction2->setText(tran.name);
            ui->label_amount2->setText(QString::number(tran.amount, 'f', 2));
            ui->label_category2->setText(tran.category);
            ui->label_date2->setText(tran.date);
            break;
        case 2:
            ui->label_transaction3->setText(tran.name);
            ui->label_amount3->setText(QString::number(tran.amount, 'f', 2));
            ui->label_category3->setText(tran.category);
            ui->label_date3->setText(tran.date);
            break;
        case 3:
            ui->label_transaction4->setText(tran.name);
            ui->label_amount4->setText(QString::number(tran.amount, 'f', 2));
            ui->label_category4->setText(tran.category);
            ui->label_date4->setText(tran.date);
            break;
        }
    }
}







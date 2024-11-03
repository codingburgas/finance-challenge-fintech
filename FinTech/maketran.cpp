#include "maketran.h"
#include "ui_maketran.h"
#include <QPixmap>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <qtSql>
#include <QSqlDatabase>
#include <QDebug>
#include "transactions.h"

// Adjust constructor parameter list if necessary
makeTran::makeTran(QWidget *parent, const QString &username, int userId)
    : QDialog(parent)
    , ui(new Ui::makeTran)
    , userId(userId)
{
    ui->setupUi(this);

    // Initialize combo box
    ui->comboBox->addItem("Income");
    ui->comboBox->addItem("Outcome");

    // Set up database connection
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("C:/Users/Nikolay/Documents/finance-challenge-fintech/DBTest.db");

    if (!DB_Connection.open()) {
        qDebug() << "Not Connected";
    } else {
        qDebug() << "Connected to database";
    }
}

makeTran::~makeTran()
{
    delete ui;
}

void makeTran::on_pushButton_clicked()
{
    // Ensure the database is open
    if (!DB_Connection.isOpen()) {
        if (!DB_Connection.open()) {
            qDebug() << "Failed to open database";
            return;
        }
    }

    // Start a transaction
    QSqlDatabase::database().transaction();
    QSqlQuery QueryInsertData(DB_Connection);

    // Prepare the insert query
    QueryInsertData.prepare("INSERT INTO Transactions ([Transaction], Amount, Category, userId) "
                            "VALUES (:Transaction, :Amount, :Category, :userId)");

    // Bind the insert values
    QueryInsertData.bindValue(":Transaction", ui->txt_transaction->text());
    QueryInsertData.bindValue(":Amount", ui->txt_amount->text().toDouble());
    QueryInsertData.bindValue(":Category", ui->comboBox->currentText());

    int userId = 1; // Make sure you replace this with the actual user ID you want to use
    QueryInsertData.bindValue(":userId", userId);

    // Execute the insert query
    if (!QueryInsertData.exec()) {
        qDebug() << "Insert query failed: " << QueryInsertData.lastError().text();
        QSqlDatabase::database().rollback();
        return; // Exit early
    }

    // Proceed to update the balance
    QString transactionType = ui->comboBox->currentText();
    double amount = ui->txt_amount->text().toDouble();

    QSqlQuery QueryUpdateBalance(DB_Connection);

    // Prepare the update balance query
    if (transactionType == "Income") {
        QueryUpdateBalance.prepare("UPDATE Users SET currentBalance = currentBalance + :amount WHERE ID = :userId");
    } else if (transactionType == "Outcome") {
        QueryUpdateBalance.prepare("UPDATE Users SET currentBalance = currentBalance - :amount WHERE ID = :userId");
    }

    QueryUpdateBalance.bindValue(":amount", amount);
    QueryUpdateBalance.bindValue(":userId", userId); // Ensure this is the correct ID

    // Execute the update query
    if (!QueryUpdateBalance.exec()) {
        qDebug() << "Update balance failed: " << QueryUpdateBalance.lastError().text();
        QSqlDatabase::database().rollback();  // Rollback if update fails
    } else {
        QSqlDatabase::database().commit();  // Commit if everything is successful
        qDebug() << "Transaction and balance updated successfully";
        emit balanceUpdated();
        this->accept();
    }
   DB_Connection.close();
}





void makeTran::on_pushButton_2_clicked()
{
    // Close the dialog
    this->close();
}

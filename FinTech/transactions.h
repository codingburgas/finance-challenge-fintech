#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>
#include "balance.h"
#include <QDialog>
#include <QMainWindow>
#include <qtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QString>

namespace Ui {
class Transactions;
}

class Transactions : public QDialog
{
    Q_OBJECT

public:
    explicit Transactions(const QString &username, QWidget *parent = nullptr);
    ~Transactions();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_logOutBut_2_clicked();
    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Transactions *ui;
      QString username;
    QSqlDatabase DB_Connection;
    void fetchAndDisplayTransactions();

};

#endif // TRANSACTIONS_H

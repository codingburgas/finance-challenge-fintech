#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>
#include <QMainWindow>
#include <qtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QString>


namespace Ui {
class Balance;
}

struct Transaction {
    QString name;
    double amount;
    QString category;
    QString date;
};

class Balance : public QDialog
{
    Q_OBJECT

public:
    explicit Balance(const QString &username, QWidget *parent = nullptr);
    ~Balance();

private slots:


    void on_label_b_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_logOutBut_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_label_username_linkActivated(const QString &link);




private:
    Ui::Balance *ui;
    QSqlDatabase DB_Connection;
    QString username;
    void fetchAndDisplayTransactions();
    void displayTransactions(const QVector<Transaction> &transactions);


public slots:
    void updateBalance();


};

#endif // BALANCE_H

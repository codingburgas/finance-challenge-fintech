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

private:
    Ui::Balance *ui;
    QSqlDatabase DB_Connection;
    QString username;


};

#endif // BALANCE_H

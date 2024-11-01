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


private:
    Ui::Balance *ui;
    QSqlDatabase DB_Connection;
    QString username;


};

#endif // BALANCE_H

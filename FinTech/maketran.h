#ifndef MAKETRAN_H
#define MAKETRAN_H

#include <QDialog>
#include <QMainWindow>
#include <qtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class makeTran;
}

class makeTran : public QDialog
{
    Q_OBJECT

public:
    explicit makeTran(QWidget *parent = nullptr, const QString &username="", int userId = -1);
    ~makeTran();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::makeTran *ui;
    QString username;
    QSqlDatabase DB_Connection;
    int userId;

signals:
    void balanceUpdated();
};

#endif // MAKETRAN_H

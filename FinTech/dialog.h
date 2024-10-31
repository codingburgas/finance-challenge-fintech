#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <qtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:


    void on_regButton_clicked();

    void on_backToLogIn_clicked();

private:
    Ui::Dialog *ui;
     QSqlDatabase DB_Connection;
};

#endif // DIALOG_H

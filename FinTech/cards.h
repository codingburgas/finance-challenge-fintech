#ifndef CARDS_H
#define CARDS_H

#include <QDialog>
#include <QMainWindow>
#include <qtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QString>

namespace Ui {
class Cards;
}

class Cards : public QDialog
{
    Q_OBJECT

public:
    explicit Cards(QWidget *parent = nullptr, const QString &username="");
    ~Cards();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_logOutBut_clicked();

    void on_pushButton_5_clicked();

    void on_label_username_cards_linkActivated(const QString &link);

private:
    Ui::Cards *ui;
    QSqlDatabase DB_Connection;
    QString username;

};

#endif // CARDS_H

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>
#include "balance.h"

namespace Ui {
class Transactions;
}

class Transactions : public QDialog
{
    Q_OBJECT

public:
    explicit Transactions(QWidget *parent = nullptr);
    ~Transactions();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_logOutBut_2_clicked();

private:
    Ui::Transactions *ui;
};

#endif // TRANSACTIONS_H

#ifndef CARDS_H
#define CARDS_H

#include <QDialog>

namespace Ui {
class Cards;
}

class Cards : public QDialog
{
    Q_OBJECT

public:
    explicit Cards(QWidget *parent = nullptr);
    ~Cards();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_logOutBut_clicked();

private:
    Ui::Cards *ui;
};

#endif // CARDS_H

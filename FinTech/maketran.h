#ifndef MAKETRAN_H
#define MAKETRAN_H

#include <QDialog>

namespace Ui {
class makeTran;
}

class makeTran : public QDialog
{
    Q_OBJECT

public:
    explicit makeTran(QWidget *parent = nullptr, const QString &username="");
    ~makeTran();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::makeTran *ui;
    QString username;
};

#endif // MAKETRAN_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtSql>
#include <QtDebug>
#include <QFileInfo>
#include"secDiealog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:

    void on_registerButton_clicked();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Register *SecDiealog;
};



#endif // MAINWINDOW_H

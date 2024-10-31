#include "MainPage.h"
#include <QVBoxLayout>

MainPage::MainPage(QWidget *parent) : QWidget(parent)
{

    this->setStyleSheet("background-color: black;");


    label = new QLabel("LOGIN SUCCESS", this);
    label->setStyleSheet("color: white; font-size: 24px;");
    label->setAlignment(Qt::AlignCenter);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);


    setWindowTitle("Main Page");
    resize(400, 200);
}

MainPage::~MainPage()
{
    delete label;
}

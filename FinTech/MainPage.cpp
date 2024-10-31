#include "MainPage.h"
#include <QVBoxLayout>

MainPage::MainPage(QWidget *parent) : QWidget(parent)
{
    // Set window background color to black
    this->setStyleSheet("background-color: black;");

    // Create a QLabel to display "LOGIN SUCCESS" and set the text color to white
    label = new QLabel("LOGIN SUCCESS", this);
    label->setStyleSheet("color: white; font-size: 24px;");
    label->setAlignment(Qt::AlignCenter);

    // Use a vertical layout to center the label within the window
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);

    // Set window title and default size
    setWindowTitle("Main Page");
    resize(400, 200);
}

MainPage::~MainPage()
{
    delete label;
}

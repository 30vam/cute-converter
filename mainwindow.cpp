#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/lengthconverter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set the starting app size as default. You can use Design tab to change the window size manually.
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    //just for test, remove header ABSTRACT header if it's not needed anymore.
    LengthConverter *lengthConverter = new LengthConverter(this);
    ui->lengthScrollArea->setWidget(lengthConverter);

}

MainWindow::~MainWindow()
{
    delete ui;
}


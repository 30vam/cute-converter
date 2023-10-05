#include "mainwindow.h"
#include "abstractconverter.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set the starting app size as default. You can use Design tab to change the window size manually.
    //this->setFixedSize(this->geometry().width(), this->geometry().height());

    //just for test, remove header ABSTRACT header if it's not needed anymore.
    AbstractConverter *testConverter = new AbstractConverter(this);
    ui->conversionScrollArea->setWidget(testConverter);

}

MainWindow::~MainWindow()
{
    delete ui;
}


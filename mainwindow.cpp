#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSize>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //WIDGET MEMBERS

    //Set the starting app size as default. You can use Design tab to change the window size manually.
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    //scrollarea test
    QGroupBox *testGroupBox = new QGroupBox("Test box", this);
    testGroupBox->setFixedHeight(2000);
    ui->conversionScrollArea->setWidget(testGroupBox);

}

MainWindow::~MainWindow()
{
    delete ui;
}


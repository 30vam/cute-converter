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

    //Expand treeWidget on the left side by default
    ui->conversionTypeTreeWidget->expandAll();

    //Create my custom lengthConverter widget
    LengthConverter *lengthConverter = new LengthConverter(this);
    ui->lengthScrollArea->setWidget(lengthConverter);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//SLOTS ------------------------------------------------------------------

void MainWindow::on_conversionTypeTreeWidget_itemSelectionChanged()
{
    qDebug() << "keyboard";
    //For example: "Basic conversions" is an item, and "Length" is its child
    if(ui->conversionTypeTreeWidget->currentItem()->text(0) == ui->conversionTypeTreeWidget->itemAt(1, 0)->child(0)->text(0)) {
        ui->conversionStackedWidget->setCurrentIndex(0);
    }
    if(ui->conversionTypeTreeWidget->currentItem()->text(0) == ui->conversionTypeTreeWidget->itemAt(1, 0)->child(1)->text(0)) {
        ui->conversionStackedWidget->setCurrentIndex(1);
    }
}


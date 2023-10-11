#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/lengthconverter.h"
#include "src/areaconverter.h"
#include <QDebug>

//Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set app to fullscreen
    //this->showMaximized();

    //Set up tree widget
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0));  //Set the default page to the BASIC page
    ui->conversionTypeTreeWidget->expandAll(); //Expand the tree list when the program starts
    indexOfItemInParent = 0;
    indexOfParent = 0;

    //Create the custom converter widgets
    LengthConverter *lengthConverter = new LengthConverter(this);
    ui->lengthScrollArea->setWidget(lengthConverter);
    AreaConverter *areaConverter = new AreaConverter(this);
    ui->areaScrollArea->setWidget(areaConverter);

}

//Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}

//Methods -----------------------------------------------------------------


//SLOTS ------------------------------------------------------------------

//Setup Stacked Widget pag
//Using SelectionChanged slot instead of Clicked because it also works with keyboard
void MainWindow::on_conversionTypeTreeWidget_itemSelectionChanged()
{
    QList<QTreeWidgetItem*> selectedItems = ui->conversionTypeTreeWidget->selectedItems();
    foreach (QTreeWidgetItem *selectedItem, selectedItems) //There's only 1 selected item at a time in this case, but Qt still treats it as a list so I use a loop
    {
        if(selectedItem->text(0) == "Basic")
            ui->conversionStackedWidget->setCurrentIndex(0);
        else if(selectedItem->text(0) == "Length"){
            ui->conversionStackedWidget->setCurrentIndex(1);
        }
        else if(selectedItem->text(0) == "Area"){
            ui->conversionStackedWidget->setCurrentIndex(2);
        }
    }

}


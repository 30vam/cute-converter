#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/lengthconverter.h"
#include "src/areaconverter.h"
#include "src/volumeconverter.h"
#include "src/weightconverter.h"
#include "src/temperatureconverter.h"
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
    //ui->conversionTypeTreeWidget->expandAll(); //Expand the tree list when the program starts
    indexOfItemInParent = 0;
    indexOfParent = 0;

    //Connect QToolButtons to their corresponding converters
    ui->lengthToolButton->setDefaultAction(ui->switchToLengthAction);
    ui->areaToolButton->setDefaultAction(ui->switchToAreaAction);
    ui->volumeToolButton->setDefaultAction(ui->switchToVolumeAction);
    ui->weightToolButton->setDefaultAction(ui->switchToWeightAction);
    ui->temperatureToolButton->setDefaultAction(ui->switchToTemperatureAction);

    //Create the custom converter widgets
    LengthConverter *lengthConverter = new LengthConverter(this);
    ui->lengthScrollArea->setWidget(lengthConverter);
    AreaConverter *areaConverter = new AreaConverter(this);
    ui->areaScrollArea->setWidget(areaConverter);
    VolumeConverter *volumeConverter = new VolumeConverter(this);
    ui->volumeScrollArea->setWidget(volumeConverter);
    WeightConverter *weightConverter = new WeightConverter(this);
    ui->weightScrollArea->setWidget(weightConverter);
    TemperatureConverter *temperatureConverter = new TemperatureConverter(this);
    ui->temperatureScrollArea->setWidget(temperatureConverter);
}

//Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}

//Methods ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//SLOTS -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Setup Stacked Widget page
void MainWindow::on_conversionTypeTreeWidget_itemSelectionChanged()  //Using SelectionChanged slot instead of Clicked because it also works with keyboard
{
    QList<QTreeWidgetItem*> selectedItems = ui->conversionTypeTreeWidget->selectedItems();
    foreach (QTreeWidgetItem *selectedItem, selectedItems) //There's only 1 selected item at a time in this case, but Qt still treats it as a list so I use a loop
    {
        if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0))  //Basic page
            ui->conversionStackedWidget->setCurrentIndex(0);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0)->child(0))  //Length page
            ui->conversionStackedWidget->setCurrentIndex(1);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0)->child(1))  //Area page
            ui->conversionStackedWidget->setCurrentIndex(2);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0)->child(2))  //Volume page
            ui->conversionStackedWidget->setCurrentIndex(3);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0)->child(3))  //Weight/Mass page
            ui->conversionStackedWidget->setCurrentIndex(4);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0)->child(4))  //Temperature page
            ui->conversionStackedWidget->setCurrentIndex(5);
    }
}

//ACTIONS ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Toolbar actions for changing converters
void MainWindow::on_switchToLengthAction_triggered()  //LENGTH
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(0));
}

void MainWindow::on_switchToAreaAction_triggered()  //AREA
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(1));
}

void MainWindow::on_switchToVolumeAction_triggered()  //VOLUME
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(2));
}

void MainWindow::on_switchToWeightAction_triggered()
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(3));
}

void MainWindow::on_switchToTemperatureAction_triggered()
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(4));
}


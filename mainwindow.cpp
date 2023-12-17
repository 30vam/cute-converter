#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/lengthconverter.h"
#include "src/areaconverter.h"
#include "src/volumeconverter.h"
#include "src/weightconverter.h"
#include "src/temperatureconverter.h"
#include "src/timeconverter.h"
#include "src/speedconverter.h"
#include "src/pressureconverter.h"
#include "src/forceconverter.h"
#include "src/energyconverter.h"
#include "src/powerconverter.h"
#include "src/currentconverter.h"
#include "src/voltageconverter.h"
#include "src/torqueconverter.h"
#include "src/volumetricflowrateconverter.h"
#include "src/densityconverter.h"
#include "src/viscosityconverter.h"
#include "src/magneticfluxdensityconverter.h"
#include "src/concentrationconverter.h"

#include <QDebug>

//Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set app to fullscreen and icon
    this->showMaximized();

    //Set up tree widget
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0));  //Set the default page to the BASIC page
    //ui->conversionTypeTreeWidget->expandAll(); //Expand the tree list when the program starts
    indexOfItemInParent = 0;
    indexOfParent = 0;

    //Create about page
    aboutPage = new AboutDialog(this);

    //Connect QToolButtons from GENERAL pages(basic, scientific) to their corresponding converters
    ui->lengthToolButton->setDefaultAction(ui->switchToLengthAction);
    ui->areaToolButton->setDefaultAction(ui->switchToAreaAction);
    ui->volumeToolButton->setDefaultAction(ui->switchToVolumeAction);
    ui->weightToolButton->setDefaultAction(ui->switchToWeightAction);
    ui->temperatureToolButton->setDefaultAction(ui->switchToTemperatureAction);
    ui->timeToolButton->setDefaultAction(ui->switchToTimeAction);
    ui->speedToolButton->setDefaultAction(ui->switchToSpeedAction);
    ui->pressureToolButton->setDefaultAction(ui->switchToPressureAction);
    ui->forceToolButton->setDefaultAction(ui->switchToForceAction);
    ui->energyToolButton->setDefaultAction(ui->switchToEnergyAction);
    ui->powerToolButton->setDefaultAction(ui->switchToPowerAction);
    ui->currentToolButton->setDefaultAction(ui->switchToCurrentAction);
    ui->voltageToolButton->setDefaultAction(ui->switchToVoltageAction);
    ui->torqueToolButton->setDefaultAction(ui->switchToTorqueAction);
    ui->volumetricFlowRateToolButton->setDefaultAction(ui->switchToVolumetricFlowRateAction);
    ui->densityToolButton->setDefaultAction(ui->switchToDensityAction);
    ui->viscosityToolButton->setDefaultAction(ui->switchToViscosityAction);
    ui->magneticFluxDensityToolButton->setDefaultAction(ui->switchToMagneticFluxDensityAction);
    ui->concentrationToolButton->setDefaultAction(ui->switchToConcentrationAction);

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
    TimeConverter *timeConverter = new TimeConverter(this);
    ui->timeScrollArea->setWidget(timeConverter);
    SpeedConverter *speedConverter = new SpeedConverter(this);
    ui->speedScrollArea->setWidget(speedConverter);
    PressureConverter *pressureConverter = new PressureConverter(this);
    ui->pressureScrollArea->setWidget(pressureConverter);
    ForceConverter *forceConverter = new ForceConverter(this);
    ui->forceScrollArea->setWidget(forceConverter);
    EnergyConverter *energyConverter = new EnergyConverter(this);
    ui->energyScrollArea->setWidget(energyConverter);
    PowerConverter *powerConverter = new PowerConverter(this);
    ui->powerScrollArea->setWidget(powerConverter);
    CurrentConverter *currentConverter = new CurrentConverter(this);
    ui->currentScrollArea->setWidget(currentConverter);
    VoltageConverter *voltageConverter = new VoltageConverter(this);
    ui->voltageScrollArea->setWidget(voltageConverter);
    TorqueConverter *torqueConverter = new TorqueConverter(this);
    ui->torqueScrollArea->setWidget(torqueConverter);
    VolumetricFlowRateConverter *volumetricFlowRateConverter = new VolumetricFlowRateConverter(this);
    ui->volumetricFlowRateScrollArea->setWidget(volumetricFlowRateConverter);
    DensityConverter *densityConverter = new DensityConverter(this);
    ui->densityScrollArea->setWidget(densityConverter);
    ViscosityConverter *viscosityConverter = new ViscosityConverter(this);
    ui->viscosityScrollArea->setWidget(viscosityConverter);
    MagneticFluxDensityConverter *magneticFluxDensityConverter = new MagneticFluxDensityConverter(this);
    ui->magneticFluxDensityScrollArea->setWidget(magneticFluxDensityConverter);
    ConcentrationConverter *concentrationConverter = new ConcentrationConverter(this);
    ui->concentrationScrollArea->setWidget(concentrationConverter);
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
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0)->child(5))  //Time page
            ui->conversionStackedWidget->setCurrentIndex(6);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0)->child(6))  //Speed page
            ui->conversionStackedWidget->setCurrentIndex(7);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1))  //Scientific page
            ui->conversionStackedWidget->setCurrentIndex(8);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(0))  //Pressure page
            ui->conversionStackedWidget->setCurrentIndex(9);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(1))  //Force page
            ui->conversionStackedWidget->setCurrentIndex(10);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(2))  //Energy page
            ui->conversionStackedWidget->setCurrentIndex(11);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(3))  //Power page
            ui->conversionStackedWidget->setCurrentIndex(12);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(4))  //Current page
            ui->conversionStackedWidget->setCurrentIndex(13);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(5))  //Voltage page
            ui->conversionStackedWidget->setCurrentIndex(14);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(6))  //Torque page
            ui->conversionStackedWidget->setCurrentIndex(15);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(7))  //Volumetric Flow Rate page
            ui->conversionStackedWidget->setCurrentIndex(16);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(8))  //Density page
            ui->conversionStackedWidget->setCurrentIndex(17);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(9))  //Viscosity page
            ui->conversionStackedWidget->setCurrentIndex(18);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(10))  //Magnetic Flux Density page
            ui->conversionStackedWidget->setCurrentIndex(19);
        else if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1)->child(11))  //Concentration page
            ui->conversionStackedWidget->setCurrentIndex(20);
    }
}

//ACTIONS ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Credit window
void MainWindow::on_aboutAction_triggered()
{
    aboutPage->exec();
}

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

void MainWindow::on_switchToWeightAction_triggered()  //WEIGHT
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(3));
}

void MainWindow::on_switchToTemperatureAction_triggered()  //TEMPERATURE
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(4));
}

void MainWindow::on_switchToTimeAction_triggered()  //TIME
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(5));
}

void MainWindow::on_switchToSpeedAction_triggered()  //SPEED
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(0)->child(6));
}

void MainWindow::on_switchToPressureAction_triggered()  //PRESSURE
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(0));
}

void MainWindow::on_switchToForceAction_triggered()  //FORCE
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(1));
}

void MainWindow::on_switchToEnergyAction_triggered()  //ENERGY
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(2));
}

void MainWindow::on_switchToPowerAction_triggered()  //POWER
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(3));
}

void MainWindow::on_switchToCurrentAction_triggered()  //CURRENT
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(4));
}

void MainWindow::on_switchToVoltageAction_triggered()  //VOLTAGE
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(5));
}

void MainWindow::on_switchToTorqueAction_triggered()  //TORQUE
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(6));
}

void MainWindow::on_switchToVolumetricFlowRateAction_triggered()   //VOLUMETRIC FLOW RATE
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(7));
}

void MainWindow::on_switchToDensityAction_triggered()  //DENSITY
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(8));
}

void MainWindow::on_switchToViscosityAction_triggered()  //VESCOSITY
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(9));
}

void MainWindow::on_switchToMagneticFluxDensityAction_triggered()  //MAGNETIC FLUX DENSITY
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(10));
}

void MainWindow::on_switchToConcentrationAction_triggered()  //CONCENTRATION
{
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(1)->child(11));
}


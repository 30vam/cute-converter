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
#include "src/angleconverter.h"
#include "src/datastorageconverter.h"
#include "src/fuelconsumptionconverter.h"

#include <QDebug>

//Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup variables
    m_basicPageIndex = 0;
    m_scientificPageIndex = 1;
    m_miscPageIndex = 2;

    //Set app to fullscreen and icon
    this->showMaximized();

    //Set up tree widget
    ui->conversionTypeTreeWidget->setCurrentItem(ui->conversionTypeTreeWidget->topLevelItem(m_basicPageIndex));  //Set the default page to the BASIC page
    //ui->conversionTypeTreeWidget->expandAll(); //Expand the tree list when the program starts

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
    ui->angleToolButton->setDefaultAction(ui->switchToAngleAction);
    ui->dataStorageToolButton->setDefaultAction(ui->switchToDataStorageAction);
    ui->fuelConsumptionToolButton->setDefaultAction(ui->switchToFuelConsumptionAction);

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
    AngleConverter *angleConverter = new AngleConverter(this);
    ui->angleScrollArea->setWidget(angleConverter);
    DataStorageConverter *dataStorageConverter = new DataStorageConverter(this);
    ui->dataStorageScrollArea->setWidget(dataStorageConverter);
    FuelConsumptionConverter *fuelConsumptionConverter = new FuelConsumptionConverter(this);
    ui->fuelConsumptionScrollArea->setWidget(fuelConsumptionConverter);
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
    int widgetIndex = 0;
    int treeParentCount = ui->conversionTypeTreeWidget->topLevelItemCount();
    int firstTreeChildCount = ui->conversionTypeTreeWidget->topLevelItem(0)->childCount();
    int secondTreeChildCount = ui->conversionTypeTreeWidget->topLevelItem(1)->childCount();
    QList<QTreeWidgetItem*> selectedItems = ui->conversionTypeTreeWidget->selectedItems();

    foreach (QTreeWidgetItem *selectedItem, selectedItems) //There's only 1 selected item at a time in this case, but Qt still treats it as a list so I use a loop
    {
        if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(0))  //if it's the 1st tree HEADER
            widgetIndex = 0;
        else  if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(1))  //if it's the 2nd tree HEADER
            widgetIndex = firstTreeChildCount + 1;
        else  if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(2))  //if it's the 3nd tree HEADER
            widgetIndex = secondTreeChildCount + firstTreeChildCount + 2;

        else  //Otherwise if the item is child of a tree:
        {
            for (int currentTreeIndex = 0; currentTreeIndex < treeParentCount; currentTreeIndex++)  //loop through HEADERS (basic, scientific, etc.)
            {
                if(selectedItem->parent() == ui->conversionTypeTreeWidget->topLevelItem(currentTreeIndex))  //If we're in the selected item's parent:
                {
                    for (int currentChildIndex = 0; currentChildIndex < selectedItem->parent()->childCount(); currentChildIndex++)  //loop through children of i (int j)
                    {
                        if(selectedItem == ui->conversionTypeTreeWidget->topLevelItem(currentTreeIndex)->child(currentChildIndex))  //If we're in the correct child:
                        {
                            widgetIndex = currentChildIndex + 1;   //if we are in the 1st tree

                            if(currentTreeIndex >= 1)  //if we are in any other tree..... add the previous children counts to widgetIndex
                            {
                                for(int i = 0; i < currentTreeIndex; i++)
                                    widgetIndex += ui->conversionTypeTreeWidget->topLevelItem(i)->childCount() + 1;
                            }
                        }
                    }
                }
            }
        }

        qDebug() << widgetIndex;
        ui->conversionStackedWidget->setCurrentIndex(widgetIndex);  //Finally, set the widget page to the correct one...(hopefully)
    }
}

//ACTIONS ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Toolbar
void MainWindow::on_aboutAction_triggered()  //ABOUT
{
    aboutPage->exec();
}

void MainWindow::on_searchAction_triggered()  //SEARCH
{

}

void MainWindow::on_favoriteAction_triggered()  //FAVORITE
{

}

//Actions for switching converters
void MainWindow::on_switchToLengthAction_triggered()  //LENGTH
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("length", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToAreaAction_triggered()  //AREA
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("area", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToVolumeAction_triggered()  //VOLUME
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("volume", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToWeightAction_triggered()  //WEIGHT
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("weight", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToTemperatureAction_triggered()  //TEMPERATURE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("temperature", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToTimeAction_triggered()  //TIME
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("time", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToSpeedAction_triggered()  //SPEED
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("speed", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToPressureAction_triggered()  //PRESSURE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("pressure", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToForceAction_triggered()  //FORCE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("force", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToEnergyAction_triggered()  //ENERGY
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("energy", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToPowerAction_triggered()  //POWER
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("power", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToCurrentAction_triggered()  //CURRENT
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("current", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToVoltageAction_triggered()  //VOLTAGE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("voltage", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToTorqueAction_triggered()  //TORQUE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("torque", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToVolumetricFlowRateAction_triggered()   //VOLUMETRIC FLOW RATE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("volumetric flow rate", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToDensityAction_triggered()  //DENSITY
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("density", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToViscosityAction_triggered()  //VISCOSITY
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("viscosity", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToMagneticFluxDensityAction_triggered()  //MAGNETIC FLUX DENSITY
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("magnetic flux density", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToConcentrationAction_triggered()  //CONCENTRATION
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("concentration", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToAngleAction_triggered()  //ANGLE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("angle", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToDataStorageAction_triggered()  //DATA STORAGE
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("data storage", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}

void MainWindow::on_switchToFuelConsumptionAction_triggered()  //FUEL CONSUMPTION
{
    QList<QTreeWidgetItem *> searchList = ui->conversionTypeTreeWidget->findItems("fuel consumption", Qt::MatchContains | Qt::MatchRecursive);
    ui->conversionTypeTreeWidget->setCurrentItem(searchList[0]);
}


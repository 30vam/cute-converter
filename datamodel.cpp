#include "datamodel.h"

DataModel::DataModel(QObject *parent)
    : QObject{parent}
{
    m_model = new QStandardItemModel();

    //Generate the model
    QStandardItem *basicItem = new QStandardItem("Basic");
    basicItem->setEditable(false);
    QStandardItem *lengthItem = new QStandardItem("Length");
    QStandardItem *areaItem = new QStandardItem("Area");
    QStandardItem *volumeItem = new QStandardItem("Volume");
    QStandardItem *WeightItem = new QStandardItem("Weight");
    QStandardItem *temperatureItem = new QStandardItem("Temperature");
    QStandardItem *timeItem = new QStandardItem("Time");
    QStandardItem *speedItem = new QStandardItem("Speed");
    QStandardItem *pressureItem = new QStandardItem("Pressure");
    QStandardItem *forceItem = new QStandardItem("Force");
    QStandardItem *energyItem = new QStandardItem("Energy");
    QStandardItem *powerItem = new QStandardItem("Power");
    QStandardItem *currentItem = new QStandardItem("Current");
    QStandardItem *voltageItem = new QStandardItem("Voltage");
    QStandardItem *TorqueItem = new QStandardItem("Torque");
    QStandardItem *volumetricFlowRateItem = new QStandardItem("Volumetric Flow Rate");
    QStandardItem *densityItem = new QStandardItem("Density");
    QStandardItem *viscosityItem = new QStandardItem("Viscosity");
    QStandardItem *MagneticFluxDensityItem = new QStandardItem("Magnetic Flux Density");
    QStandardItem *concentrationItem = new QStandardItem("Concentration");
    QStandardItem *miscItem = new QStandardItem("Misc");
    QStandardItem *angleItem = new QStandardItem("Angle");
    QStandardItem *dataStorageItem = new QStandardItem("Data Storage");
    QStandardItem *fuelConsumptionItem = new QStandardItem("Fuel Consumption");
    QStandardItem *luminanceItem = new QStandardItem("Luminance");

    m_model->appendRow(basicItem);

    //Signals and slots
    connect(m_model, &QStandardItemModel::dataChanged, this, &DataModel::modelDataChanged);
}

//Getters and setters
QStandardItemModel *DataModel::getModel()
{
    return m_model;
}

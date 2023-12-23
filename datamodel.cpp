#include "datamodel.h"

DataModel::DataModel(QObject *parent)
    : QObject{parent}
{
    //Variables
    m_model = new QStandardItemModel();
    m_itemFont = QFont("Aleo", 12, QFont::Bold);

    //Generate the Items
    QStandardItem *basicItem = new QStandardItem("Basic");
    QStandardItem *lengthItem = new QStandardItem("Length");
    QStandardItem *areaItem = new QStandardItem("Area");
    QStandardItem *volumeItem = new QStandardItem("Volume");
    QStandardItem *weightItem = new QStandardItem("Weight");
    QStandardItem *temperatureItem = new QStandardItem("Temperature");
    QStandardItem *timeItem = new QStandardItem("Time");
    QStandardItem *speedItem = new QStandardItem("Speed");
    QStandardItem *scientificItem = new QStandardItem("Scientific");
    QStandardItem *pressureItem = new QStandardItem("Pressure");
    QStandardItem *forceItem = new QStandardItem("Force");
    QStandardItem *energyItem = new QStandardItem("Energy");
    QStandardItem *powerItem = new QStandardItem("Power");
    QStandardItem *currentItem = new QStandardItem("Current");
    QStandardItem *voltageItem = new QStandardItem("Voltage");
    QStandardItem *torqueItem = new QStandardItem("Torque");
    QStandardItem *volumetricFlowRateItem = new QStandardItem("Volumetric Flow Rate");
    QStandardItem *densityItem = new QStandardItem("Density");
    QStandardItem *viscosityItem = new QStandardItem("Viscosity");
    QStandardItem *magneticFluxDensityItem = new QStandardItem("Magnetic Flux Density");
    QStandardItem *concentrationItem = new QStandardItem("Concentration");
    QStandardItem *miscItem = new QStandardItem("Misc");
    QStandardItem *angleItem = new QStandardItem("Angle");
    QStandardItem *dataStorageItem = new QStandardItem("Data Storage");
    QStandardItem *fuelConsumptionItem = new QStandardItem("Fuel Consumption");
    QStandardItem *luminanceItem = new QStandardItem("Luminance");

    //Add the items to the model:
    m_model->appendRow(basicItem);
    m_model->appendRow(lengthItem);
    m_model->appendRow(areaItem);
    m_model->appendRow(volumeItem);
    m_model->appendRow(weightItem);
    m_model->appendRow(temperatureItem);
    m_model->appendRow(timeItem);
    m_model->appendRow(speedItem);
    m_model->appendRow(scientificItem);
    m_model->appendRow(pressureItem);
    m_model->appendRow(forceItem);
    m_model->appendRow(energyItem);
    m_model->appendRow(powerItem);
    m_model->appendRow(currentItem);
    m_model->appendRow(voltageItem);
    m_model->appendRow(torqueItem);
    m_model->appendRow(volumetricFlowRateItem);
    m_model->appendRow(densityItem);
    m_model->appendRow(viscosityItem);
    m_model->appendRow(magneticFluxDensityItem);
    m_model->appendRow(concentrationItem);
    m_model->appendRow(miscItem);
    m_model->appendRow(angleItem);
    m_model->appendRow(dataStorageItem);
    m_model->appendRow(fuelConsumptionItem);
    m_model->appendRow(luminanceItem);

    //Iterate throught the items for modifying and giving data to each item etc.
    for (int row = 0; row < m_model->rowCount(); row++)
    {
        for (int column = 0; column < m_model->columnCount(); column++)
        {
            QStandardItem *currentItem = m_model->item(row, column);  //Which item are we iterating through right now?
            currentItem->setFont(m_itemFont);
            currentItem->setEditable(false);  //Remove item editting ability from use
            currentItem->setData(row, Qt::UserRole);  //Give an index to the item
        }
    }

    //Signals and slots
    connect(m_model, &QStandardItemModel::dataChanged, this, &DataModel::modelDataChanged);
}

//Getters and setters
QStandardItemModel *DataModel::getModel()
{
    return m_model;
}

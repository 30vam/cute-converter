#include "datamodel.h"

DataModel::DataModel(QObject *parent)
    : QStandardItemModel{parent}
{
    //Variables
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
    appendRow(basicItem);
    appendRow(lengthItem);
    appendRow(areaItem);
    appendRow(volumeItem);
    appendRow(weightItem);
    appendRow(temperatureItem);
    appendRow(timeItem);
    appendRow(speedItem);
    appendRow(scientificItem);
    appendRow(pressureItem);
    appendRow(forceItem);
    appendRow(energyItem);
    appendRow(powerItem);
    appendRow(currentItem);
    appendRow(voltageItem);
    appendRow(torqueItem);
    appendRow(volumetricFlowRateItem);
    appendRow(densityItem);
    appendRow(viscosityItem);
    appendRow(magneticFluxDensityItem);
    appendRow(concentrationItem);
    appendRow(miscItem);
    appendRow(angleItem);
    appendRow(dataStorageItem);
    appendRow(fuelConsumptionItem);
    appendRow(luminanceItem);

    //Iterate throught the items for setting font etc.
    for (int row = 0; row < this->rowCount(); row++)
    {
        QStandardItem *currentItem = this->item(row, 0);  //Which item are we iterating through right now?
        currentItem->setFont(m_itemFont);
        currentItem->setEditable(false);  //Remove item editting ability from user
    }
}

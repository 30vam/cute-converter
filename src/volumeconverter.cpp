#include "volumeconverter.h"

VolumeConverter::VolumeConverter(QWidget *parent)
    : AbstractConverter({ {"ml(cc)/milliliter", 1000000}, {"cl/centiliter", 100000}, {"L/liter", 1000},
                        {"mm³/millimeter³", 1e+9}, {"cm³/centimeter³", 1000000}, {"dm³/decimeter³", 1000}, {"m³/meter³", 1},
                        {"km³/kilometer³", 1e-9}, {"Mm³/megameter³", 1e-18}, {"in³/inch³", 61023.7}, {"ft³/foot³", 35.3147},
                        {"yd³/yard³", 1.30795}, {"mi³/mile³", 2.39913e-10}, {"teaspoon(US)", 202884}, {"teaspoon(UK)", 168936},
                        {"tablespoon(US)", 67628}, {"tablespoon(UK)", 56312.1}, {"cup(US)", 4226.75}, {"cup(UK)", 3519.51},
                        {"fluid ounces(US)", 33814}, {"fluid ounces(UK)", 35195.08},
                        {"gill(US)", 8453.51}, {"gill(UK)", 7039.016}, {"pint(US)", 2113.376}, {"pint(UK)", 1759.754},
                        {"gallon(US)", 264.172}, {"gallon(UK)", 219.969} }, "Volume", parent)
{

}

void VolumeConverter::convertValues(int unitIndex, QString valueString)
{
    //If the input LineEdit is cleared, clear other LineEdits as well
    if(valueString.isEmpty() || valueString.endsWith("e", Qt::CaseInsensitive))
    {
        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            if (i != unitIndex) //dont change the selected lineEdit
                m_lineEditList.at(i)->setText("");
        }
    }
    //Otherwise convert values
    else
    {
        double inputDouble = valueString.toDouble();
        double toCubicMeterCoefficient = m_unitList.at(unitIndex).second;
        double inputToCubicMeter = inputDouble / toCubicMeterCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToCubicMeter * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

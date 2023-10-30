#include "volumeconverter.h"

VolumeConverter::VolumeConverter(QWidget *parent)
    : AbstractConverter({ {"ml(cc)/milliliter", 1000000}, {"cl/centiliter", 100000}, {"L/liter", 1000},
                        {"mm³/cubic millimeter", 1e+9}, {"cm³/cubic centimeter", 1000000}, {"dm³/cubic decimeter", 1000}, {"m³/cubic meter", 1},
                        {"km³/cubic kilometer", 1e-9}, {"Mm³/cubic megameter", 1e-18}, {"in³/cubic inch", 61023.7}, {"ft³/cubic foot", 35.3147},
                        {"yd³/cubic yard", 1.30795}, {"mi³/cubic mile", 2.39913e-10}, {"teaspoon(US)", 202884}, {"teaspoon(Imperial)", 168936},
                        {"tablespoon(US)", 67628}, {"tablespoon(Imperial)", 56312.1}, {"cup(US)", 4226.75}, {"cup(Imperial)", 3519.51},
                        {"fluid ounces(US)", 33814}, {"fluid ounces(Imperial)", 35195.08},
                        {"gill(US)", 8453.51}, {"gill(Imperial)", 7039.016}, {"pint(US)", 2113.376}, {"pint(Imperial)", 1759.754},
                        {"gallon(US)", 264.172}, {"gallon(Imperial)", 219.969} }, "Volume", parent)
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

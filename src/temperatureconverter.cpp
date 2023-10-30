#include "temperatureconverter.h"

TemperatureConverter::TemperatureConverter(QWidget *parent)
    : AbstractConverter({ {"fm/femtometer", 1e+15}, {"pm/picometer", 1e+12}, {"Å/angstrom", 1e+10}, {"nm/nanometer", 1e+9}, {"μm/micrometer", 1000000},
                        {"mm/millimeter", 1000}, {"cm/centimeter", 100}, {"dm/decimeter", 10}, {"m/meter", 1}, {"dam/decameter", 0.1},
                        {"hm/hectometer", 0.01}, {"km/kilometer", 0.001}, {"Mm/megameter", 0.000001}, {"Gm/gigameter", 1e-9},
                        {"Tm/terameter", 1e-12}, {"Pm/petameter", 1e-15}, {"ly/light-year", 1.057e-16}, {"pc/parsec", 3.24078e-17},
                        {"in/inch", 39.3701}, {"ft/foot", 3.281}, {"yd/yard", 1.094},
                        {"mi/mile", 0.000621}, {"league", 0.0002071} } , "Temperature", parent)
{

}

void TemperatureConverter::convertValues(int unitIndex, QString valueString)
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

    //Otherwise convert value from meter to each unit INDIVIDUALLY
    else
    {
        double inputDouble = valueString.toDouble();
        double toMeterCoefficient = m_unitList.at(unitIndex).second;
        double inputToMeter = inputDouble / toMeterCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToMeter * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

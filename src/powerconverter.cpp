#include "powerconverter.h"

PowerConverter::PowerConverter(QWidget *parent)
    : AbstractConverter({ {"mw (milliwatt)", 1000}, {"W (watt)", 1}, {"kW (kilowatt)", 0.001}, {"MW (megawatt)", 0.000001}, {"GW (gigawatt)", 1e-9},
                        {"kcal/s (kcalorie/second)", 0.000239}, {"kcal/h (kcalorie/hour)", 0.8598452279}, {"HP (horsepower)", 0.00134102},
                        {"BTU/h (British Thermal Unit/h)", 3.4121416331}, {"TR (ton of refrigeration)", 0.000284345} },
                        "Power", parent)
{

}

void PowerConverter::convertValues(int unitIndex, QString valueString)
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
        double toWattCoefficient = m_unitList.at(unitIndex).second;
        double inputToWatte = inputDouble / toWattCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToWatte * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

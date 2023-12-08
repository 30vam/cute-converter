#include "pressureconverter.h"

PressureConverter::PressureConverter(QWidget *parent)
    : AbstractConverter({ {"Pa(Pascal)", 1}, {"m/min(meter per minute)", 60}, {"km/s", 0.001}, {"km/min", 0.06}, {"km/h(kilometer per hour)", 3.6},
                         {"ft/s(foot per second)", 3.281}, {"ft/min(foot per minute)", 196.85}, {"mi/h(mile per hour)", 2.237}, {"mach", 0.00291545}, {"knot", 1.944} },
                        "Pressure", parent)
{

}

void PressureConverter::convertValues(int unitIndex, QString valueString)
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
        double toPascalCoefficient = m_unitList.at(unitIndex).second;
        double inputToPascal = inputDouble / toPascalCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToPascal * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}


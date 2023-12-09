#include "speedconverter.h"

SpeedConverter::SpeedConverter(QWidget *parent)
    : AbstractConverter({ {"m/s (meter/second)", 1}, {"m/min (meter/minute)", 60}, {"km/s (kmeter/sec)", 0.001}, {"km/min (kmeter/minute)", 0.06}, {"km/h (kmeter/hour)", 3.6},
                        {"ft/s (foot/second)", 3.281}, {"ft/min (foot/minute)", 196.85}, {"mi/h (mile/hour)", 2.237}, {"mach", 0.00291545}, {"knot", 1.944} },
                        "Speed", parent)
{

}

void SpeedConverter::convertValues(int unitIndex, QString valueString)
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
        double toMpSCoefficient = m_unitList.at(unitIndex).second;
        double inputToMpS = inputDouble / toMpSCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToMpS * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

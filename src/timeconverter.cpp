#include "timeconverter.h"

TimeConverter::TimeConverter(QWidget *parent)
    : AbstractConverter({ {"ml(cc)/milliliter", 1000000}, {"cl/centiliter", 100000}, {"L/liter", 1000},
                        {"mm³/cubic millimeter", 1e+9}, {"cm³/cubic centimeter", 1000000}, {"dm³/cubic decimeter", 1000}, {"m³/cubic meter", 1},
                        {"gallon(US)", 264.172}, {"gallon(Imperial)", 219.969} }, "Time", parent)
{

}

void TimeConverter::convertValues(int unitIndex, QString valueString)
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
        double toSecondCoefficient = m_unitList.at(unitIndex).second;
        double inputToSecond = inputDouble / toSecondCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToSecond * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

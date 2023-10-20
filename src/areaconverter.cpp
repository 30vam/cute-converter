#include "areaconverter.h"

AreaConverter::AreaConverter(QWidget *parent)
    : AbstractConverter({ {"pm²/square picometer", 1e+24}, {"nm²/square nanometer", 1e+18}, {"μm²/square micrometer", 1e+12},
                        {"mm²/square millimeter", 1000000}, {"cm²/square centimeter", 10000}, {"dm²/square decimeter", 100}, {"m²/square meter", 1},
                        {"a/are", 0.01}, {"ha/hectar", 0.0001}, {"ac/acre", 0.000247}, {"km²/square kilometer", 0.000001}, {"in²/square inch", 1550.0031},
                        {"ft²/square foot", 10.76391}, {"yd²/square yard", 1.19599}, {"mi²/square mile", 3.861e-7}}, "Area", parent)
{

}

void AreaConverter::convertValues(int unitIndex, QString valueString)
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
        double toSquareMeterCoefficient = m_unitList.at(unitIndex).second;
        double inputToMeter = inputDouble / toSquareMeterCoefficient;

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


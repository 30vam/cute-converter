#include "areaconverter.h"

AreaConverter::AreaConverter(QWidget *parent)
    : AbstractConverter({ {"pm²/picometer²", 1e+24}, {"nm²/nanometer²", 1e+18}, {"μm²/micrometer²", 1e+12},
                        {"mm²/millimeter²", 1000000}, {"cm²/centimeter²", 10000}, {"dm²/decimeter²", 100}, {"m²/meter²", 1},
                        {"a/are", 0.01}, {"ha/hectar", 0.0001}, {"ac/acre", 0.000247}, {"km²/kilometer²", 0.000001}, {"in²/inch²", 1550.0031},
                        {"ft²/foot²", 10.76391}, {"yd²/yard²", 1.19599}, {"mi²/mile²", 3.861e-7}}, "Area", parent)
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
    //Otherwise convert values
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


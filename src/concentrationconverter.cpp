#include "concentrationconverter.h"

ConcentrationConverter::ConcentrationConverter(QWidget *parent)
    : AbstractConverter({{"kg/L (kilogram per liter)", 1}, {"g/L (gram per liter)", 1000}, {"mg/L (milligram per liter)", 1000000},
                        {"ppm (part per million)", 1001142.303}, {"gr/gal (US) (grain/gallon (US))", 58417.8306}, {"gr/gal (UK) (grain/gallon (UK))", 70156.88929},
                        {"pound per gallon (US)", 8.345404374}, {"pound per gallon (UK)", 10.02241276}, {"pound per million gallon (US)", 8345404.374},
                        {"pound per million gallon (US)", 10022412.76}, {"lb/ft³ (pound per cubic foot)", 62.42796} },
                        "Concentration", parent)
{

}

void ConcentrationConverter::convertValues(int unitIndex, QString valueString)
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
        double toMolePerCubicMeterCoefficient = m_unitList.at(unitIndex).second;
        double inputToMolePerCubicMeter = inputDouble / toMolePerCubicMeterCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToMolePerCubicMeter * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

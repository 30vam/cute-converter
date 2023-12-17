#include "concentrationconverter.h"

ConcentrationConverter::ConcentrationConverter(QWidget *parent)
    : AbstractConverter({{"N.m (newton-meter)", 1}, {"daN.m (dekanewton-meter)", 0.1}, {"kN.m (kilonewton-meter)", 0.001},
                        {"kgf.m (kilogram-force meter)", 0.1019716213}, {"ozfin (ounceforce-inch)", 141.611933},
                        {"lbf.in (poundforce-inch)", 8.850746}, {"lbf.ft (poundforce-foot)", 0.737562},  {"gf.cm (gramforce-centimeter)", 10197.1621}, },
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

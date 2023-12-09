#include "powerconverter.h"

PowerConverter::PowerConverter(QWidget *parent)
    : AbstractConverter({ {"W (watt)", 1}, {"kJ (kilojoule)", 0.001}, {"cal (calorie)", 0.239006}, {"kcal (kilocalorie)", 0.000239006}, {"kW.h (kilowatt hour)", 2.77778e-7},
                        {"kgf.m (kg-force meter)", 0.1019716213}, {"in.lbf (inch-pound)", 8.8507457916}, {"ft.lbf (foot-pound)", 0.737562},
                        {"BTU (British Thermal Unit)", 0.000947817}, {"eV (electronvolt)", 6.242e+18}},
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

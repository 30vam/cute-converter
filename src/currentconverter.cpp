#include "currentconverter.h"

CurrentConverter::CurrentConverter(QWidget *parent)
    : AbstractConverter({{"mA (milliampere)", 1000}, {"A (ampere)", 1}, {"kA (kiloampere)", 0.001}, {"MA (megaampere)", 1e-6}, {"GA (gigaampere)", 1e-9},
                        {"Bi (biot)", 0.1}, {"EMU of current", 0.1}, {"ESU of current", 2997924536.8},  {"abA (abampere)", 0.1}, {"stA (statampere)", 2997924536.8},
                        {"CGS e.m.", 0.1}, {"CGS e.s.", 2997924536.8} },
                        "Current", parent)
{

}

void CurrentConverter::convertValues(int unitIndex, QString valueString)
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
        double toAmpereCoefficient = m_unitList.at(unitIndex).second;
        double inputToAmpere = inputDouble / toAmpereCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToAmpere * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

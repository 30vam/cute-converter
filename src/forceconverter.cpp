#include "forceconverter.h"

ForceConverter::ForceConverter(QWidget *parent)
    : AbstractConverter({ {"dyn(dyne)", 100000}, {"N(newton)", 1}, {"daN(dekaNewton)", 0.1}, {"kN(kiloNewton)", 0.001}, {"kgf(kilogram-force)", 0.101972},
                        {"ibf(pound-force)", 0.224809}, {"pdl(poundal)", 7.23301}, {"kip(kip-force)", 0.0002248089}, },
                        "Force", parent)
{

}

void ForceConverter::convertValues(int unitIndex, QString valueString)
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
        double toNewtonCoefficient = m_unitList.at(unitIndex).second;
        double inputToNewton = inputDouble / toNewtonCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToNewton * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

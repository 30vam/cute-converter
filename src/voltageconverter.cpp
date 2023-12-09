#include "voltageconverter.h"

VoltageConverter::VoltageConverter(QWidget *parent)
    : AbstractConverter({{"mV (millivolt)", 1000}, {"V (volt)", 1}, {"kV (kilovolt)", 0.001},  {"MV (megavolt)", 1e-6}, {"GV (gigavolt)", 1e-9},
                        {"EMU of electric potential", 100000000}, {"ESU of electric potential", 0.0033356405},  {"abV (abvolt)", 100000000},
                        {"stV (statVolt)", 0.0033356405}, },
                        "Voltage", parent)
{

}

void VoltageConverter::convertValues(int unitIndex, QString valueString)
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
        double toVoltCoefficient = m_unitList.at(unitIndex).second;
        double inputToVolt = inputDouble / toVoltCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToVolt * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

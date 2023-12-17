#include "densityconverter.h"

DensityConverter::DensityConverter(QWidget *parent)
    : AbstractConverter({{"kg/m³ (kilogram per cubic meter)", 1}, {"g/cm³ (gram per cubic centimeter)", 0.001}, {"kg/cm³ (kilogram per cubic centimeter)", 0.000001},
                        {"g/m³ (gram per cubic meter)", 1000}, {"g/mm³ (gram/cubic millimeter)", 0.000001}, {"mg/m³ (milligram per cubic meter)", 1000000},
                        {"mg/cm³ (milligram per cubic centimeter)", 1}, {"mg/mm³ (milligram per cubic millimeter)", 0.001}, {"Eg/L (exagram per liter)", 9.999999999e-19},
                        {"Pg/L (petagram per liter)", 1.e-15}, {"Tg/L (teragram per liter)", 1.E-12}, {"Gg/L (gigagram per liter)", 1.e-9},
                        {"Mg/L (megagram per liter)", 0.000001}, {"kg/L (kilogram per liter)", 0.001}, {"hg/L (hectogram per liter)", 0.01},
                        {"dag/L (dekagram per liter)", 0.1}, {"g/L (gram per cubic liter)", 1}, {"dg/L (decigram per liter)", 10},
                        {"cg/L (centigram per liter)", 100}, {"mg/L (milligram per liter)", 1000}, {"µg/L(microgram per liter)", 1000000},
                        {"ng/L (nanogram per liter)", 1000000000}, {"pg/L (picogram perliter)", 1000000000000}, {"fg/L (femtogram per liter)", 1000000000000000},
                        {"ag/L (attogram per liter)", 999999999999999900}, {"lb/in³ (pound per cubic inch)", 0.0000361273}, {"lb/ft³ (pound per cubic foot)", 0.0624279606},
                        {"lb/yd³ (pound per cubic yard)", 1.6855549356}, {"pound/gallon (US)", 0.0083454045}, {"pound/gallon (UK)", 0.0100224129},
                        {"oz/in³ (ounce per cubic inch)", 0.0005780367}, {"oz/ft³ (ounce per cubic foot)", 0.9988473692}, {"ounce/gallon (US)", 0.1335264712},
                        {"ounce/gallon (UK)", 0.1603586057}, {"grain/gallon (US)", 58.417831164}, {"grain/gallon (UK)", 70.156889985},
                        {"gr/ft³ (grain per cubic foot)", 436.99572403}, {"ton (short)/cubic yard", 0.0008427775}, {"ton (long)/cubic yard", 0.0007524799},
                        {"slug/ft³ (slug per cubic foot)", 0.0019403203}, {"psi/1000 feet", 0.433527504}, {"Earth's density (mean)", 0.0001812251}, },
                        "Density", parent)
{

}

void DensityConverter::convertValues(int unitIndex, QString valueString)
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
        double toKilogramPerCubicMeterCoefficient = m_unitList.at(unitIndex).second;
        double inputToKilogramPerCubicMeter = inputDouble / toKilogramPerCubicMeterCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToKilogramPerCubicMeter * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

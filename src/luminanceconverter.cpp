#include "luminanceconverter.h"

LuminanceConverter::LuminanceConverter(QWidget *parent)
    : AbstractConverter({{"candela per square meter", 1}, {"candela per square centimeter", 0.0001}, {"candela per square foot", 0.09290304},
                        {"candela per square inch", 0.00064516}, {"kilocandela per square meter", 0.001}, {"sb (stilb)", 0.0001},
                        {"lumen/square meter/steradian", 1}, {"lumen/sq. cm/steradian", 0.0001}, {"lumen/square foot/steradian", 0.09290304},
                        {"watt/sq. cm/steradian (at 555 nm)", 1.464128843E-7}, {"nt (nit)", 1}, {"mnt (millinit)", 1000},
                        {"L (lambert)", 0.0003141593}, {"mL (millilambert)", 0.3141592654}, {"fL (foot-lambert)", 0.291863508},
                        {"apostilb", 3.1415926536}, {"blondel", 3.1415926536}, {"bril", 31415926.536},
                        {"skot", 3141.5926536} },
                        "Luminance", parent)
{

}

void LuminanceConverter::convertValues(int unitIndex, QString valueString)
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
        double toCandelaPerSquareMeterCoefficient = m_unitList.at(unitIndex).second;
        double inputToCandelaPerSquareMeter = inputDouble / toCandelaPerSquareMeterCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToCandelaPerSquareMeter * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

#include "magneticfluxdensityconverter.h"

MagneticFluxDensityConverter::MagneticFluxDensityConverter(QWidget *parent)
    : AbstractConverter({{"T (tesla)", 1}, {"Wb/m² (weber per square meter)", 1}, {"Wb/cm² (weber per square centimeter)", 0.0001},
                        {"Wb/in² (weber per square inch)", 0.00064516}, {"Mx/m² (maxwell per square meter)", 1}, {"Mx/cm² (maxwell per square centimeter)", 10000},
                        {"Mx/in² (maxwell per square inch)", 64516}, {"Gs, G (Gauss)", 10000}, {"line per square centimeter", 10000},
                        {"line per square inch", 64516}, {"gamma", 1000000000}, },
                        "Magnetic Flux Density", parent)
{

}

void MagneticFluxDensityConverter::convertValues(int unitIndex, QString valueString)
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
        double toTeslaCoefficient = m_unitList.at(unitIndex).second;
        double inputToTesla = inputDouble / toTeslaCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToTesla * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

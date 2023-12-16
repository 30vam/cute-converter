#include "volumetricflowrateconverter.h"

VolumetricFlowRateConverter::VolumetricFlowRateConverter(QWidget *parent)
    : AbstractConverter({ {"l/sec (litre per second)", 1000}, {"m³/sec (cubic meter per second)", 1}, {"ft³/sec (cubic foot per second)", 35.314667},
                        {"l/min (litre per minute)", 60000}, {"m³/min (cubic meter per minute)", 60}, {"ft³/min(cubic foot per minute)", 2118.88},
                        {"l/hr (litre per hour)", 3600000}, {"m³/hr (cubic meter per hour)", 3600}, {"ft³/hr(cubic foot per hour)", 127132.8},
                        {"m³/day (cubic meter per day)", 86400}, {"gal(UK)/min (UK galleon per minute)", 13198.1549}, {"gal(US)/min (US galleon per minute)", 15850.3231} }
                        , "Volumetric Flow Rate", parent)
{

}

void VolumetricFlowRateConverter::convertValues(int unitIndex, QString valueString)
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
        double toCubicMeterPerSecondCoefficient = m_unitList.at(unitIndex).second;
        double inputToCubicMeterPerSecond = inputDouble / toCubicMeterPerSecondCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToCubicMeterPerSecond * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

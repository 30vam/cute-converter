#include "temperatureconverter.h"

TemperatureConverter::TemperatureConverter(QWidget *parent)
    : AbstractConverter({ {"K/Kelvin", 0}, {"°C/Celsius(Centigrade)", 0}, {"°F/Fahrenheit", 0}, {"°R/Rankine", 0}, {"°Ré/Réaumur", 0} },
                        "Temperature", parent)
{

}

void TemperatureConverter::convertValues(int unitIndex, QString valueString)
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
        double inputToKelvin;
        double inputToCelsius;

        //Convert FROM different units to kelvin/celsius
        switch (unitIndex) {
        case 0:  //K
            inputToKelvin = inputDouble;
            inputToCelsius = inputToKelvin - m_celsiusThreshold;
            break;
        case 1:  //°C
            inputToCelsius = inputDouble;
            inputToKelvin = inputToCelsius + m_celsiusThreshold;
            break;
        case 2:  //°F
            inputToCelsius = (inputDouble - m_fahrenheitThreshold) / m_fahrenheitCoefficient;
            inputToKelvin = inputToCelsius + m_celsiusThreshold;
            break;
        case 3:  //°R
            inputToKelvin = inputDouble / m_rankineCoefficient;
            inputToCelsius = inputToKelvin - m_celsiusThreshold;
            break;
        case 4:  //°Ré
            inputToCelsius = inputDouble * m_rankineCoefficient;
            inputToKelvin = inputToCelsius + m_celsiusThreshold;
            break;
        default:
            break;
        }

        //Convert TO different units
        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            double convertedValue;

            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                switch (i) {
                case 0:  //K
                    convertedValue = inputToKelvin;
                    break;
                case 1:  //°C
                    convertedValue = inputToCelsius;
                    break;
                case 2:  //°F
                    convertedValue = (inputToCelsius * m_fahrenheitCoefficient) + m_fahrenheitThreshold;
                    break;
                case 3:  //°R
                    convertedValue = inputToKelvin * m_rankineCoefficient;
                    break;
                case 4:  //°Ré
                    convertedValue = inputToCelsius / m_reaumurCoefficient;
                    break;
                default:
                    convertedValue = 0;
                    break;
                }

                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include "abstractconverter.h"

class TemperatureConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit TemperatureConverter(QWidget *parent = nullptr);

private:
    const double m_celsiusThreshold = 273.15;
    const double m_fahrenheitCoefficient = 1.8;
    const double m_fahrenheitThreshold = 32;
    const double m_rankineCoefficient = 1.8;
    const double m_reaumurCoefficient = 1.25;

    void convertValues(int unitIndex, QString valueString) override;
};

#endif // TEMPERATURECONVERTER_H

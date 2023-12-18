#ifndef ANGLECONVERTER_H
#define ANGLECONVERTER_H

#include "abstractconverter.h"

class AngleConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit AngleConverter(QWidget *parent = nullptr);

private:
    const double m_celsiusThreshold = 273.15;
    const double m_fahrenheitCoefficient = 1.8;
    const double m_fahrenheitThreshold = 32;
    const double m_rankineCoefficient = 1.8;
    const double m_reaumurCoefficient = 1.25;

    void convertValues(int unitIndex, QString valueString) override;
};

#endif // ANGLECONVERTER_H

#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include "abstractconverter.h"

class TemperatureConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit TemperatureConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // TEMPERATURECONVERTER_H

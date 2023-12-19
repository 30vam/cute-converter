#ifndef FUELCONSUMPTIONCONVERTER_H
#define FUELCONSUMPTIONCONVERTER_H

#include "abstractconverter.h"

class FuelConsumptionConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit FuelConsumptionConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // FUELCONSUMPTIONCONVERTER_H

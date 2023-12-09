#ifndef ENERGYCONVERTER_H
#define ENERGYCONVERTER_H

#include "abstractconverter.h"

class EnergyConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit EnergyConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // ENERGYCONVERTER_H

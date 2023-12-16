#ifndef VOLUMETRICFLOWRATECONVERTER_H
#define VOLUMETRICFLOWRATECONVERTER_H

#include "abstractconverter.h"

class VolumetricFlowRateConverter : public AbstractConverter
{
    Q_OBJECT

public:
    explicit VolumetricFlowRateConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // VOLUMETRICFLOWRATECONVERTER_H

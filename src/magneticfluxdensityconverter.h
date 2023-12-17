#ifndef MAGNETICFLUXDENSITYCONVERTER_H
#define MAGNETICFLUXDENSITYCONVERTER_H

#include "abstractconverter.h"

class MagneticFluxDensityConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit MagneticFluxDensityConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // MAGNETICFLUXDENSITYCONVERTER_H

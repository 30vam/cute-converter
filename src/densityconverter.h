#ifndef DENSITYCONVERTER_H
#define DENSITYCONVERTER_H

#include "abstractconverter.h"

class DensityConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit DensityConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // DENSITYCONVERTER_H

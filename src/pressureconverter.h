#ifndef PRESSURECONVERTER_H
#define PRESSURECONVERTER_H

#include "abstractconverter.h"

class PressureConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit PressureConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // PRESSURECONVERTER_H

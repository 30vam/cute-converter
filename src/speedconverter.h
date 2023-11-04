#ifndef SPEEDCONVERTER_H
#define SPEEDCONVERTER_H

#include "abstractconverter.h"

class SpeedConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit SpeedConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // SPEEDCONVERTER_H

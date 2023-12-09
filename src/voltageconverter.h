#ifndef VOLTAGECONVERTER_H
#define VOLTAGECONVERTER_H

#include "abstractconverter.h"

class VoltageConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit VoltageConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // VOLTAGECONVERTER_H

#ifndef LUMINANCECONVERTER_H
#define LUMINANCECONVERTER_H

#include "abstractconverter.h"

class LuminanceConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit LuminanceConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // LUMINANCECONVERTER_H

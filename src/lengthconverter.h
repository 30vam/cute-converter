#ifndef LENGTHCONVERTER_H
#define LENGTHCONVERTER_H

#include "abstractconverter.h"

class LengthConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit LengthConverter(QWidget *parent = nullptr);
    virtual ~LengthConverter() {};

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // LENGTHCONVERTER_H

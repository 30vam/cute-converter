#ifndef POWERCONVERTER_H
#define POWERCONVERTER_H

#include "abstractconverter.h"

class PowerConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit PowerConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};


#endif // POWERCONVERTER_H

#ifndef VISCOSITYCONVERTER_H
#define VISCOSITYCONVERTER_H

#include "abstractconverter.h"

class ViscosityConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit ViscosityConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // VISCOSITYCONVERTER_H

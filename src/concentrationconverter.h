#ifndef CONCENTRATIONCONVERTER_H
#define CONCENTRATIONCONVERTER_H

#include "abstractconverter.h"

class ConcentrationConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit ConcentrationConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // CONCENTRATIONCONVERTER_H

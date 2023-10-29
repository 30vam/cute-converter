#ifndef WEIGHTCONVERTER_H
#define WEIGHTCONVERTER_H

#include "abstractconverter.h"


class WeightConverter : public AbstractConverter
{
    Q_OBJECT

public:
    explicit WeightConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // WEIGHTCONVERTER_H

#ifndef ANGLECONVERTER_H
#define ANGLECONVERTER_H

#include "abstractconverter.h"

class AngleConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit AngleConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // ANGLECONVERTER_H

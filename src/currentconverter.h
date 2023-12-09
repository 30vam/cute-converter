#ifndef CURRENTCONVERTER_H
#define CURRENTCONVERTER_H

#include "abstractconverter.h"

class CurrentConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit CurrentConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // CURRENTCONVERTER_H

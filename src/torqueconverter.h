#ifndef TORQUECONVERTER_H
#define TORQUECONVERTER_H

#include "abstractconverter.h"

class TorqueConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit TorqueConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // TORQUECONVERTER_H

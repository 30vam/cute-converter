#ifndef TIMECONVERTER_H
#define TIMECONVERTER_H

#include "abstractconverter.h"

class TimeConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit TimeConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // TIMECONVERTER_H

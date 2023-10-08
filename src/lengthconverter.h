#ifndef LENGTHCONVERTER_H
#define LENGTHCONVERTER_H

#include "abstractconverter.h"

class LengthConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit LengthConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString, QList<QLineEdit *> &outputLineEditList) override;
};

#endif // LENGTHCONVERTER_H

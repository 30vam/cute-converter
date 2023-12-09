#ifndef FORCECONVERTER_H
#define FORCECONVERTER_H

#include "abstractconverter.h"

class ForceConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit ForceConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // FORCECONVERTER_H

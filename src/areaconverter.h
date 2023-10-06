#ifndef AREACONVERTER_H
#define AREACONVERTER_H

#include "abstractconverter.h"

class AreaConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit AreaConverter(QWidget *parent = nullptr);

private:
    void convertValues() override;
};

#endif // AREACONVERTER_H

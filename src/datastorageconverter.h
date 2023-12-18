#ifndef DATASTORAGECONVERTER_H
#define DATASTORAGECONVERTER_H

#include "abstractconverter.h"

class DataStorageConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit DataStorageConverter(QWidget *parent = nullptr);

private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // DATASTORAGECONVERTER_H

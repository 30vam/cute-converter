#ifndef VOLUMECONVERTER_H
#define VOLUMECONVERTER_H

#include  "abstractconverter.h"

class VolumeConverter : public AbstractConverter
{
    Q_OBJECT
public:
    explicit VolumeConverter(QWidget *parent = nullptr);
    //virtual ~VolumeConverter() {};


private:
    void convertValues(int unitIndex, QString valueString) override;
};

#endif // VOLUMECONVERTER_H

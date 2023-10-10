#include "areaconverter.h"

AreaConverter::AreaConverter(QWidget *parent)
    : AbstractConverter({ {"pm²/square picometer", 1e+24}, {"nm²/square nanometer", 1e+18}, {"μm²/square micrometer", 1e+12},
                        {"mm²/square millimeter", 1000000}, {"cm²/square centimeter", 10000}, {"dm²/square decimeter", 100}, {"m²/square meter", 1},
                        {"a/are", 0.01}, {"ha/hectar", 0.0001}, {"ac/acre", 0.000247}, {"km²/square kilometer", 0.000001}, {"in²/square inch", 1550.0031},
                        {"ft²/square foot", 10.76391}, {"yd²/square yard", 1.19599}, {"mi²/square mile", 3.861e-7}}, "Area", parent)
{


}

void AreaConverter::convertValues(int unitIndex, QString valueString, QList<QLineEdit *> &outputLineEditList)
{
    double inputDouble = valueString.toDouble();
    double toMeterCoefficient = _unitList.at(unitIndex).second;
    double inputToMeter = inputDouble / toMeterCoefficient;

    //Convert value from meter to each unit INDIVIDUALLY
    for(int i = 0; i < outputLineEditList.count(); i++)
    {
        double convertedValue = inputToMeter * _unitList.at(i).second;
        outputLineEditList.at(i)->setText(QString::number(convertedValue));
    }
}

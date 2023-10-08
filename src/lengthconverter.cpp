#include "lengthconverter.h"

//Constructor sets up specefic variables for this converter
LengthConverter::LengthConverter(QWidget *parent)
    : AbstractConverter({ {"fm/femtometer", 1e+15}, {"pm/picometer", 1e+12}, {"Å/angstrom", 1e+10}, {"nm/nanometer", 1e+9}, {"μm/micrometer/micron", 1000000},
                        {"mm/millimeter", 1000}, {"cm/centimeter", 100}, {"dm/decimeter", 10}, {"m/meter", 1}, {"dam/decameter", 0.1},
                        {"hm/hectometer", 0.01}, {"km/kilometer", 0.001}, {"Mm/megameter", 0.000001}, {"Gm/gigameter", 1e-9},
                        {"Tm/terameter", 1e-12}, {"Pm/petameter", 1e-15}, {"ly/light-year", 1.057e-16}, {"pc/parsec", 3.24078e-17},
                        {"in/inch", 39.3701}, {"ft/foot", 3.281}, {"yd/yard", 1.094},
                        {"mi/mile", 0.000621}, {"league", 0.0002071} } , "Length", 8, parent)

{

}

void LengthConverter::convertValues(QString valueString, QList<QLineEdit *> &outputLineEditList)
{
    qDebug() << "Length value entered: "<< valueString;
}

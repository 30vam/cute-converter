#include "pressureconverter.h"

PressureConverter::PressureConverter(QWidget *parent)
    : AbstractConverter({ {"Pa(Pascal)", 1}, {"hPa(Hectopascal)", 0.01}, {"kPa(Kilopascal)", 0.001}, {"MPa(MegaPascal)", 1e-6}, {"atm(standard atmosphere)", 9.86923e-6},
                        {"Bar", 1e-5}, {"mBar(milliBar)", 0.01}, {"psi(pound per square inch)", 0.000145038}, {"psf(pound per square foot)", 0.020885},
                        {"ksi(kilopound force/inch²)", 1.45038e-7}, {"kgf/cm²(kilogram force/centimeter²)", 1.01972e-5}, {"kgf/m²(kilogram force/meter²)", 0.101972},
                        {"mmHg(millimeter of mercury)", 0.00750062}, {"cmHg(centimeter of mercury)", 0.000750062}, {"inchHg(inch of mercury)", 0.0002953},
                        {"mmH₂O(millimeter of water)", 0.10197}, {"cmH₂O(centimeter of water)", 0.0101972}, {"inchH₂O(inch of water)", 0.00401865},
                        {"Torr", 0.00750062}, {"mTorr(millTorr)", 7.50062 } },
                        "Pressure", parent)
{

}

void PressureConverter::convertValues(int unitIndex, QString valueString)
{
    //If the input LineEdit is cleared, clear other LineEdits as well
    if(valueString.isEmpty() || valueString.endsWith("e", Qt::CaseInsensitive))
    {
        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            if (i != unitIndex) //dont change the selected lineEdit
                m_lineEditList.at(i)->setText("");
        }
    }
    //Otherwise convert values
    else
    {
        double inputDouble = valueString.toDouble();
        double toPascalCoefficient = m_unitList.at(unitIndex).second;
        double inputToPascal = inputDouble / toPascalCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToPascal * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}


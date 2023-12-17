#include "viscosityconverter.h"

ViscosityConverter::ViscosityConverter(QWidget *parent)
    : AbstractConverter({{"Ps.s (pascal second)", 1}, {"kilogram-force second per square meter", 0.1019716213}, {"newton second per square meter", 1},
                        {"millinewton second per square meter", 1000}, {"dyne second per square centimeter", 10}, {"P (poise)", 10},
                        {"EP (exapoise)", 1.E-17}, {"PP (petapoise)", 1.E-14}, {"TP (terrapoise)", 1.E-11},
                        {"GP (gigapoise)", 1.E-8}, {"MP (megapoise)", 0.00001}, {"kP (kilopoise)", 0.01},
                        {"hP (hectopoise)", 0.1}, {"daP (dekapoise)", 1}, {"dP (decipoise)", 100},
                        {"cP (centipoise)", 1000}, {"mP (millipoise)", 10000}, {"µP (micropoise)", 10000000},
                        {"nP (nanopoise)", 10000000000}, {"pP (picopoise)", 10000000000000}, {"fP (femtopoise)", 10000000000000000},
                        {"pound-force second per square inch", 0.0001450377}, {"pound-force second per square foot", 0.0208854342}, {"poundal second/square foot", 0.6719689751},
                        {"gram per centimeter second", 10}, {"slug per foot second", 0.0208854342}, {"pound per foot second",0.6719689751},
                         {"lb/ft.h (pound per foot hour)", 2419.0883105} },
                        "Viscosity", parent)
{

}

void ViscosityConverter::convertValues(int unitIndex, QString valueString)
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
        double toPascalSecondCoefficient = m_unitList.at(unitIndex).second;
        double inputToPascalSecond = inputDouble / toPascalSecondCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToPascalSecond * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

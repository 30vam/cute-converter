#include "fuelconsumptionconverter.h"

FuelConsumptionConverter::FuelConsumptionConverter(QWidget *parent)
    : AbstractConverter({ {"m/L (meter per liter)", 1}, {"Em/L (exameter per liter)", 1.e-18}, {"Pm/L (petameter per liter)",  1.e-15},
                        {"Tm/L (terameter per liter)", 1.e-12}, {"Gm/L (gigameter per liter)", 1.E-9}, {"Mm/L (megameter per liter)", 0.000001},
                        {"km/L (kilometer per liter)", 0.001}, {"hm/L (hectometer per liter)", 0.01}, {"dam/L (dekameter per liter)", 0.1},
                        {"cm/L (centimeter per liter)", 100}, {"mi/L (mile(US) per liter)", 0.0006213712}, {"n.mile/L (nautical mile per liter)", 0.0005395941},
                        {"nautical mile per gallon(US)", 0.0020425858}, {"kilometer per gallon(US)", 0.0037854118}, {"meter per gallon(US)", 3.7854117834},
                        {"meter per gallon(UK)", 4.5460992939}, {"mile per gallon(US)", 0.0023521458}, {"mile per gallon(UK)", 0.0028248094},
                        {"m/m³ (meter per cubic meter)", 1000}, {"m/cm³ (meter per cubic centimeter)", 0.001}, {"m/yd³ (meter per cubic yard)", 764.55485817},
                        {"m/ft³ (meter per cubic foot)", 28.316846593}, {"m/in³ (meter per cubic inch)", 0.016387064}, {"meter per quart(US)", 0.9463529464},
                        {"meter per quart(UK)", 1.136524823}, {"m/pt (meter per pint(US))", 0.473176473}, {"m/pt (meter per pint(UK))", 0.5682624117},
                        {"meter per cup(US)", 0.2365882365}, {"meter per cup(UK)", 0.2841312059}, {"meter per fluid ounce(US)", 0.0295735296},
                        {"meter per fluid ounce(UK)", 0.0284131206},
                        //Inverted Units
                        {"L/m (liter/meter)", 1}, {"L/100km (liter per 100 kilometer)", 100000}, {"gallon (US) per mile", 425.1437075},
                        {"gallon(US) per 100 mile", 42514.37075}, {"gallon(UK) per mile", 354.00618996}, {"gallon(UK) per 100 mile", 35400.618996}, },
                        "Fuel Consumption", parent)
{

}

void FuelConsumptionConverter::convertValues(int unitIndex, QString valueString)
{
    int invertedUnitStartingIndex = 31;  //From which unit index onwards the formula is inverted?

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
        double coefficient = m_unitList.at(unitIndex).second;
        double inputToMeterPerLiter;
        double inputToLiterPerMeter;

        if(unitIndex < invertedUnitStartingIndex)  //If it's a normal unit
        {
            inputToMeterPerLiter = inputDouble / coefficient;
            inputToLiterPerMeter = coefficient / inputDouble;
        }
        else  //If it's an inverted unit
        {
            inputToLiterPerMeter = inputDouble / coefficient;
            inputToMeterPerLiter = coefficient / inputDouble;
        }

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex)
            {
                double convertedValue;

                if(i < invertedUnitStartingIndex)  //If it's a normal unit
                    convertedValue = inputToMeterPerLiter * m_unitList.at(i).second;
                else  //If it's an inverted unit
                    convertedValue = inputToLiterPerMeter * m_unitList.at(i).second;

                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

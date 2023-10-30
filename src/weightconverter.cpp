#include "weightconverter.h"

WeightConverter::WeightConverter(QWidget *parent)
    : AbstractConverter({ {"µg/microgram", 1000000}, {"mg/milligram", 1000}, {"cg/centigram", 100}, {"g/gram", 1}, {"kg/kilogram", 0.001}, {"hg/hectogram", 0.01},
                        {"oz/ounces", 0.035274}, {"oz t/troy ounces", 0.0321507}, {"AT(UK)/assay ton(UK)", 0.0306122449}, {"lb/pound", 0.00220462}, {"st/stones", 0.000157473},
                        {"q/quintal", 0.00001}, {"t/ton", 0.000001}, {"pwt/pennyweight", 0.643015}, {"car/carat", 5}, {"gr/grain", 15.4324}, {"u/Atomic mass unit", 6.022e+23} },
                        "Weight/Mass", parent)
{

}

void WeightConverter::convertValues(int unitIndex, QString valueString)
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
        double toGramCoefficient = m_unitList.at(unitIndex).second;
        double inputToGram = inputDouble / toGramCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToGram * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

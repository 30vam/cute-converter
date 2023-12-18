#include "angleconverter.h"

AngleConverter::AngleConverter(QWidget *parent)
    : AbstractConverter({ {"rad (radian)", 1}, {"° (degree) (Centigrade)", 57.295779513}, {"g (grad)", 63.661977237}, {"' (minute)", 3437.7467708},
                        {"\" (second)", 206264.80625}, {"gon", 63.661977237}, {"sign", 1.9098593171}, {"mil", 1018.5916358},
                        {"r (revolution)", 0.1591549431}, {"°circle", 0.1591549431}, {"turn", 0.1591549431}, {"quandrant", 0.6366197724},
                        {"right angle", 0.6366197724}, {"sextant", 0.9549296586} },
                        "Angle", parent)
{

}

void AngleConverter::convertValues(int unitIndex, QString valueString)
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
        double toRadianCoefficient = m_unitList.at(unitIndex).second;
        double inputToRadian = inputDouble / toRadianCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex)
            {
                double convertedValue = inputToRadian * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

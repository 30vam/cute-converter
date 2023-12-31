#include "timeconverter.h"

TimeConverter::TimeConverter(QWidget *parent)
    : AbstractConverter({ {"nanosecond", 1e+9}, {"microsecond", 1e+6}, {"millisecond", 1000}, {"centisecond", 100}, {"decisecond", 10}, {"second", 1},
                         {"minute", 60}, {"hour", 3600}, {"day", 86400}, {"week", 604800}, {"month", 2.628e+6}, {"year", 3.154e+7}, {"lustrum", 1.577e+8}, {"decade", 3.154e+8},
                        {"century", 3.154e+9}, {"millenium", 3.154e+10} }, "Time", parent)
{

}

void TimeConverter::convertValues(int unitIndex, QString valueString)
{
    //What is the index of second in unitList?
    int secondIndex = 5;

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
        double toSecondCoefficient = m_unitList.at(unitIndex).second;
        double inputToSecond{0};

        if(unitIndex <= secondIndex)  //devide value by its coefficient if the unit is SMALLER than second
            inputToSecond = inputDouble / toSecondCoefficient;
        else //multiply value by its coefficient if the unit is LARGER than second
            inputToSecond = inputDouble * toSecondCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            double convertedValue{0};

            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                if(i <= secondIndex)  //multiply second by its coefficient if the unit is SMALLER than second
                    convertedValue = inputToSecond * m_unitList.at(i).second;
                else //devide second by its coefficient if the unit is LARGER than second
                    convertedValue = inputToSecond / m_unitList.at(i).second;

                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

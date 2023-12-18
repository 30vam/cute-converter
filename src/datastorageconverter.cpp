#include "datastorageconverter.h"

DataStorageConverter::DataStorageConverter(QWidget *parent)
    : AbstractConverter({ {"b (bit)", 1}, {"nibble", 0.25}, {"B (byte)", 0.125}, {"character", 0.125},
                        {"word", 0.0625}, {"MAPM-word", 0.03125}, {"quadruple-word", 0.015625}, {"block", 0.0002441406},
                        {"kb (kilobit)", 0.0009765625}, {"kB (kilobyte)", 0.000125}, {"Mb (megabit)", 9.536743164E-7}, {"MB (megabyte)", 1.25E-7},
                        {"Gb (gigabit)", 9.313225746E-10}, {"GB (gigabyte)", 1.164153218E-10}, {"Tb (terabit)", 9.094947017E-13}, {"TB (terabyte)", 1.25E-13},
                        {"Pb (petabit)", 8.881784197E-16}, {"PB (petabyte)", 1.25E-16}, {"Eb (exabit)", 8.673617379E-19}, {"EB (exabyte)", 1.25E-19},
                        {"floppy disk (3.5\", DD)", 1.715072883E-7}, {"floppy disk (3.5\", HD)", 8.575364418E-8}, {"floppy disk (3.5\", ED)", 4.287682209E-8},
                        {"floppy disk (5.25\", DD)", 3.430145767E-7}, {"floppy disk (5.25\", HD)", 1.029694749E-7}, {"Zip 100", 1.244624813E-9},
                        {"Zip 250", 4.978499255E-10}, {"Jaz 1GB", 1.164153218E-10},  {"Jaz 2GB", 5.820766091E-11}, {"CD (74 minute)", 1.83537884E-10},
                        {"CD (80 minute)", 1.697725428E-10}, {"DVD (1 layer, 1 side)", 2.47692174E-11}, {"DVD (2 layer, 1 side)", 1.369592021E-11},
                        {"DVD (1 layer, 2 side)", 1.23846087E-11}, {"DVD (2 layer, 2 side)", 6.847960107E-12}, },
                        "Data Storage", parent)
{

}

void DataStorageConverter::convertValues(int unitIndex, QString valueString)
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
        double toBitCoefficient = m_unitList.at(unitIndex).second;
        double inputToBit = inputDouble / toBitCoefficient;

        for(int i = 0; i < m_lineEditList.count(); i++)
        {
            //This condition makes it so the LineEdit which is correctly being edited is not affected by the loop
            if (i != unitIndex) {
                double convertedValue = inputToBit * m_unitList.at(i).second;
                m_lineEditList.at(i)->setText(QString::number(convertedValue));
            }
        }
    }
}

#include "abstractconverter.h"

#include <QDebug>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

AbstractConverter::AbstractConverter(QWidget *parent)
    : QWidget{parent}
{
    //test
    this->unitList.append("Test2");
    QHBoxLayout *converterLayout = new QHBoxLayout(this);
    QPushButton *testButton = new QPushButton("TEST", this);
    testButton->setFixedSize(100, 1000);
    QPushButton *testButton2 = new QPushButton("TEST2", this);
    testButton2->setFixedSize(100, 1000);
    converterLayout->addWidget(testButton);
    converterLayout->addWidget(testButton2);
    //DONT FORGET TO ADD THESE LATER
    //QLineEdit *valueLineEdit;
    //QComboBox *unitComboBox;

    generateAllUnits(this);
}

//MAYBE I NEEDED TO SETUP CONVERSION SCROLL AREA WIDGET FIRST
void AbstractConverter::generateAllUnits(AbstractConverter *converterObject)
{
    /*//Setup groupBox
    converterObject->converterGroupBox->setTitle(converterObject->groupBoxTitle);
    float width = converterObject->conversionScrollArea->width();
    float height = converterObject->conversionScrollArea->height();
    converterObject->converterGroupBox->setMinimumSize(width, height);

    //Setup lineEdit
    converterObject->valueLineEdit->setPlaceholderText("Enter a value...");

    //Setup comboBox
    converterObject->unitComboBox->addItems(converterObject->unitList);*/

}

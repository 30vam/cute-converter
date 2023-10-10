#include "abstractconverter.h"

#include <QDebug>
#include <QScrollArea>
#include <QFrame>
#include <QSpacerItem>
#include <QDoubleValidator>

//Use an initilizer list to setup field members, and then define the constructor
AbstractConverter::AbstractConverter(QList<QPair<QString, double>> unitList, QString conversionType, QWidget *parent, int defaultComboBoxUnit)
    : QWidget(parent), _unitList(unitList), _conversionType(conversionType), _defaultComboBoxUnit(defaultComboBoxUnit),  //Fields that need unique parameters from constructor
    _aleoFont("Aleo", 10), _aleoBigFont("Aleo", 15)  //Fonts (Fields that don't need parameters to initilize, but couldn't find a way to initilize them inside header, so they're initilized here.
{
    //CREATE THE GRID LAYOUT
    _converterGridLayout = new QGridLayout(this);

    //Setup converter UI
    AbstractConverter::setFont(_aleoFont);
    generateInputSection(_converterGridLayout, _conversionType, _unitList, _aleoBigFont);  //Probably won't use it
    generateOutputSection(_converterGridLayout, _outputLineEditList, _unitList);
}

void AbstractConverter::generateInputSection(QGridLayout *converterGridLayout, QString &conversionType, QList<QPair<QString, double>> &unitList, const QFont &inputFont)
{
    //Setup layout inside the scrollArea
    _converterGridLayout->setContentsMargins(64, 32, 64, 32);
    converterGridLayout->setHorizontalSpacing(64);
    converterGridLayout->setVerticalSpacing(16);
    converterGridLayout->setColumnStretch(0,2);
    converterGridLayout->setColumnStretch(1,1);
    converterGridLayout->setRowMinimumHeight(1, 16);
    setLayout(converterGridLayout);

    //Generate the main lineEdit the top part of the layout
    QLineEdit *inputLineEdit = new QLineEdit(this);
    inputLineEdit->setFont(inputFont);
    inputLineEdit->setPlaceholderText("Enter " + conversionType.toUpper() + "...");
    inputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
    inputLineEdit->setClearButtonEnabled(true);
    //Set input validator for lineEdit
    QValidator *inputValidator = new QDoubleValidator(this); //This let's us allow doubles inside textEdits only
    inputLineEdit->setValidator(inputValidator);

    //Create a comboBox for available units
    QComboBox *unitComboBox = new QComboBox(this);
    unitComboBox->setFont(inputFont);
    for(int i =0; i < unitList.count(); i++) //Loop for adding unit list to the combo box
    {
        unitComboBox->addItem(unitList[i].first);
    }
    unitComboBox->setCurrentIndex(this->_defaultComboBoxUnit);

    //Generates a line that seperates input & output section
    QFrame *lineFrame = new QFrame(this);
    lineFrame->setFrameShape(QFrame::HLine);
    lineFrame->setFrameShadow(QFrame::Sunken);

    //Add all of the above to the grid layout
    converterGridLayout->addWidget(inputLineEdit, 0, 0);
    converterGridLayout->addWidget(unitComboBox, 0, 1);
    converterGridLayout->addWidget(lineFrame, 1, 0, 1, 2);

}

void AbstractConverter::generateOutputSection(QGridLayout *converterGridLayout, QList<QLineEdit *> &outputLineEditList, QList<QPair<QString, double>> &unitList)
{
    QValidator *inputValidator = new QDoubleValidator(this);

    //Generates as many lineEdits as available units
    for(int row = _outputStartingRow; row < (unitList.count() + _outputStartingRow); row++){
        QLineEdit *outputLineEdit = new QLineEdit(this);
        outputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        outputLineEdit->setPlaceholderText("Convert " + unitList.at(row - _outputStartingRow).first);
        outputLineEdit->setValidator(inputValidator);
        outputLineEdit->setClearButtonEnabled(true);
        converterGridLayout->addWidget(outputLineEdit, row, 0);
        outputLineEditList.append(outputLineEdit); //Add the new lineEdit(its pointer) to a list for later use

        //This connect function, connects the "textChanged" signal from lineEdits to the lambda function,
        //the lambda function also takes the new entered value, so it can be used inside the calculator function for the final result.
        int unitIndex = row - _outputStartingRow; //For passing the index of lineEdit as value inside connect, so we can know which unit to use
        //Capture only unitIndex BY VALUE and everything else as reference. We need to capture it by value, because otherwise it'll be out of scope?
        connect(outputLineEdit, &QLineEdit::textEdited, this, [&, unitIndex](QString newText){
            convertValues(unitIndex, newText, outputLineEditList);
        });

        //Create a spacer if the last lineEdit is made
        if (row >= (unitList.count() + _outputStartingRow - 1)) {
            QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            converterGridLayout->addItem(verticalSpacer, row + 1, 0);
        }
    }

    //Generates unit buttons right next to their value lineEdits.
    for(int row = _outputStartingRow; row < (unitList.count() + _outputStartingRow); row++){
        QPushButton *unitPushButton = new QPushButton(unitList.at(row - _outputStartingRow).first, this);
        converterGridLayout->addWidget(unitPushButton, row, 1);
    }
}

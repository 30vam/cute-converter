#include "abstractconverter.h"

#include <QDebug>
#include <QComboBox>
#include <QPushButton>
#include <QFrame>

//Use an initilizer list to setup field members, and then define the constructor
AbstractConverter::AbstractConverter(QList<QPair<QString, double>> unitList, QString conversionType, QWidget *parent, int defaultComboBoxUnit)
    : QWidget(parent), _unitList(unitList), _conversionType(conversionType), _defaultComboBoxIndex(defaultComboBoxUnit),  //Fields that need unique parameters from constructor
    _aleoFont("Aleo", 10), _aleoBigFont("Aleo", 15)  //Fonts (Fields that don't need parameters to initilize, but couldn't find a way to initilize them inside header, so they're initilized here.
{

    //Setup layout inside the scrollArea
    _converterGridLayout->setContentsMargins(64, 32, 64, 32);
    _converterGridLayout->setHorizontalSpacing(64);
    _converterGridLayout->setVerticalSpacing(16);
    _converterGridLayout->setColumnStretch(0,2);
    _converterGridLayout->setColumnStretch(1,1);
    _converterGridLayout->setRowMinimumHeight(1, 16);
    setLayout(_converterGridLayout);

    //Setup converter UI
    AbstractConverter::setFont(_aleoFont);
    //generateInputSection(_aleoBigFont);  //Probably better not use it
    generateLineEdits();
}

void AbstractConverter::generateInputSection(const QFont &inputFont)
{
    //Generate the main lineEdit in the top part of the converter
    QLineEdit *inputLineEdit = new QLineEdit(this);
    inputLineEdit->setFont(inputFont);
    inputLineEdit->setPlaceholderText("Enter " + _conversionType.toUpper() + "...");
    inputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
    inputLineEdit->setClearButtonEnabled(true);
    inputLineEdit->setValidator(_inputValidator);  //Set input validator for lineEdit for double inputs only

    //Create a comboBox for available units
    QComboBox *unitComboBox = new QComboBox(this);
    unitComboBox->setFont(inputFont);
    for(int i =0; i < _unitList.count(); i++) //Loop for adding all units to the combo box
    {
        unitComboBox->addItem(_unitList.at(i).first);
    }
    unitComboBox->setCurrentIndex(this->_defaultComboBoxIndex);

    //Generates a line that seperates input & output section
    QFrame *lineFrame = new QFrame(this);
    lineFrame->setFrameShape(QFrame::HLine);
    lineFrame->setFrameShadow(QFrame::Sunken);

    //Add all of the above to the grid layout
    _converterGridLayout->addWidget(inputLineEdit, 0, 0);
    _converterGridLayout->addWidget(unitComboBox, 0, 1);
    _converterGridLayout->addWidget(lineFrame, 1, 0, 1, 2);
}

void AbstractConverter::generateLineEdits()
{
    //Generates as many lineEdits as available units
    for(int row = _outputStartingRow; row < (_unitList.count() + _outputStartingRow); row++){
        QLineEdit *outputLineEdit = new QLineEdit(this);
        outputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        outputLineEdit->setPlaceholderText("Convert " + _unitList.at(row - _outputStartingRow).first);
        outputLineEdit->setValidator(_inputValidator);
        outputLineEdit->setClearButtonEnabled(true);
        _converterGridLayout->addWidget(outputLineEdit, row, 0);
        _lineEditList.append(outputLineEdit); //Add the new LineEdit to a list for later use

        //This connect function, connects the "textChanged" signal from lineEdits to the lambda function,
        //and the lambda function also passes the newly entered value to the calculator function, so it can be used inside the
        //calculator function for the final result.
        int unitIndex = row - _outputStartingRow; //For passing the index of lineEdit as value inside connect, so we can know which unit to use
        connect(outputLineEdit, &QLineEdit::textEdited, this, [&, unitIndex](QString newText){  //Capture only unitIndex BY VALUE and everything else as reference. We need to capture it by value, because otherwise it'll be out of scope?
            convertValues(unitIndex, newText);
        });

        //Create a spacer if the last lineEdit is made
        if (row >= (_unitList.count() + _outputStartingRow - 1)) {
            QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            _converterGridLayout->addItem(verticalSpacer, row + 1, 0);
        }
    }

    //Generates unit buttons right next to their value lineEdits.
    for(int row = _outputStartingRow; row < (_unitList.count() + _outputStartingRow); row++){
        QPushButton *unitPushButton = new QPushButton(_unitList.at(row - _outputStartingRow).first, this);
        _converterGridLayout->addWidget(unitPushButton, row, 1);
    }
}

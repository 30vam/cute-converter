#include "abstractconverter.h"

#include <QDebug>
#include <QComboBox>
#include <QPushButton>
#include <QFrame>

//Use an initilizer list to setup field members, and then define the constructor
AbstractConverter::AbstractConverter(QList<QPair<QString, double>> unitList, QString conversionType, QWidget *parent, int defaultComboBoxUnit)
    : QWidget(parent), m_unitList(unitList), m_conversionType(conversionType), m_defaultComboBoxIndex(defaultComboBoxUnit),  //Fields that need unique parameters from constructor
    m_aleoFont("Aleo", 16), m_aleoBigFont("Aleo", 15)  //Fonts (Fields that don't need parameters to initilize, but couldn't find a way to initilize them inside header, so they're initilized here.
{

    //Setup layout inside the scrollArea
    m_converterGridLayout->setContentsMargins(64, 32, 64, 32);
    m_converterGridLayout->setHorizontalSpacing(64);
    m_converterGridLayout->setVerticalSpacing(16);
    m_converterGridLayout->setColumnStretch(0,3);
    m_converterGridLayout->setColumnStretch(1,2);
    m_converterGridLayout->setRowMinimumHeight(1, 16);
    setLayout(m_converterGridLayout);

    //Setup converter UI
    AbstractConverter::setFont(m_aleoFont);
    //generateInputSection(_aleoBigFont);  //Probably better not use it
    generateLineEdits();
}

void AbstractConverter::generateInputSection(const QFont &inputFont)
{
    //Generate the main lineEdit in the top part of the converter
    QLineEdit *inputLineEdit = new QLineEdit(this);
    inputLineEdit->setFont(inputFont);
    inputLineEdit->setPlaceholderText("Enter " + m_conversionType.toUpper() + "...");
    inputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
    inputLineEdit->setClearButtonEnabled(true);
    inputLineEdit->setValidator(m_inputValidator);  //Set input validator for lineEdit for double inputs only

    //Create a comboBox for available units
    QComboBox *unitComboBox = new QComboBox(this);
    unitComboBox->setFont(inputFont);
    for(int i =0; i < m_unitList.count(); i++) //Loop for adding all units to the combo box
    {
        unitComboBox->addItem(m_unitList.at(i).first);
    }
    unitComboBox->setCurrentIndex(this->m_defaultComboBoxIndex);

    //Generates a line that seperates input & output section
    QFrame *lineFrame = new QFrame(this);
    lineFrame->setFrameShape(QFrame::HLine);
    lineFrame->setFrameShadow(QFrame::Sunken);

    //Add all of the above to the grid layout
    m_converterGridLayout->addWidget(inputLineEdit, 0, 0);
    m_converterGridLayout->addWidget(unitComboBox, 0, 1);
    m_converterGridLayout->addWidget(lineFrame, 1, 0, 1, 2);
}

void AbstractConverter::generateLineEdits()
{
    //Generates as many lineEdits as available units
    for(int row = m_outputStartingRow; row < (m_unitList.count() + m_outputStartingRow); row++){
        QLineEdit *outputLineEdit = new QLineEdit(this);
        outputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        outputLineEdit->setPlaceholderText("Convert " + m_unitList.at(row - m_outputStartingRow).first);
        outputLineEdit->setValidator(m_inputValidator);
        outputLineEdit->setClearButtonEnabled(true);
        outputLineEdit->setFixedHeight(m_buttonHeight);
        m_converterGridLayout->addWidget(outputLineEdit, row, 0);
        m_lineEditList.append(outputLineEdit); //Add the new LineEdit to a list for later use

        //This connect function, connects the "textChanged" signal from lineEdits to the lambda function,
        //and the lambda function also passes the newly entered value to the calculator function, so it can be used inside the
        //calculator function for the final result.
        int unitIndex = row - m_outputStartingRow; //For passing the index of lineEdit as value inside connect, so we can know which unit to use
        connect(outputLineEdit, &QLineEdit::textEdited, this, [&, unitIndex](QString newText){  //Capture only unitIndex BY VALUE and everything else as reference. We need to capture it by value, because otherwise it'll be out of scope?
            convertValues(unitIndex, newText);
        });

        //Create a spacer if the last lineEdit is made
        if (row >= (m_unitList.count() + m_outputStartingRow - 1)) {
            QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            m_converterGridLayout->addItem(verticalSpacer, row + 1, 0);
        }
    }

    //Generates unit buttons right next to their value lineEdits.
    for(int row = m_outputStartingRow; row < (m_unitList.count() + m_outputStartingRow); row++){
        QPushButton *unitPushButton = new QPushButton(m_unitList.at(row - m_outputStartingRow).first, this);
        unitPushButton->setFixedHeight(m_buttonHeight);
        m_converterGridLayout->addWidget(unitPushButton, row, 1);
    }
}

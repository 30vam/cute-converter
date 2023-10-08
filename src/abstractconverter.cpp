#include "abstractconverter.h"

#include <QDebug>
#include <QScrollArea>
#include <QFrame>
#include <QSpacerItem>
#include <QDoubleValidator>

AbstractConverter::AbstractConverter(QList<QPair<QString, double>> unitList, QString conversionType, int defaultComboBoxUnit, QWidget *parent)
    : QWidget{parent}
{
    //FONTS
    //QFont exoFont("Exo Medium", 15);
    //QFont dosisFont("Dosis", 15, QFont::Light);
    //QFont dosisBoldFont("Dosis", 15, QFont::Bold);
    QFont aleoFont("Aleo", 10);
    QFont aleoBoldFont("Aleo", 15);
    //QFont mulishFont("Mulish", 15, QFont::ExtraLight);

    //CREATE THE GRID LAYOUT
    QGridLayout *converterGridLayout = new QGridLayout(this);
    //In which row should output UI start ?
    outputStartingRow = 2;
    //Set up properties that are captured by the constructor
    this->defaultComboBoxUnit = defaultComboBoxUnit;
    this->conversionType = conversionType;
    this->unitList = unitList;

    //Setup converter UI
    AbstractConverter::setFont(aleoFont);
    generateInputSection(converterGridLayout, conversionType, unitList, aleoBoldFont);
    generateOutputSection(converterGridLayout, outputLineEditList, unitList);

    //test
    //qDebug() << "Units after running method: " << unitList;
}

void AbstractConverter::generateInputSection(QGridLayout *converterGridLayout, QString &conversionType, QList<QPair<QString, double>> &unitList, QFont &inputFont)
{
    //Setup layout inside the scrollArea
    converterGridLayout->setContentsMargins(64, 32, 64, 32);
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
    unitComboBox->setCurrentIndex(defaultComboBoxUnit);

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
    for(int row = outputStartingRow; row < (unitList.count() + outputStartingRow); row++){
        QLineEdit *outputLineEdit = new QLineEdit(this);
        outputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        outputLineEdit->setPlaceholderText("Convert " + unitList.at(row - outputStartingRow).first);
        outputLineEdit->setValidator(inputValidator);
        outputLineEdit->setClearButtonEnabled(true);
        converterGridLayout->addWidget(outputLineEdit, row, 0);
        outputLineEditList.append(outputLineEdit); //Add the new lineEdit(its pointer) to a list for later use

        //This connect function, connects the "textChanged" signal from lineEdits to the lambda function,
        //the lambda function also takes the new entered value, so it can be used inside the calculator function for the final result.
        int unitIndex = row - outputStartingRow; //For passing the index of lineEdit as value inside connect, so we can know which unit to use
        //Capture only unitIndex BY VALUE and everything else as reference. We need to capture it by value, because otherwise it'll be out of scope?
        connect(outputLineEdit, &QLineEdit::textEdited, [&, unitIndex](QString newText){
            convertValues(unitIndex, newText, outputLineEditList);
        });

        //Create a spacer if the last lineEdit is made
        if (row >= (unitList.count() + outputStartingRow - 1)) {
            QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            converterGridLayout->addItem(verticalSpacer, row + 1, 0);
        }
    }

    //Generates unit buttons right next to their value lineEdits.
    for(int row = outputStartingRow; row < (unitList.count() + outputStartingRow); row++){
        QPushButton *unitPushButton = new QPushButton(unitList.at(row - outputStartingRow).first, this);
        converterGridLayout->addWidget(unitPushButton, row, 1);
    }
}

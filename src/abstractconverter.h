#ifndef ABSTRACTCONVERTER_H
#define ABSTRACTCONVERTER_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QFont>
#include <QValidator>

class AbstractConverter : public QWidget
{
    Q_OBJECT

public:
    //Constructor, intitilizer list is inside source file
    explicit AbstractConverter(QList<QPair<QString, double>> unitList, QString conversionType, QWidget *parent = nullptr, int defaultComboBoxUnit = 0);

protected:
    //Field names start with _ to differentiate them from local variables
    QList<QPair<QString, double>> _unitList;  //List of units that is different for each child object, so it's a protected member
    QList<QLineEdit *> _lineEditList; //List that stores the dynamically generated LineEdits inside the currentconverter page

private:
    //Class members
    QGridLayout *_converterGridLayout = new QGridLayout(this); //The layout for each converter (is inside ScrollArea)
    QValidator *_inputValidator = new QDoubleValidator(this); //This validator let's us allow ONLY doubles inside LineEdits
    QString _conversionType; //The name of the conversion e.g. "Length"
    const int _outputStartingRow = 0; //In which row should lineEdit UI start ?
    int _defaultComboBoxIndex; //If i decide to make an input section, what should the default comboBox unit be set to?

    //FONTS DECLERATION, they are defined inside constructor initilizer lsit (inside source file)
    const QFont _aleoFont;
    const QFont _aleoBigFont;

    //This methods generate all the buttons, lineEdits etc.
    void generateInputSection(const QFont &inputFont);
    void generateLineEdits();
    virtual void convertValues(int unitIndex, QString valueString) = 0; //Abstract function for each type of child converter

signals:

private slots:

};

#endif // ABSTRACTCONVERTER_H

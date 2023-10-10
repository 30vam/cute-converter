#ifndef ABSTRACTCONVERTER_H
#define ABSTRACTCONVERTER_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFont>

class AbstractConverter : public QWidget
{
    Q_OBJECT

public:
    //Constructor, intitilizer list is inside source file
    explicit AbstractConverter(QList<QPair<QString, double>> unitList, QString conversionType, QWidget *parent = nullptr, int defaultComboBoxUnit = 0);

protected:
    //Field names start with _ to differentiate them from local variables
    QList<QPair<QString, double>> _unitList;  //List of units that is different for each child object, so it's a protected member

private:
    //Class members
    QList<QLineEdit *> _outputLineEditList; //List that stores the dynamically generated LineEdits inside the currentconverter page
    QGridLayout *_converterGridLayout; //??? should be a way to remove it
    QString _conversionType; //The name of the conversion e.g. "Length"
    const int _outputStartingRow = 2; //In which row should lineEdit UI start ?
    int _defaultComboBoxUnit; //If i decide to make an input section, what should the default comboBox unit be set to?

    //FONTS DECLERATION, they are defined inside constructor initilizer lsit (inside source file)
    const QFont _aleoFont;
    const QFont _aleoBigFont;

    //This methods generate all the buttons, lineEdits etc.
    void generateInputSection(QGridLayout *converterGridLayout, QString &conversionType, QList<QPair<QString, double>> &unitList, const QFont &inputFont);
    void generateOutputSection(QGridLayout *converterGridLayout, QList<QLineEdit *> &outputLineEditList, QList<QPair<QString, double>> &unitList);
    virtual void convertValues(int unitIndex, QString valueString, QList<QLineEdit *> &outputLineEditList) = 0; //Abstract function for each type of child converter

signals:

private slots:

};

#endif // ABSTRACTCONVERTER_H

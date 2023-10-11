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
    QList<QPair<QString, double>> m_unitList;  //List of units that is different for each child object, so it's a protected member
    QList<QLineEdit *> m_lineEditList; //List that stores the dynamically generated LineEdits inside the currentconverter page

private:
    //Class members
    QGridLayout *m_converterGridLayout = new QGridLayout(this); //The layout for each converter (is inside ScrollArea)
    QValidator *m_inputValidator = new QDoubleValidator(this); //This validator let's us allow ONLY doubles inside LineEdits
    QString m_conversionType; //The name of the conversion e.g. "Length"
    const int m_outputStartingRow = 0; //In which row should lineEdit UI start ?
    int m_defaultComboBoxIndex; //If i decide to make an input section, what should the default comboBox unit be set to?

    //FONTS DECLERATION, they are defined inside constructor initilizer lsit (inside source file)
    const QFont m_aleoFont;
    const QFont m_aleoBigFont;

    //This methods generate all the buttons, lineEdits etc.
    void generateInputSection(const QFont &inputFont);
    void generateLineEdits();
    virtual void convertValues(int unitIndex, QString valueString) = 0; //Abstract function for each type of child converter

signals:

private slots:

};

#endif // ABSTRACTCONVERTER_H

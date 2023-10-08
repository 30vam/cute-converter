#ifndef ABSTRACTCONVERTER_H
#define ABSTRACTCONVERTER_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

class AbstractConverter : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractConverter(QList<QPair<QString, double>> unitList, QString conversionType, int defaultComboBoxUnit, QWidget *parent = nullptr);

protected:
    QList<QPair<QString, double>> unitList;

private:
    //FONTS
    QFont exoFont;
    QFont dosisFont;
    QFont dosisBoldFont;
    QFont aleoFont;

    //Class members

    QList<QLineEdit *> outputLineEditList; //List of the generated output LineEdits inside the current widget page
    QString conversionType;
    QGridLayout *converterGridLayout;

    int outputStartingRow;
    int defaultComboBoxUnit;

    //This methods generate all the buttons, lineEdits etc.
    void generateInputSection(QGridLayout *converterGridLayout, QString &conversionType, QList<QPair<QString, double>> &unitList, QFont &inputFont);
    void generateOutputSection(QGridLayout *converterGridLayout, QList<QLineEdit *> &outputLineEditList, QList<QPair<QString, double>> &unitList);

    //Abstract function for each type of converter
    virtual void convertValues(int unitIndex, QString valueString, QList<QLineEdit *> &outputLineEditList) = 0;

signals:

private slots:

};

#endif // ABSTRACTCONVERTER_H

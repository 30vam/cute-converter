#ifndef ABSTRACTCONVERTER_H
#define ABSTRACTCONVERTER_H

#include <QWidget>
#include <QGridLayout>
#include <QPair>

class AbstractConverter : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractConverter(QWidget *parent = nullptr);

private:
    //FONTS
    QFont exoFont;
    QFont dosisFont;
    QFont dosisBoldFont;
    QFont aleoFont;

    //OTHER MEMBERS
    QList<QPair<QString, double>> unitList;
    QString conversionType;
    QGridLayout *converterGridLayout;
    int outputStartingRow;
    int defaultComboBoxUnit;

    //This methods generats all the buttons, lineEdits etc.
    void generateInputSection(QGridLayout *converterGridLayout, QString &conversionType, QList<QPair<QString, double>> &unitList, QFont &inputFont);
    void generateOutputSection(QGridLayout *converterGridLayout, QList<QPair<QString, double>> &unitList);

signals:
    //Abstract function for each type of converter
    //virtual void convertValues() = 0;

};

#endif // ABSTRACTCONVERTER_H

#ifndef ABSTRACTCONVERTER_H
#define ABSTRACTCONVERTER_H

#include <QWidget>
#include <QGridLayout>

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

    //Declaration of members that are unique to each converter.
    QList<QString> unitList;
    QString conversionType;
    QGridLayout *converterGridLayout;
    int outputStartingRow;

    //This method generates all the buttons, lineEdits etc.
    void generateInputSection(QGridLayout *converterGridLayout, QString &conversionType, QList<QString> &unitList, QFont &inputFont);
    void generateOutputSection(QGridLayout *converterGridLayout, QList<QString> &unitList);

signals:
    //Abstract function for each type of converter
    //virtual void convertValues() = 0;

};

#endif // ABSTRACTCONVERTER_H

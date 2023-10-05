#ifndef ABSTRACTCONVERTER_H
#define ABSTRACTCONVERTER_H

#include <QWidget>

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

    //This method generates all the buttons, lineEdits etc.
    void generateConverterUI(QList<QString> unitList, QString conversionType, QFont inputFont);

signals:
    //Abstract function for each type of converter
    //virtual void convertValues() = 0;

};

#endif // ABSTRACTCONVERTER_H

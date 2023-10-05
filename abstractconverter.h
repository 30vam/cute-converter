#ifndef ABSTRACTCONVERTER_H
#define ABSTRACTCONVERTER_H

#include <QWidget>

class AbstractConverter : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractConverter(QWidget *parent = nullptr);

private:
    //Declaration of members that are unique to each converter.
    QList<QString> unitList;

    //This method generates all the buttons, lineEdits etc.
    void generateAllUnits(AbstractConverter *converterObject);

signals:

};

#endif // ABSTRACTCONVERTER_H

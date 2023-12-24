#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QModelIndex>
#include <QFont>

class DataModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);

private:
    QFont m_itemFont;

signals:
    void modelDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
};

#endif // DATAMODEL_H

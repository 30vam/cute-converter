#include "datamodel.h"

DataModel::DataModel(QObject *parent)
    : QObject{parent}
{
    m_model = new QStandardItemModel();

    //Generate the model
    QStandardItem *testItem = new QStandardItem("TEST");
    QStandardItem *testItem1 = new QStandardItem("TEST1");
    QStandardItem *testItem2 = new QStandardItem("TEST2");
    QStandardItem *testItem3 = new QStandardItem("TEST3");
    QStandardItem *testItem4 = new QStandardItem("TEST4");
    QStandardItem *testItem5 = new QStandardItem("TEST5");
    QStandardItem *testItem6 = new QStandardItem("TEST6");
    QStandardItem *testItem7 = new QStandardItem("TEST7");
    QStandardItem *testItem8 = new QStandardItem("TEST8");
    QStandardItem *testItem9 = new QStandardItem("TEST9");
    QStandardItem *testItem10 = new QStandardItem("TEST10");
    m_model->appendRow(testItem);
    m_model->appendRow(testItem1);
    m_model->appendRow(testItem2);
    m_model->appendRow(testItem3);
    m_model->appendRow(testItem4);
    m_model->appendRow(testItem5);
    m_model->appendRow(testItem6);
    m_model->appendRow(testItem7);
    m_model->appendRow(testItem8);
    m_model->appendRow(testItem9);
    m_model->appendRow(testItem10);

    //Signals and slots
    connect(m_model, &QStandardItemModel::dataChanged, this, &DataModel::modelDataChanged);
}

//Getters and setters
QStandardItemModel *DataModel::getModel()
{
    return m_model;
}

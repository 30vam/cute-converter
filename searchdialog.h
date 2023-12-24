#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
#include <QIcon>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "datamodel.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT
private:
    QPushButton *m_searchButton;
    QIcon m_goToIcon;
    QStringList m_searchStringList;
    DataModel m_dataModel;
    QModelIndex m_firstIndex;
    QModelIndex m_lastIndex;

    Ui::SearchDialog *ui;

public:
    explicit SearchDialog(DataModel *dataModel, QWidget *parent = nullptr);
    ~SearchDialog();

    //Getters and setters

private slots:
    void modelDataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void on_searchButtonBox_clicked(QAbstractButton *button);
    void on_searchLineEdit_textChanged(const QString &arg1);

signals:
    void searchSelected(QString searchedItemText);  //Signal enmits when user clicks on the "Go to" button

};

#endif // SEARCHDIALOG_H

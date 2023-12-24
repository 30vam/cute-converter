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
    QList <QStandardItem *> m_searchResultList;
    DataModel m_dataModel;

    Ui::SearchDialog *ui;

public:
    explicit SearchDialog(DataModel *dataModel, QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void onModelDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void on_searchButtonBox_clicked(QAbstractButton *button);
    void on_searchLineEdit_textChanged(const QString &arg1);

signals:
    void searchSelected(QString searchedItemText);  //Signal enmits when user clicks on the "Go to" button

};

#endif // SEARCHDIALOG_H

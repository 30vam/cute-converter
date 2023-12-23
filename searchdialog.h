#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_Hs

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
#include <QIcon>
#include <QStandardItemModel>

#include "datamodel.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(DataModel *dataModel, QWidget *parent = nullptr);
    ~SearchDialog();

    //Getters and setters
    int getSearchedItemIndex();

private slots:
    void modelDataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void on_searchButtonBox_clicked(QAbstractButton *button);

    void on_searchListView_clicked(const QModelIndex &index);

private:
    int m_searchedItemIndex;

    QPushButton *m_searchButton;
    QIcon m_goToIcon;
    QStringList m_searchStringList;
    DataModel m_dataModel;
    QModelIndex m_firstIndex;
    QModelIndex m_lastIndex;

    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H

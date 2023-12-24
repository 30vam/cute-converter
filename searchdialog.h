#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
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
private:
    QPushButton *m_searchButton;
    QStandardItemModel *m_searchResultModel;
    QIcon m_goToIcon;
    DataModel m_dataModel;
    QFont m_searchResultFont;

    Ui::SearchDialog *ui;

public:
    explicit SearchDialog(DataModel *dataModel, QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void on_searchButtonBox_clicked(QAbstractButton *button);
    void on_searchLineEdit_textChanged(const QString &arg1);

signals:
    void searchSelected(QString searchedItemText);  //Signal enmits when user clicks on the "Go to" button

};

#endif // SEARCHDIALOG_H

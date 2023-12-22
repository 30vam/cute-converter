#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
#include <QIcon>
#include <QStandardItemModel>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QStandardItemModel *converterItemModel, QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void on_searchButtonBox_clicked(QAbstractButton *button);

private:
    QPushButton *m_searchButton;
    QIcon m_goToIcon;
    QStringList m_searchStringList;

    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H

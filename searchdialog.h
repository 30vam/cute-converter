#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void on_searchButtonBox_clicked(QAbstractButton *button);

private:
    QPushButton *searchButton;
    QIcon goToIcon;

    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H

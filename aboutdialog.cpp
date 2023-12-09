#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QLayout>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());  //Locked dialog size
    this->setWindowTitle("About");  //Dialog name
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

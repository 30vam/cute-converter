#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    //Variables
    goToIcon = QIcon("://icons/go_to_icon.jpg");
    searchButton = new QPushButton(goToIcon, "Go To", this);


    this->setWindowTitle("Search Converters : ");
    ui->searchButtonBox->addButton(searchButton, QDialogButtonBox::AcceptRole);

}

SearchDialog::~SearchDialog()
{
    delete ui;
}

//Slots ----------------------------------------------------------------------------------

void SearchDialog::on_searchButtonBox_clicked(QAbstractButton *button)
{
    if(button == searchButton)  //When clicked on the search button
    {

    }
}


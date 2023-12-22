#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QStandardItemModel *converterItemModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    //Variables
    m_goToIcon = QIcon("://icons/go_to_icon.jpg");
    m_searchButton = new QPushButton(m_goToIcon, "Go To", this);

    //Set up UI
    this->setWindowTitle("Search Converters : ");
    ui->searchButtonBox->addButton(m_searchButton, QDialogButtonBox::AcceptRole);

    //Search List


}

SearchDialog::~SearchDialog()
{
    delete ui;
}

//Slots ----------------------------------------------------------------------------------

void SearchDialog::on_searchButtonBox_clicked(QAbstractButton *button)
{
    if(button == m_searchButton)  //When clicked on the search button
    {

    }
}


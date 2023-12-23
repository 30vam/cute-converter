#include "searchdialog.h"
#include "ui_searchdialog.h"

#include <QDebug>

SearchDialog::SearchDialog(DataModel *dataModel, QWidget *parent) :
    QDialog(parent), m_dataModel(dataModel),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    //Variables
    m_goToIcon = QIcon("://icons/go_to_icon.jpg");
    m_searchButton = new QPushButton(m_goToIcon, "Go To", this);

    //Set up UI
    this->setFixedSize(this->size());  //Locked dialog size
    this->setWindowTitle("Search Converters : ");
    ui->searchLineEdit->setPlaceholderText("Search all converters...");
    ui->searchButtonBox->addButton(m_searchButton, QDialogButtonBox::ApplyRole);

    //Signals and slots
    connect(&m_dataModel, &DataModel::modelDataChanged, this, &SearchDialog::modelDataChangedSlot);

    //Emit a signal when the search window opens, so that it creates the itemList
    emit m_dataModel.modelDataChanged(m_firstIndex, m_lastIndex);  //first and last index are empty for now, because I dont think they are needed for now
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

//Slots ------------------------------------------------------------------------------------------------
void SearchDialog::modelDataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    QStandardItemModel *model = m_dataModel.getModel();
    ui->searchListView->setModel(model);
}

void SearchDialog::on_searchButtonBox_clicked(QAbstractButton *button)
{
    if(button == m_searchButton && ui->searchListView->selectionModel()->hasSelection())  //When clicked on the search button AND an item is selected
    {
        int searchedItemIndex = m_dataModel.getModel()->data(ui->searchListView->currentIndex(), Qt::UserRole).toInt();
        QString searchedItemText = m_dataModel.getModel()->data(ui->searchListView->currentIndex(), Qt::DisplayRole).toString();
        emit searchSelected(searchedItemText);
        close();

        //Test
        qDebug() << searchedItemIndex << searchedItemText << "was searched.";
    }
}

//Getters and setters  ----------------------------------------------------------------------------------

//SLOTS -------------------------------------------------------------------------------------------------
void SearchDialog::on_searchListView_clicked(const QModelIndex &index) //When user clicks on an item
{
    int searchedItemIndex = m_dataModel.getModel()->data(index, Qt::UserRole).toInt();
    QString searchedItemText = m_dataModel.getModel()->data(index, Qt::DisplayRole).toString();

    //Test
    qDebug() << searchedItemIndex << searchedItemText<< "was selected.";
}


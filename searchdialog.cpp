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
    m_searchResultModel = new QStandardItemModel(this);
    m_searchResultFont = m_dataModel.item(0, 0)->font();  //Get the font that full datamodel uses

    //Set up UI
    this->setFixedSize(this->size());  //Locked dialog size
    this->setWindowTitle("Search Converters : ");
    ui->searchLineEdit->setPlaceholderText("Search all converters...");
    ui->searchButtonBox->addButton(m_searchButton, QDialogButtonBox::ApplyRole);

    //set the model at start to the full model
    ui->searchListView->setModel(&m_dataModel);
}

//Deconstructor
SearchDialog::~SearchDialog()
{
    delete ui;
}

//SLOTS ------------------------------------------------------------------------------------------------
void SearchDialog::on_searchButtonBox_clicked(QAbstractButton *button)  //When user clicks on one of the buttons in the buttonBox (There is only 1 button atm):
{
    if(button == m_searchButton && ui->searchListView->selectionModel()->hasSelection())  //When clicked on the search button AND an item is selected
    {
        QString searchedItemText;
        QAbstractItemModel *currentModel = ui->searchListView->model();

        if(currentModel == &m_dataModel)  //If the view is using the FULL model, send a signal with the string from the FULL model:
            searchedItemText = m_dataModel.data(ui->searchListView->currentIndex(), Qt::DisplayRole).toString();
        else if(currentModel == m_searchResultModel)  //If the view is using a search model, send a signal with the string from the SEARCH model:
            searchedItemText = m_searchResultModel->data(ui->searchListView->currentIndex(), Qt::DisplayRole).toString();

        emit searchSelected(searchedItemText);  //This activates a slot in mainwindow.cpp
        close();  //Don't forget to close the search window after we're done
    }
}

void SearchDialog::on_searchLineEdit_textChanged(const QString &searchText)  //When a search expression is entered in the linEdit:
{
    m_searchResultModel->removeRows(0, m_searchResultModel->rowCount());  //Remove all the items in the searchResultModel so its empty at the start
    ui->searchListView->selectionModel()->clearSelection();  //Clear the previously selected item

    //Iterate through all items in the model to find the search expression, only if the new searchText is not an empty string
    if(searchText != "")
    {
        for (int row = 0; row < m_dataModel.rowCount(); row++)
        {
                QModelIndex currentIndex = m_dataModel.index(row, 0);  //Which index are we iterating through? (all items are in column 0)
                QString currentText = m_dataModel.data(currentIndex, Qt::DisplayRole).toString();

                if(currentText.contains(searchText, Qt::CaseInsensitive))  //Add items that contain the searchText to a QStringList
                {
                    QStandardItem *newSearchResultItem = new QStandardItem(currentText);
                    m_searchResultModel->appendRow(newSearchResultItem);
                }
        }

        ui->searchListView->setModel(m_searchResultModel);  //Only Show the search results in the ListView (Which are the items of m_searchResultModel).

        if(m_searchResultModel->rowCount() > 0)  //Check if any items were found by the search (To avoid out of range error)
            ui->searchListView->setCurrentIndex(m_searchResultModel->index(0, 0));  //Set the current item to the FIRST found searched item

        //Test
        qDebug() << m_searchResultModel->rowCount() << "results were found for" << searchText << ":";

        //Change font etc. for all search result
        for (int row = 0; row < m_searchResultModel->rowCount(); row++)
        {
            QStandardItem *currentItem = m_searchResultModel->item(row, 0);  //Which item are we iterating through right now?
            currentItem->setFont(m_searchResultFont);
            currentItem->setEditable(false);  //Remove item editting ability from use

            //Test
            qDebug() << m_searchResultModel->item(row, 0)->text();
        }

    }
    else  //If the string was empty, just show all items again
        ui->searchListView->setModel(&m_dataModel);
}

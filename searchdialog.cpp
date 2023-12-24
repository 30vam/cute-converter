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

//SLOTS ------------------------------------------------------------------------------------------------
void SearchDialog::modelDataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight)  //This slot refreshes the ListView data
{
    QStandardItemModel *model = m_dataModel.getModel();
    ui->searchListView->setModel(model);
}

void SearchDialog::on_searchButtonBox_clicked(QAbstractButton *button)
{
    if(button == m_searchButton && ui->searchListView->selectionModel()->hasSelection())  //When clicked on the search button AND an item is selected
    {
        int searchedItemIndex =
            m_dataModel.getModel()->data(ui->searchListView->currentIndex(), Qt::UserRole).toInt();
        QString searchedItemText = m_dataModel.getModel()->data(ui->searchListView->currentIndex(), Qt::DisplayRole).toString();
        emit searchSelected(searchedItemText);
        close();

        //Test
        qDebug() << searchedItemIndex << searchedItemText << "was searched.";
    }
}

void SearchDialog::on_searchLineEdit_textChanged(const QString &searchText)  //When a search expression is entered
{
    int matchCount = 0;
    QList<QStandardItem *> searchResultList;  //This list stores all found search results

    ui->searchListView->selectionModel()->clearSelection();  //Clear the previously selected item

    //Iterate through all items to find the search expression, only if the new searchText is not an empty string
    if(searchText != "")
    {
        for (int row = 0; row < m_dataModel.getModel()->rowCount(); row++)
        {
            for (int column = 0; column < m_dataModel.getModel()->columnCount(); column++)
            {
                QModelIndex currentIndex = m_dataModel.getModel()->index(row, column);  //Which index are we iterating through?
                QString currentText = m_dataModel.getModel()->data(currentIndex, Qt::DisplayRole).toString();

                if(currentText.contains(searchText, Qt::CaseInsensitive))  //Add items that containt the searchText to an itemList
                {
                    matchCount++;
                    searchResultList.append(m_dataModel.getModel()->itemFromIndex(currentIndex));
                }
            }
        }
        if(searchResultList.count() > 0)  //Check if any items were found by the search (To avoid out of range error)
            ui->searchListView->setCurrentIndex(searchResultList.at(0)->index());  //Set the current item to the FIRST found searched item

        //Test
        qDebug() << matchCount << "results were found for" << searchText << ":";
        foreach (QStandardItem *item, searchResultList) {
            qDebug() << item->text();
        }
    }
}


//Getters and setters  ----------------------------------------------------------------------------------

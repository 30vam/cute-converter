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
    connect(&m_dataModel, &DataModel::modelDataChanged, this, &SearchDialog::onModelDataChanged);

    //Emit a signal when the search window opens, so that it creates the itemList
    emit m_dataModel.modelDataChanged(QModelIndex(), QModelIndex());  //first and last index are empty for now, because I dont think they are neededs
}

//Deconstructor
SearchDialog::~SearchDialog()
{
    delete ui;
}

//SLOTS ------------------------------------------------------------------------------------------------
void SearchDialog::onModelDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)  //This slot refreshes the ListView data
{
    QStandardItemModel *model = m_dataModel.getModel();
    ui->searchListView->setModel(model);
}

void SearchDialog::on_searchButtonBox_clicked(QAbstractButton *button)
{
    if(button == m_searchButton && ui->searchListView->selectionModel()->hasSelection())  //When clicked on the search button AND an item is selected
    {
        QStandardItemModel *model = m_dataModel.getModel();
        QString searchedItemText = model->data(ui->searchListView->currentIndex(), Qt::DisplayRole).toString();

        emit searchSelected(searchedItemText);  //This activates a slot in mainwindow.cpp
        close();  //Don't forget to close the search window after we're done
    }
}

void SearchDialog::on_searchLineEdit_textChanged(const QString &searchText)  //When a search expression is entered
{
    int matchCount = 0;
    QList<QStandardItem *> searchResultList;  //This list stores all found search results
    QStandardItemModel *model = m_dataModel.getModel();

    ui->searchListView->selectionModel()->clearSelection();  //Clear the previously selected item

    //Iterate through all items in the model to find the search expression, only if the new searchText is not an empty string
    if(searchText != "")
    {
        for (int row = 0; row < model->rowCount(); row++)
        {
                QModelIndex currentIndex = model->index(row, 0);  //Which index are we iterating through? (all items are in column 0)
                QString currentText = model->data(currentIndex, Qt::DisplayRole).toString();

                if(currentText.contains(searchText, Qt::CaseInsensitive))  //Add items that contain the searchText to a QStringList
                {
                    matchCount++;
                    searchResultList.append(model->itemFromIndex(currentIndex));
                }
        }

        if(searchResultList.count() > 0)  //Check if any items were found by the search (To avoid out of range error)
            ui->searchListView->setCurrentIndex(searchResultList.at(0)->index());  //Set the current item to the FIRST found searched item

        //Test
        qDebug() << matchCount << "results were found for" << searchText << ":";
        //Print all found results
        foreach (QStandardItem *item, searchResultList) {
            qDebug() << item->text();
        }
    }
}

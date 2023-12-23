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
    ui->searchButtonBox->addButton(m_searchButton, QDialogButtonBox::AcceptRole);

    //Signals and slots
    connect(&m_dataModel, &DataModel::modelDataChanged, this, &SearchDialog::modelDataChangedSlot);

    //Emit a signal when the search window opens
    emit m_dataModel.modelDataChanged(m_firstIndex, m_lastIndex);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

//Slots ----------------------------------------------------------------------------------
void SearchDialog::modelDataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    QStandardItemModel *model = m_dataModel.getModel();
    ui->searchListView->setModel(model);
}

void SearchDialog::on_searchButtonBox_clicked(QAbstractButton *button)
{
    if(button == m_searchButton)  //When clicked on the search button
    {
        m_searchedItemIndex = m_dataModel.getModel()->data(ui->searchListView->currentIndex(), Qt::UserRole).toInt();
        qDebug() << m_searchedItemIndex << "was searched.";
    }
}

//Getters and setters
int SearchDialog::getSearchedItemIndex()
{
    return m_searchedItemIndex;
}

//When user clicks on an item
void SearchDialog::on_searchListView_clicked(const QModelIndex &index)
{
    int selectedIndex = m_dataModel.getModel()->data(index, Qt::UserRole).toInt();
    qDebug() << selectedIndex << "was selected.";
}


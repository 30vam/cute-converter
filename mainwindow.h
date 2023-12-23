#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QStandardItemModel>

#include "aboutdialog.h"
#include "searchdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Getters and setters

private:
    int m_basicPageIndex;
    int m_scientificPageIndex;
    int m_miscPageIndex;
    int m_totalWidgetCount;
    QStandardItemModel *m_treeWidgetModel;
    DataModel *m_quantityDataModel;

    //Methods
    void getItemModel();

    AboutDialog *m_aboutPage;  //About page instance
    SearchDialog *m_searchDialog;
;

    Ui::MainWindow *ui;

signals:
    void modelDataChanged();

private slots:
    void on_conversionTypeTreeWidget_itemSelectionChanged();
    void on_switchToLengthAction_triggered();
    void on_switchToAreaAction_triggered();
    void on_switchToVolumeAction_triggered();
    void on_switchToWeightAction_triggered();
    void on_switchToTemperatureAction_triggered();
    void on_switchToTimeAction_triggered();
    void on_switchToSpeedAction_triggered();
    void on_switchToPressureAction_triggered();
    void on_switchToForceAction_triggered();
    void on_switchToEnergyAction_triggered();
    void on_switchToPowerAction_triggered();
    void on_switchToCurrentAction_triggered();
    void on_switchToVoltageAction_triggered();
    void on_aboutAction_triggered();
    void on_switchToTorqueAction_triggered();
    void on_switchToVolumetricFlowRateAction_triggered();
    void on_switchToDensityAction_triggered();
    void on_switchToViscosityAction_triggered();
    void on_switchToMagneticFluxDensityAction_triggered();
    void on_switchToConcentrationAction_triggered();
    void on_searchAction_triggered();
    void on_favoriteAction_triggered();
    void on_switchToAngleAction_triggered();
    void on_switchToDataStorageAction_triggered();
    void on_switchToFuelConsumptionAction_triggered();
    void on_nextAction_triggered();
    void on_previousAction_triggered();
    void on_conversionStackedWidget_currentChanged(int arg1);
    void on_switchToLuminanceAction_triggered();
};
#endif // MAINWINDOW_H

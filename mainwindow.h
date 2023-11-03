#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    int indexOfItemInParent;
    int indexOfParent;
    Ui::MainWindow *ui;

private slots:
    void on_conversionTypeTreeWidget_itemSelectionChanged();
    void on_switchToLengthAction_triggered();
    void on_switchToAreaAction_triggered();
    void on_switchToVolumeAction_triggered();
    void on_switchToWeightAction_triggered();
    void on_switchToTemperatureAction_triggered();
    void on_switchToTimeAction_triggered();
};
#endif // MAINWINDOW_H

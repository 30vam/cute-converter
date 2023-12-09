#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Stylesheets
    //Load the external stylesheet files
    //Darkmode
    QFile darkModeFile("://dark-style.css");
    darkModeFile.open(QFile::ReadOnly);
    QString darkModeString = QLatin1String(darkModeFile.readAll());
    //Modern
    QFile modernFile("://CadWin Light Deep Cerulean.qss");
    darkModeFile.open(QFile::ReadOnly);
    QString modernString = QLatin1String(darkModeFile.readAll());

    //Apply the stylesheet
    a.setStyleSheet(modernString);

    //Translator
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "qt-unit-converter_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}

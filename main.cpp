#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Fonts database
    QFontDatabase::addApplicationFont("://fonts/Aleo-Medium.ttf");
    QFontDatabase::addApplicationFont("://fonts/Aleo-Regular.ttf");
    QFontDatabase::addApplicationFont("://fonts/Aleo-Bold.ttf");
    QFontDatabase::addApplicationFont("://fonts/Aleo-Light.ttf");
    QFontDatabase::addApplicationFont("://fonts/Aleo-Thin.ttf");

    //Stylesheets
    //Load the external stylesheet files
    QFile modernFile("://modern.qss");
    modernFile.open(QFile::ReadOnly);
    QString modernString = QLatin1String(modernFile.readAll());

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

#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("QtLanguage_ru_RU",".");

    MainWindow w;
    w.show();
    return a.exec();
}

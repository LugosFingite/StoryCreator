/*  main.cpp  - Yann BOUCHER (yann) 19/06/2017
**
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**                    Version 2, December 2004
**
** Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
**
** Everyone is permitted to copy and distribute verbatim or modified
** copies of this license document, and changing it is allowed as long
** as the name is changed.
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
**
**  0. You just DO WHAT THE FUCK YOU WANT TO.
*/
#include "mainwindow.hpp"

#include <stdexcept>
#include <iostream>

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    try
    {
        MainWindow w;
        w.show();

        return a.exec();
    }
    catch (const std::exception& e)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur critique lors de l'exécution : ") + e.what());
        std::cerr << "Critical execution error : " << e.what() << "\n";
        return -1;
    }
    catch (...)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur inconnue ! (vraiment ! wtf ?)"));
        std::cerr << "Unknown exception type thrown !\n";
        return -2;
    }
}

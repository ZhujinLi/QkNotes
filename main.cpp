#include "pch.h"
#include "qknotes.h"
#include <QApplication>
#include <QDir>
#include <QMainWindow>
#include <QStandardPaths>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    g_dataDir = QStandardPaths::standardLocations(QStandardPaths::StandardLocation::DataLocation)[0];
    QDir().mkpath(g_dataDir);

    QkNotes qkNotes;
    qkNotes.show();

    return a.exec();
}

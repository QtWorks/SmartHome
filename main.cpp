#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file(":/catalog.css");
    if (file.open(QIODevice::ReadOnly))
    {
        app.setStyleSheet(file.readAll());
        file.close();
    }

    MainWindow w;
    w.show();

    return app.exec();
}

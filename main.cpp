#include <QApplication>
#include <QMainWindow>

#include<QObject>
#include "header.h"

int main (int argc, char** argv)
{
    QApplication        app(argc, argv);
    mainWindow          mw;

    return app.exec();
}

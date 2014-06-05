#include <QApplication>
#include "header.h"

int main (int argc, char** argv)
{
    QApplication        app(argc, argv);
    mainWindow          mw;
    return app.exec();
}

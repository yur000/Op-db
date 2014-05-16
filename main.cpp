#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include "header.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QLabel      lbl("Zeeeeerrrrooo");
    QPushButton cmd("ADD");
    QPushButton cmd2("ADD33");
    Counter     counter;
    cmd.show();
    lbl.show();
    cmd2.show();

    QObject::connect(&cmd, SIGNAL(clicked()),
                     &counter, SLOT(slotInc())
                    );
    QObject::connect(&cmd2, SIGNAL(clicked()),
                     &counter, SLOT(slotInc())
                    );

    QObject::connect(&counter, SIGNAL(counterChanged(int)),
                     &lbl, SLOT(setNum(int))
                    );

    QObject::connect(&counter, SIGNAL(goodbye()),
                     &app, SLOT(quit())
                    );
    return app.exec();
}

#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QTableWidget>
#include <QStringList>
#include <QMenu>
#include "header.h"

int main (int argc, char** argv)
{
    int n = 3;
    QApplication        app(argc, argv);
    QWidget             mainWindow;
    QLayout             *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    QTableWidget        table(n, n);
    QTableWidgetItem    *ptwi;
    QStringList         strList;

    strList << "Number" << "Balance" << "Internet";
    table.setHorizontalHeaderLabels(strList);
    for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
    ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
    table.setItem(i, j, ptwi);
    }
    }

    layout->addWidget(&table);
    mainWindow.setLayout(layout);
    mainWindow.show();

    return app.exec();
}

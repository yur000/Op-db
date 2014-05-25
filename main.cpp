#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QTableWidget>
#include <QStringList>
#include <QMenu>
#include <QCheckBox>
#include "header.h"

int main (int argc, char** argv)
{
    int n = 5;
    QApplication        app(argc, argv);
    QWidget             mainWindow;
    QLayout             *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    QTableWidget        table(n, n);
    QCheckBox           *chkbox;
    QTableWidgetItem    *ptwi;
    QStringList         strList;

    strList << "Number" << "Balance" << "Tarif" << "Internet" << "Blocked";
    //TEST
    table.setHorizontalHeaderLabels(strList);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j!=4) {
                ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
                table.setItem(i, j, ptwi);
            }
            else {
                chkbox = new QCheckBox;
                table.setCellWidget(i, j, chkbox);
            }
        }
    }

    layout->addWidget(&table);
    mainWindow.resize(550,300);
    mainWindow.setLayout(layout);
    mainWindow.show();

    return app.exec();
}

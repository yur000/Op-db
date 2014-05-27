#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QTableWidget>
#include <QStringList>
#include <QMenu>
#include <QCheckBox>
#include<QObject>
#include "header.h"

int main (int argc, char** argv)
{
    int n = 5;
    QApplication        app(argc, argv);
    QWidget             mainWindow;
    QLabel              *lbl = new QLabel("qqqq");
    QLayout             *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    QTableWidget        *tbl=new QTableWidget(&mainWindow);
    QCheckBox           *chkbox;
    QTableWidgetItem    *ptwi;
    QStringList         strList;
    Counter             cnt;

    strList << "Number" << "Balance" << "Tarif" << "Internet" << "Blocked";
    //TEST
    tbl->setRowCount(n);
    tbl->setColumnCount(n);
    tbl->setHorizontalHeaderLabels(strList);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j!=4) {
                ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
                tbl->setItem(i, j, ptwi);
            }
            else {
                chkbox = new QCheckBox;
                tbl->setCellWidget(i, j, chkbox);
            }
        }
    }

    layout->addWidget(tbl);
    layout->addWidget(lbl);
    mainWindow.resize(550,300);
    mainWindow.setLayout(layout);
    mainWindow.show();

    QObject::connect(tbl, SIGNAL(cellChanged(int,int)),
                     &cnt, SLOT(slotInc()));
    QObject::connect(&cnt, SIGNAL(counterChanged(int)),
                             lbl, SLOT(setNum(int)));

    return app.exec();
}

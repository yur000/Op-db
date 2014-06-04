#ifndef HEADER_H
#define HEADER_H

#include <QObject>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QTableWidget>
#include <QStringList>
#include <QMenu>
#include <QCheckBox>
#include <QMap>
#include "element.h"

class Counter : public QObject {
    Q_OBJECT
private:
    int m_nValue;

public:
    Counter();

public slots:
    void slotInc();

signals:
    void goodbye       (   );
    void counterChanged(int);
};

class mainWindow : public QWidget {
    Q_OBJECT
private:
    QLabel                            *lbl;
    QTableWidget                      *tbl;
    QCheckBox                         *chkbox;
    QTableWidgetItem                  *ptwi;
    QStringList                       strList;
    QPushButton                       *add;
    QPushButton                       *close;
    Counter                           cnt;
    QLayout                           *layout;
    QLayout                           *layoutbut;
    QMap<QString, element>            numbers;
    QMap<QString, element>::iterator  *iter;
public:
    mainWindow(QWidget* pwgt = 0);
    virtual ~mainWindow();
private slots:
    void changed(int,int);
};

#endif // HEADER_H

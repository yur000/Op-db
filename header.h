#ifndef HEADER_H
#define HEADER_H

#include <QObject>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QTableWidget>
#include <QStringList>
#include <QCheckBox>
#include <QMap>
#include <QIntValidator>
#include <QItemDelegate>
#include "element.h"
#include "balanceWindow.h"

class mainWindow : public QWidget {
    Q_OBJECT
private:
    QTableWidget                      *tbl;
    QCheckBox                         *chkbox;
    QTableWidgetItem                  *ptwi;
    QStringList                       strList;
    QPushButton                       *addBalance;
    QPushButton                       *close;
    QPushButton                       *reflesh;
    QLayout                           *layout;
    QLayout                           *layoutbut;
    balanceWindow                     *balWind;
    QMap<QString, element>            numbers;
    QMap<QString, element>::iterator  iter;
public:
    mainWindow(QWidget* pwgt = 0);
    void pushTable();
    virtual ~mainWindow();
private slots:
    void updateBalance(int,int,int,bool,bool);
    void refleshTable();
    void showbal();
};

class NonEditTableColumnDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    NonEditTableColumnDelegate(QObject * parent = 0) : QItemDelegate(parent) {}
    virtual QWidget * createEditor ( QWidget *, const QStyleOptionViewItem &,
                                     const QModelIndex &) const
    {
        return 0;
    }
};

#endif // HEADER_H

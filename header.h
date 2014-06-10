#ifndef HEADER_H
#define HEADER_H

#include <QFile>
#include <QDataStream>
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
#include"stack.h"
#include"stack.cpp"
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
    QPushButton                       *save;
    QPushButton                       *undo;
    QLayout                           *layout;
    QLayout                           *layoutbut;
    balanceWindow                     *balWind;
    QMap<QString, element>            *numbers;
    QMap<QString, element>            *numbsTmp;
    QMap<QString, element>::iterator  iter;
    Stack< QMap<QString, element> >   *st;
public:
    mainWindow(QWidget* pwgt = 0);
    void pushTable();
    void loadNums();
    bool read_map_bin(QMap<QString, element>&, const QString&);
    bool write_map_bin(QMap<QString, element>&, const QString&);
    virtual ~mainWindow();
private slots:
    void updateBalance(int,int,int,int,int);
    void refleshTable();
    void showbal();
    void undoChange();
    void saveTable();
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

#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QObject>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <element.h>

class balanceWindow : public QWidget {
    Q_OBJECT
private:
    QLabel                            *lbl;
    QCheckBox                         *inet;
    QCheckBox                         *block;
    QPushButton                       *okBut;
    QPushButton                       *close;
    QLayout                           *layout;
    QLayout                           *layoutbut;
    QComboBox                         *comboBox;
    QSpinBox                          *spinBox;
public:
    balanceWindow(QWidget* pwgt = 0);
    void setCBox(const QMap<QString, element>);
    virtual ~balanceWindow();
signals:
    void sendBalance(int, int, bool, bool);
private slots:
    void okPressed();
};

#endif // BALANCEWINDOW_H

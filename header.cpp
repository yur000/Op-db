#include "header.h"

Counter::Counter() : QObject()
                   , m_nValue(0)
{
}

void Counter::slotInc()
{
    emit counterChanged(++m_nValue);

    if (m_nValue == 5) {
        emit goodbye();
    }
}
// ----------------------------------------------------------------------
mainWindow::mainWindow(QWidget* pwgt) {

    lbl         = new QLabel("qqqq");
    add         = new QPushButton("Add");
    close       = new QPushButton("Close");
    tbl         = new QTableWidget(pwgt);
    layout      = new QBoxLayout(QBoxLayout::TopToBottom);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    iter        = new QMap<QString, element>::iterator;
    *iter       = numbers.begin();
    strList     << "Number"
                << "Balance"
                << "Tarif"
                << "Internet"
                << "Blocked";
    //TEST
    int n = 5;


    element *el = new element(111,22,0,1);

    numbers.insert("2000001", *el);

    tbl->setRowCount(numbers.size());
    tbl->setColumnCount(n);
    tbl->setHorizontalHeaderLabels(strList);
    int i=0;
    *iter = numbers.begin();
    for (i=0; i<numbers.size(); i++) {
        ptwi = new QTableWidgetItem(QString(iter->key()));
        tbl->setItem(i, 0, ptwi);

        ptwi = new QTableWidgetItem(QString::number(iter->value().getBalance()));
        tbl->setItem(i, 1, ptwi);

        ptwi = new QTableWidgetItem(QString::number(iter->value().getTarifID()));
        tbl->setItem(i, 2, ptwi);

        chkbox = new QCheckBox;
        chkbox->setChecked(iter->value().isInet());
        tbl->setCellWidget(i, 3, chkbox);

        chkbox = new QCheckBox;
        chkbox->setChecked(iter->value().isBlock());
        tbl->setCellWidget(i, 4, chkbox);
    }

    layoutbut->addWidget(add);
    layoutbut->addWidget(close);
    layout->addItem(layoutbut);
    layout->addWidget(tbl);
    layout->addWidget(lbl);

    this->setLayout(layout);
    this->setMinimumHeight(300);
    this->setMinimumWidth(550);
    this->show();

    connect(tbl, SIGNAL(cellChanged(int,int)),
                       SLOT(changed(int,int)));
    connect(&cnt, SIGNAL(counterChanged(int)),
                             lbl, SLOT(setNum(int)));
    connect(close, SIGNAL(clicked()), SLOT(close()));

}
mainWindow::~mainWindow() {
}

void mainWindow::changed(int i, int j){
    if(j==2) {
        ptwi = tbl->item(i,0);
        *iter = numbers.find(ptwi->text());
        ptwi = tbl->item(i,j);
        iter->value().setTarifID(ptwi->text().toInt());
    }
}

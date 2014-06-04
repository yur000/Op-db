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
    addBalance  = new QPushButton("Add");
    reflesh       = new QPushButton("Reflesh");
    close       = new QPushButton("Close");
    tbl         = new QTableWidget(pwgt);
    layout      = new QBoxLayout(QBoxLayout::TopToBottom);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    strList     << "Number"
                << "Balance"
                << "Tarif"
                << "Internet"
                << "Blocked";
    //TEST

    element *el = new element(111,22,0,1);
    numbers.insert("2000001", *el);
    el = new element(222,32,1,0);
    numbers.insert("6912492", *el);
    el = new element(541,24,1,1);
    numbers.insert("2062492", *el);

    this->pushTable();

    layoutbut->addWidget(addBalance);
    layoutbut->addWidget(reflesh);
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
    connect(close, SIGNAL(clicked()), SLOT(close()));
    connect(reflesh, SIGNAL(clicked()), SLOT(refleshTable()));

}

void mainWindow::pushTable() {
    tbl->setRowCount(numbers.size());
    tbl->setColumnCount(5);
    tbl->setHorizontalHeaderLabels(strList);
    int i = 0;
//    *iter = numbers.begin();
//    iter=iter;
    for (iter = numbers.begin(); iter!=numbers.end(); iter++, i++) {
        ptwi = new QTableWidgetItem(QString(iter.key()));
        tbl->setItem(i, 0, ptwi);

        ptwi = new QTableWidgetItem(QString::number(iter.value().getBalance()));
        tbl->setItem(i, 1, ptwi);

        ptwi = new QTableWidgetItem(QString::number(iter.value().getTarifID()));
        tbl->setItem(i, 2, ptwi);

        chkbox = new QCheckBox;
        chkbox->setChecked(iter.value().isInet());
        tbl->setCellWidget(i, 3, chkbox);

        chkbox = new QCheckBox;
        chkbox->setChecked(iter.value().isBlock());
        tbl->setCellWidget(i, 4, chkbox);
    }
}

void mainWindow::changed(int i, int j){
    if(j==2) {
        ptwi = tbl->item(i,0);
        iter = numbers.find(ptwi->text());
        ptwi = tbl->item(i,j);
        iter.value().setTarifID(ptwi->text().toInt());
    }
}

void mainWindow::refleshTable() {
    this->pushTable();
}

mainWindow::~mainWindow() {
}

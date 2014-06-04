#include "header.h"

mainWindow::mainWindow(QWidget* pwgt) {

    addBalance  = new QPushButton("Manage");
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

    element *el = new element(111,22,0,1);
    numbers.insert("2000001", *el);
    el = new element(222,32,1,0);
    numbers.insert("6912492", *el);
    el = new element(541,24,1,1);
    numbers.insert("7836412", *el);
    el = new element(0,1,0,0);
    numbers.insert("1830684", *el);
    el = new element(9437,30,1,1);
    numbers.insert("3429854", *el);

    this->pushTable();

    layoutbut->addWidget(addBalance);
    layoutbut->addWidget(reflesh);
    layoutbut->addWidget(close);
    layout->addItem(layoutbut);
    layout->addWidget(tbl);

    this->setLayout(layout);
    this->setMinimumHeight(300);
    this->setMinimumWidth(550);
    this->show();

    connect(close, SIGNAL(clicked()), SLOT(close()));
    connect(reflesh, SIGNAL(clicked()), SLOT(refleshTable()));
    connect(addBalance, SIGNAL(clicked()), SLOT(showbal()));
}

void mainWindow::pushTable() {
    int i;
    tbl->setRowCount(numbers.size());
    tbl->setColumnCount(5);
    tbl->setHorizontalHeaderLabels(strList);

    for (i = 0, iter = numbers.begin(); iter!=numbers.end(); iter++, i++) {
        ptwi = new QTableWidgetItem(QString(iter.key()));
        tbl->setItem(i, 0, ptwi);
        tbl->setItemDelegateForColumn(0, new NonEditTableColumnDelegate());

        ptwi = new QTableWidgetItem(QString::number(iter.value().getBalance()));
        tbl->setItem(i, 1, ptwi);
        tbl->setItemDelegateForColumn(1, new NonEditTableColumnDelegate());

        ptwi = new QTableWidgetItem(QString::number(iter.value().getTarifID()));
        tbl->setItem(i, 2, ptwi);
        tbl->setItemDelegateForColumn(2, new NonEditTableColumnDelegate());

        chkbox = new QCheckBox;
        chkbox->setDisabled(1);
        chkbox->setChecked(iter.value().isInet());
        tbl->setCellWidget(i, 3, chkbox);

        chkbox = new QCheckBox;
        chkbox->setDisabled(1);
        chkbox->setChecked(iter.value().isBlock());
        tbl->setCellWidget(i, 4, chkbox);
    }
}

void mainWindow::refleshTable() {
    this->pushTable();
}

void mainWindow::showbal(){
    balWind = new balanceWindow(this);
    balWind->setCBox(numbers);
    balWind->show();
    connect(balWind, SIGNAL(sendBalance(int,int,int,bool,bool)),
            SLOT(updateBalance(int,int,int,bool,bool)));
}

void mainWindow::updateBalance(int line, int sum, int tarif, bool isInet, bool isBlock) {
    iter = numbers.begin();
    iter = iter+line;
    iter.value().setBalance(iter.value().getBalance()+sum);
    if(tarif) iter.value().setTarifID(tarif);
    iter.value().setInet(isInet);
    iter.value().setBlock(isBlock);
    refleshTable();
}

mainWindow::~mainWindow() {
}

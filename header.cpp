#include "header.h"


mainWindow::mainWindow(QWidget* pwgt) {
    addBalance  = new QPushButton("Manage");
    save        = new QPushButton("Save");
    close       = new QPushButton("Close");
    undo        = new QPushButton("Undo");
    tbl         = new QTableWidget(pwgt);
    layout      = new QBoxLayout(QBoxLayout::TopToBottom);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    numbers     = new QMap<QString, element>;
    st          = new Stack< QMap<QString, element> >;
    strList     << "Number"
                << "Balance"
                << "Tarif"
                << "Internet"
                << "Blocked";

    this->loadNums();
    this->pushTable();

    layoutbut->addWidget(addBalance);
    layoutbut->addWidget(save);
    layoutbut->addWidget(undo);
    layoutbut->addWidget(close);
    layout->addItem(layoutbut);
    layout->addWidget(tbl);

    this->setLayout(layout);
    this->setMinimumHeight(350);
    this->setMinimumWidth(557);
    this->setWindowTitle("Mobile Operator");
    this->show();

    connect(close, SIGNAL(clicked()), SLOT(close()));
    connect(save, SIGNAL(clicked()), SLOT(saveTable()));
    connect(addBalance, SIGNAL(clicked()), SLOT(showbal()));
    connect(undo, SIGNAL(clicked()), SLOT(undoChange()));
    connect(tbl, SIGNAL(cellDoubleClicked(int,int)), SLOT(showbal()));
}

void mainWindow::pushTable() {
    int i;

    tbl->setRowCount(numbers->size());
    tbl->setColumnCount(5);
    tbl->setHorizontalHeaderLabels(strList);

    for (i = 0, iter = numbers->begin(); iter!=numbers->end(); iter++, i++) {
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
    balWind->setLine(tbl->currentRow());
    balWind->show();
    connect(balWind, SIGNAL(sendBalance(int,int,int,int,int)),
            SLOT(updateBalance(int,int,int,int,int)));
    connect(tbl, SIGNAL(cellClicked(int,int)), balWind, SLOT(setLine(int,int)));
}

void mainWindow::updateBalance(int line, int sum, int tarif, int isInet, int isBlock) {
    numbsTmp = new QMap<QString, element>(*numbers);
    st->Push(numbsTmp);
    iter = numbers->begin();
    iter = iter+line;
    iter.value().setBalance(iter.value().getBalance()+sum);
    if(tarif) iter.value().setTarifID(tarif);
    if(isInet != -1) iter.value().setInet(isInet);
    if(isBlock != -1) iter.value().setBlock(isBlock);
    this->refleshTable();
}

void mainWindow::loadNums() {
    read_map_bin(*numbers, QString("nums"));
}

void mainWindow::undoChange() {
    if(st->GetCount()) {
        numbers = st->Top();
        st->Pop();
        this->refleshTable();
    }
}

void mainWindow::saveTable() {
    this->write_map_bin(*numbers, QString("nums"));
}

bool mainWindow::write_map_bin(QMap<QString, element>& map, const QString& file) {
    QFile f (file);
    if (!f.open(QIODevice::WriteOnly)) return false;

    QDataStream str(&f);
    str << map;

    return true;
}

bool mainWindow::read_map_bin(QMap<QString, element>& map, const QString& file) {
    QFile f (file);
    if (!f.open(QIODevice::ReadOnly)) return false;

    QDataStream str(&f);
    map.clear();
    str >> map;
    return true;
}

mainWindow::~mainWindow() {

}

#include"balanceWindow.h"

balanceWindow::balanceWindow(QWidget *pwgt){
    lbl             = new QLabel("Number: ");
    okBut           = new QPushButton("Ok");
    close           = new QPushButton("Close");
    inet            = new QCheckBox(pwgt);
    block           = new QCheckBox(pwgt);
    comboBox        = new QComboBox(pwgt);
    spinBoxBalance  = new QSpinBox();
    spinBoxTarif    = new QSpinBox();
    layout          = new QBoxLayout(QBoxLayout::TopToBottom);
    layoutbut       = new QBoxLayout(QBoxLayout::LeftToRight);


    layoutbut->addWidget(lbl);
    layoutbut->addWidget(comboBox);
    layout->addItem(layoutbut);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    lbl         = new QLabel("Sum: ");
    layoutbut->addWidget(lbl);
    layoutbut->addWidget(spinBoxBalance);
    layout->addItem(layoutbut);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    lbl         = new QLabel("TarifID: ");
    layoutbut->addWidget(lbl);
    layoutbut->addWidget(spinBoxTarif);
    layout->addItem(layoutbut);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    lbl         = new QLabel("Internet: ");
    layoutbut->addWidget(lbl);
    layoutbut->addWidget(inet);
    layout->addItem(layoutbut);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    lbl         = new QLabel("Blocked: ");
    layoutbut->addWidget(lbl);
    layoutbut->addWidget(block);
    layout->addItem(layoutbut);
    layoutbut   = new QBoxLayout(QBoxLayout::LeftToRight);
    layoutbut->addWidget(okBut);
    layoutbut->addWidget(close);
    layout->addItem(layoutbut);


    this->setLayout(layout);
    this->setWindowTitle("Manage");
    spinBoxBalance->setRange(-999999,999999);
    spinBoxTarif->setRange(0,100);
    inet->setTristate(1);
    block->setTristate(1);
    connect(close, SIGNAL(clicked()), SLOT(close()));
    connect(okBut, SIGNAL(clicked()), SLOT(okPressed()));
}

void balanceWindow::setCBox(const QMap<QString, element> *nums){
    QMap<QString, element>::const_iterator iter;
    for(iter = nums->begin();iter!=nums->end();iter++) {
        comboBox->addItem(iter.key());

    }
}

void balanceWindow::okPressed() {
    int line, sum, tarif;
    bool isInet, isBlock;
    line = comboBox->currentIndex();
    sum = spinBoxBalance->value();
    tarif = spinBoxTarif->value();
    if(!inet->isTristate()) isInet = inet->isChecked();
    else isInet = -1;
    if(!block->isTristate()) isBlock = block->isChecked();
    else isBlock = -1;
    emit sendBalance(line, sum, tarif, isInet, isBlock);
    this->hide();
}

void balanceWindow::setLine(int line, int) {
    comboBox->setCurrentIndex(line);
}

void balanceWindow::setLine(int line) {
    if(line>0) comboBox->setCurrentIndex(line);
}

balanceWindow::~balanceWindow() {
}

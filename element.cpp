#include<iostream>
#include"element.h"
using namespace std;

#define MAXMARK 4

element::element(int BalanceIn, int TarifIDIn, bool InetIn, bool BlockIn) {
        Balance = BalanceIn;
        TarifID = TarifIDIn;
        Inet = InetIn;
        Block = BlockIn;
}

element::element() {
        Balance = 0;
        TarifID = 0;
        Inet = 0;
        Block = 0;
}

element::element(const element &TempObj) {
        Balance = TempObj.Balance;
        TarifID = TempObj.TarifID;
        Inet = TempObj.Inet;
        Block = TempObj.Block;
}

int element::getBalance() {
    return Balance;
}

int element::getTarifID() {
    return TarifID;
}

bool element::isInet(){
    return Inet;
}

bool element::isBlock() {
    return Block;
}

void element::setBalance(int inBalance){
    Balance = inBalance;
}

void element::setTarifID(int inTarif) {
    TarifID = inTarif;
}

void element::setInet(bool inInet) {
    Inet = inInet;
}

void element::setBlock(bool inBlock) {
    Block = inBlock;
}

element::~element() {
}



istream &operator>>(istream &stream, element &TempObject) {
    cout << "Type: ";
    stream >> TempObject.Balance;
    stream >> TempObject.TarifID;
    stream >> TempObject.Inet;
    stream >> TempObject.Block;
	return stream;
}

ostream &operator<<(ostream &stream, const element TempObject) {
    stream << TempObject.Balance << " "
           << TempObject.TarifID << " "
           << TempObject.Inet<< " "
           << TempObject.Block << endl;
	return stream;
}

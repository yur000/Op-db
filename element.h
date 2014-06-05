#ifndef _ELEMENT_
#define _ELEMENT_

class element  {
    int Balance, TarifID;
    bool Inet, Block;
public:
    element(int, int, bool, bool);
    element();
    element(const element&);
    int getBalance();
    int getTarifID();
    bool isInet();
    bool isBlock();
    void setBalance(int);
    void setTarifID(int);
    void setInet(bool);
    void setBlock(bool);
    ~element();
};

#endif

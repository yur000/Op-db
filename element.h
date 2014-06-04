#ifndef _ELEMENT_
#define _ELEMENT_
#include<iostream>

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
    friend std::istream &operator>>(std::istream&, element&);
    friend std::ostream &operator<<(std::ostream&, const element);
};

#endif

#ifndef FIRM_H
#define FIRM_H
#include "Lab2task1.h"


class BankAccounts {
  private:
    static const unsigned maxAccNumber = 100;
    BankAccount accounts[maxAccNumber];
    unsigned actualAccNumber = 0;
  public: 
    void addAcc();
    void editAcc();
    void deleteAcc();
    void printPersonsAccs();
    void printAllAccs();
    void sortAccs();
};



#endif
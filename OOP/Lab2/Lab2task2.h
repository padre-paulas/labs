#ifndef FIRM_H
#define FIRM_H
#include "Lab2task1.h"

class BankAccounts {
  private:
    static const unsigned maxAccNumber = 100;
    BankAccount accounts[maxAccNumber];
    unsigned actualAccNumber = 0;
  public: 
    void addAcc(const char accOwner[20]);
    void editAcc();
    void deleteAcc(int ID);
    void printPersonsAccs();
    void printAllAccs();
    void sortAccs();
    BankAccounts();
};



#endif
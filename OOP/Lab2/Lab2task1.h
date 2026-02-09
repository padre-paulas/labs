#ifndef FIRM_H
#define FIRM_H

struct Date {
  unsigned day;
  unsigned month;
  unsigned year;
  Date();
  Date(unsigned dDay, unsigned dMonth, unsigned dYear);
};

class BankAccount {
  private: 
    char owner[20];
    Date dateCreated;
    int balance;
    char recentActions[10][50];
    void setDateCreated();
  public:
    BankAccount();
    BankAccount(char accOwner[20]);
    void print();

};






#endif
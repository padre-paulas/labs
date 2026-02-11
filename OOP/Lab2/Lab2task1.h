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
    char recentActions[10][50] = {"Account created"};
    void setDateCreated();
  public:
    BankAccount();
    BankAccount(const char accOwner[20]);
    void setName(const char newName[20]);
    void depositWithdraw(int amount, bool deposit);
    void updateRecentActions(const char sentence[50]);
    void setDate(unsigned newDay, unsigned newMonth, unsigned newYear);
    void print();
};






#endif
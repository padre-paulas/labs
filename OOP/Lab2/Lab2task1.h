#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Date {
  unsigned day;
  unsigned month;
  unsigned year;
  Date();
  Date(unsigned dDay, unsigned dMonth, unsigned dYear);
};

class BankAccount {
  private: 
    static int nextID;
    int accID;
    char owner[20];
    Date dateCreated;
    int balance;
    char recentActions[10][50] = {"Account created"};
    void setDateCreated();
    void updateRecentActions(const char sentence[50]);
  public:
    BankAccount();
    BankAccount(const char accOwner[20]);
    void setName(const char newName[20]);
    const char* getName() const { return owner; };
    void depositWithdraw(int amount, bool deposit);
    void setDate(int newDay, int newMonth, int newYear);
    int getID() const { return accID; };
    void deleteID() { accID = -1; };
    void print();
};






#endif
#include "Lab2task1.h"
#include <iostream>
#include <ctime>

int main() {

  BankAccount pavlosAccount("Pavlo");
  pavlosAccount.depositWithdraw(3, true);
  pavlosAccount.depositWithdraw(3, false);
  pavlosAccount.depositWithdraw(150, true);
  pavlosAccount.setName("Pavlo Prokhorov");
  pavlosAccount.depositWithdraw(5, false);
  pavlosAccount.depositWithdraw(100, true);
  pavlosAccount.depositWithdraw(10000, true);
  pavlosAccount.depositWithdraw(100, false);
  pavlosAccount.setDate(133, 8, 2004);
  pavlosAccount.setDate(12, 7, 2025);
  pavlosAccount.print();
  return 0;
}

Date::Date() : day(1), month(1), year(1900) {};

Date::Date(unsigned dDay, unsigned dMonth, unsigned dYear)
: day(dDay), month(dMonth), year(dYear) {};

void BankAccount::setDateCreated() {
  std::time_t t = std::time(nullptr);
  std::tm *now = std::localtime(&t);

  dateCreated = Date(
    now->tm_mday,
    now->tm_mon + 1, 
    now->tm_year + 1900
  );
}

void BankAccount::print() {
  std::cout << "\nOwner: " << owner << std::endl
  << "Account created: " << dateCreated.day 
  << "/" << dateCreated.month << "/" << dateCreated.year 
  << std::endl << "Balance: " << balance << std::endl 
  << "Recent actions: ";

  int i = 0, j = 0;
  while (recentActions[i][0] != '\0' && i < 10) {
    std::cout << std::endl << i + 1 << ". ";
    j = 0;
    while (recentActions[i][j] != '\0' && j < 50) {
      std::cout << recentActions[i][j];
      j++;
    }
    i++;
    std::cout << " ";
  } 
  std::cout << "\n\n";
};

void BankAccount::setName(const char newName[20]) {
  int i = 0;
  while (newName[i] != '\0' && i < 19) {
    owner[i] = newName[i];
    i++;
  }
  owner[i] = '\0';
  char buffer[50];
  std::snprintf(buffer, 50, "Changed name to %s", newName);
  updateRecentActions(buffer);
};

void BankAccount::depositWithdraw(int amount, bool deposit) {
  if (amount <= 0) {
    if (deposit) {
      std::cout << "Invalid deposit!" << std::endl;
      return;
    } 
    std::cout << "Invalid withdrawal!" << std::endl;
  }
  if (deposit) {
    balance += amount;
    char buffer[50];
    std::snprintf(buffer, 50, "Deposited %u$", amount);
    updateRecentActions(buffer);
    return;
  }
  if (amount > balance) {
    std::cout << "Not enough money!" << std::endl;
    return;
  }
  char buffer[50];
  std::snprintf(buffer, 50, "Withdrew %u$", amount);
  updateRecentActions(buffer);
  balance -= amount;
  return;
}

void BankAccount::updateRecentActions(const char sentence[50]) {
  int i = 0, j = 0;
  
  if (recentActions[9][0] != '\0') {
    for (i = 1; i < 10; i++) {
      j = 0;
      while (j < 49 && recentActions[i][j] != '\0') {
        recentActions[i - 1][j] = recentActions[i][j];
        j++;
      }
      recentActions[i - 1][j] = '\0';
    }

    j = 0;
    while (sentence[j] != '\0' && j < 49) {
      recentActions[9][j] = sentence[j];
      j++;
    }
    recentActions[9][j] = '\0';
    return;
  }

  while (i < 10) {
    j = 0;
    if (recentActions[i][0] == '\0') {
      while (sentence[j] != '\0' && j < 49) {
        recentActions[i][j] = sentence[j];
        j++;
      }
      recentActions[i][j] = '\0';
      return;
    }
    i++;
  }
  return;
}

int BankAccount::nextID = 1000;

BankAccount::BankAccount() 
: owner("Undefined"), 
accID(nextID++),
balance(0) {
  for(int i = 0; i < 10; i++) {
    recentActions[i][0] = '\0'; 
  }
  setDateCreated();
};

BankAccount::BankAccount(const char accOwner[20])
: balance(0),
accID(nextID++) {
  int i = 0;
  while (accOwner[i] != '\0' && i < 19) {
    owner[i] = accOwner[i];
    i++;
  }
  owner[i] = '\0';

  for(int i = 0; i < 10; i++) {
    recentActions[i][0] = '\0'; 
  }

  setDateCreated();
};

void BankAccount::setDate(int newDay, int newMonth, int newYear) {
  if (
    newDay <= 0 
    || newDay > 31 
    || newMonth <= 0 
    || newMonth > 12 
    || newYear < 1890 
    || newYear > 2026
  ) {
    std::cout << "Invalid date!\n";
    return;
  }
  dateCreated.day = newDay;
  dateCreated.month = newMonth;
  dateCreated.year = newYear;

  char buffer[50];
  std::snprintf(buffer, 50, "Changed the date of account creation to %u/%u/%u", newDay, newMonth, newYear);
  updateRecentActions(buffer);
  
  return;
}








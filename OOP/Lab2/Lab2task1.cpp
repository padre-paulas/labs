#include "Lab2task1.h"
#include <iostream>
#include <string>
#include <ctime>

int main() {

  // BankAccount first;
  // first.print();
  BankAccount second("Pavlo");
  // second.print();
  // second.setName("Someone");
  second.depositWithdraw(3, true);
  second.print();
  second.depositWithdraw(3, false);
  second.print();
  second.setName("Emma");
  second.print();
  second.setName("Emma");
  second.print();  
  second.setName("Emma");
  second.print();  
  second.setName("Emma");
  second.print();  
  second.setName("Emma");
  second.print();
  second.setName("Emma");
  second.print();
  second.setName("Emma");
  second.print();
  second.depositWithdraw(150, true);
  second.print();
  second.setName("Emma");
  second.print();
  second.setName("Emma");
  second.print();
  second.setName("Emma");
  second.print();  
  second.setName("Emma");
  second.print();  
  second.setName("Emma");
  second.print();  
  second.setName("Emma");
  second.print();
  second.setName("Emma");
  second.print();
  second.setName("Emma");
  second.print();
  second.depositWithdraw(5, false);
  second.print();
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
    std::cout << "Invalid input!" << std::endl;
    return;
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
  }
}

BankAccount::BankAccount() 
: owner("Undefined"),
balance(0) {
  for(int i = 0; i < 10; i++) {
    recentActions[i][0] = '\0'; 
  }
  setDateCreated();
};

BankAccount::BankAccount(const char accOwner[20])
: balance(0) {
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







#include "Lab2task1.h"
#include <iostream>
#include <string>
#include <ctime>

int main() {

  BankAccount first;
  first.print();
  // BankAccount second("Pavlo");

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
  std::cout << "Owner: " << owner << std::endl
  << "Account created: " << dateCreated.day 
  << "/" << dateCreated.month << "/" << dateCreated.year 
  << std::endl << "Balance: " << balance << std::endl 
  << "Recent actions: " << recentActions << std::endl;
};

BankAccount::BankAccount() 
: owner("Undefined"),
balance(0), 
recentActions({"Account created"}) {
  setDateCreated();
};

BankAccount::BankAccount(char accOwner[20])
: balance(0),
recentActions({"Account created"}) {
  int i = 0;
  while (accOwner[i] != '\0' && i < 20) {
    owner[i] = accOwner[i];
    i++;
  }
  owner[i] = '/0';

  setDateCreated();

};






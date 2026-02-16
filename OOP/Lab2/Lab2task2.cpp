#include "Lab2task2.h"
// #include "Lab2task1.h"
#include <iostream>

int main() {

  BankAccounts accArray;
  accArray.addAcc("Pavlo");
  accArray.addAcc("Taylor");
  accArray.editAcc();
  accArray.printAllAccs();
  accArray.deleteAcc(1100);
  accArray.printAllAccs();
  accArray.printPersonsAccs();

  return 0;
}

BankAccounts::BankAccounts() : actualAccNumber(0) {};

void BankAccounts::addAcc(const char accOwner[20]) {
    if (actualAccNumber < maxAccNumber) {
      actualAccNumber++;
      accounts[actualAccNumber - 1] = BankAccount(accOwner);
      return;
    }
}

void BankAccounts::deleteAcc(int ID) {
  for (int i = 0; i < maxAccNumber; i++) {
    if (accounts[i].getID() == ID) {
      // std::cout << "getID: " << accounts[i].getID() << std::endl;
      accounts[i].deleteID();
      return;
    }
  }
}

void BankAccounts::editAcc() {
  int ID = 0;
  std::cout << "Enter account ID: ";
  std::cin >> ID;
  for (int i = 0; i < maxAccNumber; i++) {
    if (accounts[i].getID() == ID) {
      char input[20] = "";
      std::cout << "What do you want to edit? (owner, date, dep/with): \n";
      std::cin >> input;
      if (strcmp(input, "owner") == 0) {
        char newName[20];
        std::cout << "Enter new name: ";
        std::cin >> newName;
        accounts[i].setName(newName);
      }
    }
  }
}

void BankAccounts::printAllAccs() {
  for (int i = 0; i < maxAccNumber && accounts[i].getID() != -1; i++) {
    if (strcmp(accounts[i].getName(), "Undefined") == 0) continue;
    accounts[i].print();
  }
}

void BankAccounts::printPersonsAccs() {
  char name[20];
  std::cout << "Enter name to print all person's accounts: ";
  std::cin >> name;
  for (int i = 0; i < maxAccNumber; i++) {
    if (strcmp(accounts[i].getName(), name) == 0) {
      accounts[i].print();
    }
  }
}

void BankAccounts::sortAccs() {
  BankAccount left, right;
  while (left.getID() < right.getID()) {
    
  }
}

#include "Lab2task2.h"
#include <iostream>

int main() {

  BankAccounts accArray;
  accArray.addAcc("Pavlo");
  accArray.addAcc("Taylor");
  accArray.addAcc("Margot");
  accArray.addAcc("Margot");
  accArray.addAcc("Johnny");
  accArray.addAcc("Rony");
  accArray.editAcc();
  // accArray.deleteAcc(1102);
  // accArray.sortAccs();
  accArray.printAllAccs();
  // accArray.showActualAccNumber();
  accArray.printPersonsAccs();

  return 0;
}

void BankAccounts::showActualAccNumber() {
  std::cout << "Actual Account Number: " << actualAccNumber << std::endl;
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
      accounts[i].deleteID();
      actualAccNumber--;
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
      char newDate[20];
      if (strcmp(input, "date") == 0) {
        char newName[20];
        std::cout << "Enter new date (01/01/2026): ";
        std::cin >> newDate;
        int day = (newDate[0] - '0') * 10 + (newDate[1] - '0');
        int month = (newDate[3] - '0') * 10 + (newDate[4] - '0');
        int year = (newDate[6] - '0') * 1000 + (newDate[7] - '0') * 100 + (newDate[8] - '0') * 10 + (newDate[9] - '0');
          accounts[i].setDate(day, month, year);
        std::cout << int(newDate[9]);
      }
      int newDepWith = 0;
      if (strcmp(input, "dep/with") == 0) {
        std::cout << "Do you want to deposit or withdraw? (d/w): ";
        std::cin >> input;
        if (strcmp(input, "d") == 0) {
          std::cout << "How much do you want to deposit: ";
          std::cin >> newDepWith;
          accounts[i].depositWithdraw(newDepWith, true);
        } else if (strcmp(input, "w") == 0) {
          std::cout << "How much do you want to deposit: ";
          std::cin >> newDepWith;
          accounts[i].depositWithdraw(newDepWith, false);
        }
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
  BankAccount temp;
  for (int i = 0; i < maxAccNumber; i++) {
    for (int j = 0; j < maxAccNumber - 1; j++) {
      if (
        accounts[j].getID() > accounts[j + 1].getID() &&
        accounts[j].getID() != -1 && accounts[j + 1].getID() != -1
      ) {
        temp = BankAccount(accounts[j]);
        accounts[j] = accounts[j + 1];
        accounts[j + 1] = temp;
      }
    }
  }
}

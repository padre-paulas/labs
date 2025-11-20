#include <iostream>

void sayLastName();

int main() {

  sayLastName();

  return 0;
}

void sayLastName() {
  std::string lastName = "";

  std::cout << "Привіт! Ця програма хоче з тобою привітатися! Напиши своє прізвище: ";
  std::cin >> lastName;
  std::cout << std::endl << "Привіт, " << lastName << "!" << std::endl;
}
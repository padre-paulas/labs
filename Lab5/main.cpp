#include <iostream>
#include <string>

int main() {

 
  std::cout << "\n************************************\n";
  std::cout << "Hi! Enter your full name: ";

  std::string fullName, first, second, third;
  int i(0), skip(0);

  std::getline(std::cin, fullName);

  for (i = 0; i < fullName.length(); i++) {
    if (fullName[i] == ' ') {
      skip++;
      continue;
    }
    if (skip == 0) {
      first += fullName[i];
    } 
    if (skip == 1) {
      second += fullName[i];
    } 
    if (skip == 2) {
      third += fullName[i];
    }
  }

  std::cout << first.length() << " " << second.length() << " " << third.length() << std::endl;

  if (first.length() > second.length() && first.length() > third.length()) {
    std::cout << first << std::endl;
  } else if (second.length() > third.length()) {
    std::cout << second << std::endl;
  } else if (third.length() > second.length()) {
    std::cout << third << std::endl;
  } else if (first.length() == second.length()) {
    if (first.length() == third.length()) {
      std::cout << first << " " << second << " " << third << std::endl;
    } else {
      std::cout << first << " " << second << std::endl;
    }
  } else if (first.length() == third.length() && first.length() != second.length()) {
    std::cout << first << " " << third << std::endl;
  } else if (second.length() == third.length() && first.length() != second.length()) {
    std::cout << second << " " << third << std::endl;
  } 

  std::cout << "************************************\n\n";

  

  return 0;
}
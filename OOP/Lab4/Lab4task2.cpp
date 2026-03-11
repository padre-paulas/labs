#include <iostream>
#include <cmath>

void demo();

class Factorial {
  private: 
    const double num;
    long long calculateFactorial() const;
    Factorial(const double num) : num(num) {};
    friend void demo();
};

int main() {
  demo();
  return 0;
}

long long Factorial::calculateFactorial() const {
  if (std::floor(num) != num || num < 0) 
    throw std::runtime_error("Not a non-negative integer!");
  if (num > 20) 
    throw std::overflow_error("Number will cause overflow!");
  if (num == 0) return 1;
  long long result(1);
  for (int i = 2; i <= num; i++) {
    result *= i;
  }
  return result;
}

void demo() {
  std::cout << "\n===Factorial calculation===\n";
  char choice('c');
  long long result(0);
  do {
    std::cout << "\nEnter a non-negative integer [0 - 20]: ";
    double num(0);
    std::cin >> num;

    Factorial factorial(num);

    try {
      result = factorial.calculateFactorial();
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
      continue;
    }

    std::cout << "Result: " << result
    << "\nContinue or exit? (c/e): ";
    std::cin >> choice;
  } while (choice == 'c');
  std::cout << "===========================\n\n";
}
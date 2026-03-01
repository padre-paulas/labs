#include "Lab3task1.h"
#include <iostream>
#include <fstream>
#include <string>

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

std::ostream& operator << (std::ostream& os, const Vector& vec) {
  os << "x: " << vec.x << "  y: " << vec.y << "  z: "
  << vec.z;
  return os;
}

Vector& Vector::operator = (const Vector& vec) {
  x = vec.x;
  y = vec.y;
  z = vec.z;
  return *this;
}

bool Vector::operator == (const Vector& vec) const {
  return (x == vec.x && y == vec.y && z == vec.z);
}

bool Vector::operator < (const Vector& vec) const {
  return (x < vec.x && y < vec.y && z < vec.z);
}
bool Vector::operator > (const Vector& vec) const {
  return vec < *this;
}
bool Vector::operator <= (const Vector& vec) const {
  return (*this < vec || *this == vec);
}
bool Vector::operator >= (const Vector& vec) const {
  return (vec < *this || *this == vec);
}

Vector Vector::operator * (const double num) const {
  return Vector(x * num, y * num, z * num);
}

Vector Vector::operator - (const Vector& vec) const {
  return Vector(x - vec.x, y - vec.y, z - vec.z);
}

Vector Vector::operator + (const Vector& vec) const{
  return Vector(x + vec.x, y + vec.y, z + vec.z);
}

Vector Vector::operator * (const Vector& vec) const {
  return Vector(x * vec.x, y * vec.y, z * vec.z);
}

Vector Vector::operator / (const Vector& vec) const {
  return Vector(x / vec.x, y / vec.y, z / vec.z);
}

Vector& Vector::operator += (const Vector& vec) {
  return *this = *this + vec;
}

Vector& Vector::operator -= (const Vector& vec) {
  return *this = *this - vec;
}

Vector& Vector::operator *= (const Vector& vec) {
  return *this = *this * vec;
}

Vector& Vector::operator /= (const Vector& vec) {
  return *this = *this / vec;
}

Vector Vector::operator + (const double num) const {
  return Vector(x + num, y + num, z + num);
}

Vector& Vector::operator ++ () {
  return *this = *this + double(1);
}

Vector& Vector::operator -- () {
  return *this = *this + double(-1);
}

Vector Vector::operator ++ (int) {
  Vector temp = *this;
  *this = ++*this;
  return temp;
}

Vector Vector::operator -- (int) {
  Vector temp = *this;
  *this = --*this;
  return temp;
}

int demo();

int main() {
  demo();
  return 0;
}

int demo() {
  double x, y, z, num;
  char option;
  std::string strOption;

  do {
    std::cout << "Enter vector A values (x, y, z): ";
    std::cin >> x >> y >> z;
    Vector vecA = Vector(x, y, z);

    std::cout << "Do you want to use unary or binary operator? (u/b): ";
    std::cin >> option;

    if (option == 'b') {
      std::cout << "Do you want the operation with two vectors or vector and number? (v/n): \n";
      std::cin >> option;
      if (option == 'n') {
        std::cout << "Enter number: ";
        std::cin >> num;
        std::cout << "Enter operation (+, *): ";
        std::cin >> option;
        if (option == '+') {
          std::cout << "Result: " << vecA + num << std::endl;
        } else if (option == '*') {
          std::cout << "Result: " << vecA * num << std::endl;
        }
      } else if (option == 'v') {
        std::cout << "Enter vector B values (x, y, z): \n";
        std::cin >> x >> y >> z;
        Vector vecB = Vector(x, y, z);
        std::cout << "Enter operation (=, +=, -=, *=, /=, ==, <, >, <=, >=, +, *, -, /): ";
        std::cin >> strOption;
        if (strOption == "=") {
          std::cout << "Result: vector A: " << (vecA = vecB) << std::endl;
        } else if (strOption == "+=") {
          std::cout << "Result: vector A: " << (vecA += vecB) << std::endl;
        } else if (strOption == "-=") {
          std::cout << "Result: vector A: " << (vecA -= vecB) << std::endl;
        } else if (strOption == "*=") {
          std::cout << "Result: vector A: " << (vecA *= vecB) << std::endl;
        } else if (strOption == "/=") {
          std::cout << "Result: vector A: " << (vecA /= vecB) << std::endl;
        } else if (strOption == "==") {
          std::cout << "Result: " << (vecA == vecB) << std::endl;
        } else if (strOption == "<") {
          std::cout << "Result: " << (vecA < vecB) << std::endl;
        } else if (strOption == ">") {
          std::cout << "Result: " << (vecA > vecB) << std::endl;
        } else if (strOption == "<=") {
          std::cout << "Result: " << (vecA <= vecB) << std::endl;
        } else if (strOption == ">=") {
          std::cout << "Result: " << (vecA >= vecB) << std::endl;
        } else if (strOption == "+") {
          std::cout << "Result: " << (vecA + vecB) << std::endl;
        } else if (strOption == "*") {
          std::cout << "Result: " << (vecA * vecB) << std::endl;
        } else if (strOption == "-") {
          std::cout << "Result: " << (vecA - vecB) << std::endl;
        } else if (strOption == "/") {
          std::cout << "Result: " << (vecA / vecB) << std::endl;
        }
      }
    } else if (option == 'u') {
      std::cout << "Do you want a prefix or a postfix operation? (pre/post): ";
      std::cin >> strOption;
      if (strOption == "pre") {
        std::cout << "Enter operator (++, --): ";
        std::cin >> strOption;
        if (strOption == "++") {
          std::cout << "Result: " << ++vecA << std::endl;
        } else if (strOption == "--") {
          std::cout << "Result: " << --vecA << std::endl;
        }
      } else if (strOption == "post") {
        std::cout << "Enter operator (++, --): ";
        std::cin >> strOption;
        if (strOption == "++") {
          std::cout << "Result: " << vecA++ << std::endl;
          std::cout << "Vector A: " << vecA << std::endl;
        } else if (strOption == "--") {
          std::cout << "Result: " << vecA-- << std::endl;
          std::cout << "Vector A: " << vecA << std::endl;
        }
      }
    }
    std::cout << "Do you want to continue or exit? (c/e): ";
    std::cin >> option;
  } while (option == 'c');
  return 0;
}
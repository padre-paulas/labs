#include <iostream>
#include <fstream>
#include <vector>
#include <random>

void fillFile(int amount);
std::vector<double> readFile();

int main() {

  fillFile(30);
  readFile();

  return 0;
}

void fillFile(int amount) {
  std::ofstream ofs("input.txt", std::ios::trunc);
  if (!ofs.is_open()) throw std::runtime_error("Can't create file!");

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(0.0, 1000);

  for (int i = 0; i < amount; i++) {
    ofs << dis(gen) << ' ';
  }
  ofs.close();
}

std::vector<double> readFile() {
  std::ifstream ifs("input.txt");
  if (!ifs.is_open()) throw std::runtime_error("Couldn't open file!");

  std::vector<double> vec;

  // double number = 0;
  // bool isIntPart = true;
  // int i = 10;
  // char ch = ' ';
  double number;

  while(ifs >> number) {
    std::cout << number << " ";
    vec.push_back(number);

  // std::cout << "Hello 2";
  // std::cout << ch;
  //   if (ch == ' ') {
  //     vec.push_back(number);
  //     std::cout << number << std::endl;
  // std::cout << "Hello from space";
  //     number = 0;
  //     isIntPart = true;
  //     i = 10;
  //     continue;
  //   }
  //   if (ch == '.') {
  //     isIntPart = false;
  //     continue;
  //   }
  //   if (isIntPart) {
  //     // std::cout << "Hello 3";

  //     number *= 10;
  //     number += double(ch);
  //   } else {
  //     // std::cout << "Hello 4";

  //     number += (double(ch) / i);
  //     i *= 10;
  //   }
  }
  return vec;
}
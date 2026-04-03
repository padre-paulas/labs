#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <iterator>
#include <exception>

void fillFile(int amount);
std::vector<double> readFile();
void deletePositive(std::vector<double>& vec);
std::list<double> createList(std::vector<double>& vec);
template <typename T>
void printElements(T& container);

int main() {

  std::vector<double> vec;

  try {
    fillFile(30);
    vec = readFile();
  } catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
  printElements(vec);

  deletePositive(vec);
  printElements(vec);
  
  std::list<double> list = createList(vec);
  printElements(list);

  return 0;
}

void fillFile(int amount) {
  std::ofstream ofs("input.txt", std::ios::trunc);
  if (!ofs.is_open()) throw std::runtime_error("Can't create file!");

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(-1000, 1000);

  for (int i = 0; i < amount; i++) {
    ofs << dis(gen) << ' ';
  }
  ofs.close();
}

std::vector<double> readFile() {
  std::ifstream ifs("input.txt");
  if (!ifs.is_open()) throw std::runtime_error("Couldn't open file!");

  std::vector<double> vec;
  double number;

  while(ifs >> number) vec.push_back(number);

  return vec;
}

void deletePositive(std::vector<double>& vec) {
  // for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++) {
  //   if (*it > 0) { 
  //     vec.erase(it); 
  //     it--; 
  //   }
  // }
  
  // std::erase_if(vec, [](double n) { return n > 0; });
  vec.erase(std::remove_if(vec.begin(), vec.end(),
    [](double n) { return n > 0; }), vec.end());
}

std::list<double> createList(std::vector<double>& vec) {
  return std::list<double>(vec.rbegin(), vec.rend());
}

template <typename T>
void printElements(T& container) {
  for (auto elem : container) std::cout << elem << " ";
  std::cout << "\n\n";
}
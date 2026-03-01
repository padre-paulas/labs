#include <iostream>
#include <fstream>
#include <string>

void copy();

int main() {
  copy();
  return 0;
}

void copy() {
  std::ifstream ifs("file_input.txt");
  char ch = ifs.get();
  std::cout << ch << std::endl;
}
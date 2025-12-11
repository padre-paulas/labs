#include <iostream>
#include <fstream>

void readFile();

int main() {


  return 0;
}

void readFile() {
  std::fstream fs;
  std::string fileName = "student.txt";

  fs.open(fileName, std::ios::in);

}


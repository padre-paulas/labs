#include <iostream>
#include <fstream>

void readFile();
void calculateAverage();

int main() {


  return 0;
}

void readFile() {
  std::fstream fs;
  std::string fileName = "student.txt";

  fs.open(fileName, std::ios::in);

  fs.close();

}

void calculateAverage() {
  struct Student {
    std::string lastName;
    int grade1, grade2, grade3, grade4;
  };
}


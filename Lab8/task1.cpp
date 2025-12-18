#include <iostream>
#include <fstream>
#include <vector>

void readFile();

struct Student {
  std::string lastName;
  int grade1, grade2, grade3, grade4;
  double averageGrade;

  void calculateAverage() {
    averageGrade = (grade1 + grade2 + grade3 + grade4) / 4.0;
  }
};

int main() {

  readFile();
  
  return 0;
}

void readFile() {
  std::ifstream file("student.txt");
  std::vector<Student> students;
  double overallAverage = 0;

  if (!file) {
    std::cout << "File not found\n";
    return;
  }

  Student s;

  while (file >> s.lastName >> s.grade1 >> s.grade2 >> s.grade3 >> s.grade4) {
    s.calculateAverage();
    students.push_back(s);
  }

  int i = 0;
  for (const Student &st : students) {
    overallAverage += st.averageGrade;
    i++;
  }

  overallAverage /= i;

  std::cout << "\nOverall average = " << overallAverage << "\n\n";

  for (const Student &st : students) {
    if (st.averageGrade > overallAverage) {
      std::cout << st.lastName << " " << st.averageGrade << std::endl;
    }
  }
  std::cout << std::endl;
}
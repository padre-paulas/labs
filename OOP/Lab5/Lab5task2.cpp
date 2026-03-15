#include <iostream>
#include <string>
#include <locale>

void demo();

enum class Disciplines {
  math,
  physics,
  english,
  oop,
  ap
};

class PolytechnicStudent {
  protected:
    struct Name {
      std::string firstName;
      std::string lastName;
    };
    struct Grades {
      double mathGrade;
      double physicsGrade;
      double englishGrade;
    };
    std::string group;
    Name StudentName;
    Grades StudentGrades;
    PolytechnicStudent(
      std::string group,
      std::string firstName, 
      std::string lastName,
      double mathGrade,
      double physicsGrade,
      double englishGrade
    ) : group(group),
    StudentName{firstName, lastName},
    StudentGrades{mathGrade, physicsGrade, englishGrade} {};
};

class ICSITStudent: private PolytechnicStudent {
  private: 
    struct Grades {
      double oopGrade;
      double apGrade;
    };
    std::string major;
    Grades ICSITStudentGrades;
  public:   
    ICSITStudent(
      std::string group, 
      std::string major,
      std::string firstName, 
      std::string lastName,
      double mathGrade,
      double physicsGrade,
      double englishGrade,
      double oopGrade,
      double apGrade
    ) : PolytechnicStudent(
      group, 
      firstName, 
      lastName, 
      mathGrade, 
      physicsGrade, 
      englishGrade
    ), major(major),
    ICSITStudentGrades{oopGrade, apGrade} {};
    void show();
    void setGroup(std::string group);
    void setMajor(std::string major);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    // void setMathGrade(double mathGrade);
    // void setPhysicsGrade(double physicsGrade);
    // void setEnglishGrade(double englishGrade);
    // void setMajor(double major);
    // void setOopGrade(double oopGrade);
    // void setApGrade(double apGrade);
    void setGrade(Disciplines disciplines, double grade);
};

int main() {
  std::locale::global(std::locale("uk_UA.UTF-8"));
  std::cin.imbue(std::locale());
  std::cout.imbue(std::locale());

  // Disciplines disciplines;
  // ICSITStudent st(
  //   "ПП-14", 
  //   "Проєктування та програмування інтелектуальних систем та пристроїв",
  //   "Павло",
  //   "Прохоров",
  //   78.5,
  //   95,
  //   100,
  //   100,
  //   100
  // );
  // st.show();

  demo();
  return 0;
}

void demo() {
  // ICSITStudent student;
  std::string firstName, lastName, group, major;
  double mathGrade, physicsGrade,
  englishGrade, oopGrade, apGrade;

  std::string choice;
  std::cout << "===Оцінки студента ІКНІ===\n";
  std::cout << "Введіть ім‘я: ";
  std::cin >> firstName;
  std::cout << "Введіть прізвище: ";
  std::cin >> lastName;
  std::cout << "Введіть спеціальність: ";
  std::cin >> major;
  std::cout << "Введіть групу: ";
  std::cin >> group;
  std::cout << "Введіть оцінку з математики: ";
  std::cin >> mathGrade;
  std::cout << "Введіть оцінку з фізики: ";
  std::cin >> physicsGrade;
  std::cout << "Введіть оцінку з англійської мови: ";
  std::cin >> englishGrade;
  std::cout << "Введіть оцінку з ООП: ";
  std::cin >> oopGrade;
  std::cout << "Введіть оцінку з АП: ";
  std::cin >> apGrade;

  ICSITStudent student(
    group,
    major, 
    firstName,
    lastName,
    mathGrade,
    physicsGrade,
    englishGrade,
    oopGrade,
    apGrade
  );

  student.show();
  
  do {
    std::cout << "Яку інформацію про студента ви бажаєте змінити?\n(ім, пріз, спец, гр, матем, фіз, анг, ооп, ап): ";
    std::cin >> choice;
    if (choice == "ім") { 
      std::cout << "Введіть ім‘я: ";
      std::cin >> firstName;
      student.setFirstName(firstName);
    } else if (choice == "пріз") {
      std::cout << "Введіть прізвище: ";
      std::cin >> lastName;
      student.setLastName(lastName);
    } else if (choice == "спец") {
      std::cout << "Введіть спеціальність: ";
      std::cin >> major;
      student.setMajor(major);
    } else if (choice == "гр") {
      std::cout << "Введіть групу: ";
      std::cin >> group;
      student.setGroup(group);
    } else if (choice == "матем") {
      std::cout << "Введіть оцінку: ";
      std::cin >> mathGrade;
      student.setGrade(Disciplines::math, mathGrade);
    } else if (choice == "фіз") {
      std::cout << "Введіть оцінку: ";
      std::cin >> physicsGrade;
      student.setGrade(Disciplines::physics, physicsGrade);
    } else if (choice == "анг") {
      std::cout << "Введіть оцінку: ";
      std::cin >> englishGrade;
      student.setGrade(Disciplines::english, englishGrade);
    } else if (choice == "ооп") {
      std::cout << "Введіть оцінку: ";
      std::cin >> oopGrade;
      student.setGrade(Disciplines::oop, oopGrade);
    } else if (choice == "ап") {
      std::cout << "Введіть оцінку: ";
      std::cin >> apGrade;
      student.setGrade(Disciplines::ap, apGrade);
    }

    student.show();

    std::cout << "Продовжити або вийти? (п/в): ";
    std::cin >> choice;
  } while (choice == "п");
}

void ICSITStudent::show() {
  std::cout << "\n---Інформація про студента ІКНІ---\n";
  std::cout << "Прізвище та ім‘я: " << StudentName.lastName
  << " " << StudentName.firstName << "\n";
  std::cout << "Спеціальність: " << major << "\n";
  std::cout << "Група: " << group << std::endl;
  std::cout << "Оцінки з загальних предметів:\n"
  << "Математика: " << StudentGrades.mathGrade << "\n"
  << "Фізика: " << StudentGrades.physicsGrade << "\n"
  << "Англійська мова: " << StudentGrades.englishGrade << "\n";
  std::cout << "Оцінки зі спеціальних предметів:\n"
  << "ООП: " << ICSITStudentGrades.oopGrade << "\n"
  << "АП: " << ICSITStudentGrades.apGrade << "\n";
  std::cout << "----------------------------------\n\n";
}

void ICSITStudent::setGroup(std::string group) {
  this->group = group;
}

void ICSITStudent::setMajor(std::string major) {
  this->major = major;
}

void ICSITStudent::setFirstName(std::string firstName) {
  StudentName.firstName = firstName;
}

void ICSITStudent::setLastName(std::string lastName) {
  StudentName.lastName = lastName;
}

void ICSITStudent::setGrade(Disciplines disciplines, double grade) {
  switch (disciplines) {
  case Disciplines::math:
    StudentGrades.mathGrade = grade;
    break;
  case Disciplines::physics:
    StudentGrades.physicsGrade = grade;
    break;
  case Disciplines::english:
    StudentGrades.englishGrade = grade;
  case Disciplines::oop:
    ICSITStudentGrades.oopGrade = grade;
    break;
  case Disciplines::ap:
    ICSITStudentGrades.apGrade = grade;
    break;
  default:
    std::cout << "Invalid discipline!\n";
    break;
  }
} 



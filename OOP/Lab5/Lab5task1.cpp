#include <iostream>
#include <string>

class Airplane_B1 {
  protected:
    double weight;
  public:
    Airplane_B1(double weight) : weight(weight) {};
    void show() {
      std::cout << "Airplane B1:\nWeight: " << weight << std::endl;
    };
};

class Pilot_B2 {
  protected:
    std::string name;
    int age;
  public:
    Pilot_B2(std::string name, int age) : name(name), age(age) {};
    void show() {
      std::cout << "Pilot B2:\nName: " << name 
      << "\nAge: " << age << std::endl;
    };
};

class PassengerAirliner_D1: public Airplane_B1 {
  protected:
    int passengerCapacity;
  public:
    PassengerAirliner_D1(double weight, int passengerCapacity) : 
    Airplane_B1(weight),
    passengerCapacity(passengerCapacity) {};
    void show() {
      std::cout << "PassengerAirliner D1:\nPassenger capacity: " 
      << passengerCapacity << "\nWeight: " << weight << std::endl;
    };
};

class Airbus_D2: private Airplane_B1 {
  protected:
    double cost;
  public:
    Airbus_D2(double weight, double cost) :
    Airplane_B1(weight),
    cost(cost) {};
    void show() {
      std::cout << "Airbus D2:\nCost: " << cost 
      << "\nWeight: " << weight << std::endl;
    };
};

class AirbusModel_D4: 
public Airbus_D2,
public PassengerAirliner_D1,
public Pilot_B2 {
  private:
    std::string modelName;
  public:
    AirbusModel_D4(
      double weight, 
      int passengerCapacity, 
      double cost, 
      std::string pilotName, 
      int pilotAge, 
      std::string modelName
    ) : Airbus_D2(weight, cost),
    PassengerAirliner_D1(weight, passengerCapacity),
    Pilot_B2(pilotName, pilotAge),
    modelName(modelName) {};

    void show() {
      std::cout << "AirbusModel D4:\nModel name: " << modelName 
      << "\nWeight: " << PassengerAirliner_D1::weight 
      << "\nPassengerCapacity: " << passengerCapacity 
      << "\nCost: " << cost
      << "\nPilot name: " << name 
      << "\nPilot age: " << age << std::endl;
    };
};  

int main() {


  return 0;
}
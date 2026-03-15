#include <iostream>
#include <string>

void demo();

class Airplane_B1 {
  protected:
    double weight;
  public:
    Airplane_B1(double weight) : weight(weight) {};
    void show() {
      std::cout << "Airplane B1:\nWeight: " << weight << " kg\n\n";
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
      << "\nAge: " << age << "\n\n";
    };
};

class PassengerAirliner_D1: virtual public Airplane_B1 {
  protected:
    int passengerCapacity;
  public:
    PassengerAirliner_D1(double weight, int passengerCapacity) : 
    Airplane_B1(weight),
    passengerCapacity(passengerCapacity) {};
    void show() {
      std::cout << "PassengerAirliner D1:\nPassenger capacity: " 
      << passengerCapacity << "\nWeight: " << weight << " kg\n\n";
    };
};

class Airbus_D2: virtual private Airplane_B1 {
  protected:
    double cost;
  public:
    Airbus_D2(double weight, double cost) :
    Airplane_B1(weight),
    cost(cost) {};
    void show() {
      std::cout << "Airbus D2:\nCost: $" << cost 
      << " million\nWeight: " << weight << " kg\n\n";
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
    ) : Airplane_B1(weight),
    Airbus_D2(weight, cost),
    PassengerAirliner_D1(weight, passengerCapacity),
    Pilot_B2(pilotName, pilotAge),
    modelName(modelName) {};

    void show() {
      std::cout << "AirbusModel D4:\nModel name: " << modelName 
      << "\nWeight: " << weight 
      << " kg\nPassengerCapacity: " << passengerCapacity 
      << "\nCost: $" << cost
      << " million\nPilot name: " << name 
      << "\nPilot age: " << age << "\n\n";
    };
};  

int main() {
  demo();
  return 0;
}

void demo() {
  std::cout << std::endl;
  Airplane_B1 airplane(29300);
  airplane.show();
  Pilot_B2 pilot("Martin", 37);
  pilot.show();
  PassengerAirliner_D1 passengerAirliner(12000, 298);
  passengerAirliner.show();
  Airbus_D2 airbus(190000, 321);
  airbus.show();
  AirbusModel_D4 airbusModel(276800, 525, 445, "Andrew", 42, "A380");
  airbusModel.show();
}
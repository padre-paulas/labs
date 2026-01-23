#include <iostream>
#include <cmath>
using namespace std;

double calculate_function();

int main() {

  double result = calculate_function();
  cout << "Результат:" << result << endl << endl;

  return 0;
}

double calculate_function() {

  double z, x;

  cout << "Введи значення z: ";
  cin >> z;

  if (z >= 0) {
    x = pow(z, 3.0);
  } else {
    x = pow(z, 2.0) - z;
  }

  cout << "Значення проміжної змінної x: " << x << endl;

  return pow(sin(x), 3.0)*(x + pow(x, 2.0) + pow(x, 3.0));

}




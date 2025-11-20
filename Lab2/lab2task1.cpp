#include <iostream>
#include <cmath>
using namespace std;
// Variant 7

double calculate_function();

int main() {

  double result = calculate_function();
  if (isnan(result)) {
    return 0;
  } 
  cout << "Результат: " << result << endl << endl;

  return 0;
}

double calculate_function() {
  double x, y, z, numerator, denominator;

  cout << "Введи значення x: ";
  cin >> x;

  if (x < -1 || x > 1) {
    cout << "arccos не може приймати числа < -1 або > 1, введіть інше значення x" << endl << endl;
    return numeric_limits<double>::quiet_NaN();
  }

  cout << "Введи значення y: ";
  cin >> y;
  cout << "Введи значення z: ";
  cin >> z;

  denominator = fabs(x-y)*z + pow(x, 2.0);
  
  if (denominator == 0) {
    cout << "Знаменник = 0, немає рішень" << endl << endl;
    return numeric_limits<double>::quiet_NaN();
  }

  numerator = (1.0/4.0)*acos(x)*(x + 3.0*fabs(x-y) + pow(x, 2.0));

  return 5.0*atan(x) - numerator/denominator;
}

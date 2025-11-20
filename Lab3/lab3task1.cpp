#include <iostream>
#include <cmath>
#define N 15
using namespace std;
// Variant 7

void calculateFunction();
void calculateIntegral(double steps);

int main() {

  calculateFunction();
  calculateIntegral(100000); 
  return 0;
}

void calculateFunction() {

  double y, x = 0, step;

  step = M_PI / (N - 1);

  for (int i = 0; i < N; i++) {

    printf("Номер = %-8d x = %-8.1f y = %f \n", i, x, (1 / M_PI) * atan(((2 * x - 1) / 2) + M_PI));

    x += step;
  }
}

void calculateIntegral(double steps) {

  double result = 0, delta_x = M_PI / steps, x = 0;

  for (int i = 0; i < steps; i++) {
    result += delta_x * (1 / M_PI) * atan(((2 * x - 1) / 2) + M_PI);
    x += delta_x;
  }

  printf("Значення інтегралу на відрізку 0 <= x <= PI: %.7f\n", result);
}


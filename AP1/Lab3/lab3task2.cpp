#include <iostream>
#include <cmath>
using namespace std;
// Variant 7

void calculateFunction();

int main() {

  calculateFunction();

  return 0;
}

void calculateFunction() {
  double epsilon, x;

  printf("Enter x, 0 < |x| < 1: ");

  do {
    scanf("%lf", &x);
    if (abs(x) >= 1) {
      printf("Invalid x value, try once more: ");
    }
  } while (abs(x) >= 1);

  printf("Enter epsilon, e < 0.0001: ");

  do {
    scanf("%lf", &epsilon);
    if (epsilon <= 0 || epsilon >= 0.0001) {
      printf("Invalid epsilon value, try once more: ");
    }
  } while (epsilon <= 0 || epsilon >= 0.0001);

  double Y = -(1.0 / 2.0) * log(1.0 - 2.0 * x * cos(M_PI / 3) + pow(x, 2.0));

  printf("The exact value of function Y: %lf\n", Y);


  double term = 0, k = 1.0, sum = 0;
  while (abs(Y - sum) > epsilon) {
   term = (pow(x, k) * cos(k * M_PI / 3.0)) / k;
    sum += term;
    k += 1.0;
  }

  double difference = abs(Y - sum);

  printf("Approximate value of Y using Taylor's series: %lf\n", sum);
  printf("Absolute error Y - approximation of Y: %.8lf\n", difference);
  printf("******************************************************\n\n");

  
}
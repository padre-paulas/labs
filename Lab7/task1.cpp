#include <iostream> 

// double getX();
std::pair<double, double> getInterval();
double calculateIntegral(std::pair<double, double> interval, int step);
void printResult(double result);

int main() {

  double result = calculateIntegral(getInterval(), 0);
  printResult(result);

  return 0;
}

// double getX() {

//   double x;

//   std::fputs("-----------------------------------------", stdout);
//   std::fputs("This program calculates integral of \n7x^3 - x^2 + 3x + 2 on interval [0, pi]\n", stdout);

//   // std::fputs("Enter x: ", stdout);
//   // std::cin >> x;

//   return x;
// }

std::pair<double, double> getInterval() {
  double lowX = 2, highX = 3;
  int step = 0;
  
  return std::pair<double, double> (lowX, highX);
}

double calculateIntegral(std::pair<double, double> interval, int step) {

  double lowX = interval.first;
  double highX = interval.second;

  double x = lowX;
  int accuracy = 1000;
  double deltaX = x / accuracy;

  std::cout << step << std::endl;

  if (step == accuracy - 1) {
    return deltaX * (7 * pow(x, 3) - pow(x, 2) + 3 * x + 2);
  } else return calculateIntegral(interval, ++step) + deltaX * (7 * pow(x, 3) - pow(x, 2) + 3 * x + 2);

}

void printResult(double result) {
  std::cout << "Result: " << result << std::endl;
}
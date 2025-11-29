#include <iostream> 

std::pair<double, double> getInterval();
double calculateIntegral(std::pair<double, double> interval, int step);
void printResult(double result);

int main() {

  double result = calculateIntegral(getInterval(), 0);
  printResult(result);

  return 0;
}

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
  double deltaX = abs(highX - lowX) / accuracy;

  std::cout << step << std::endl;

  if (step == accuracy - 1) {
    return deltaX * (7 * pow(x, 3) - pow(x, 2) + 3 * x + 2);
  } else return calculateIntegral(interval, ++step) + deltaX * (7 * pow(x, 3) - pow(x, 2) + 3 * x + 2);

}

void printResult(double result) {
  std::cout << "Result: " << result << std::endl;
}
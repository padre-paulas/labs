#include <iostream> 

std::pair<double, double> getInterval();
double calculateIntegral(
  std::pair<double, double> interval,
  int step,
  double x
);
double calculateFormula(double x, double deltaX);
void printResult(double result);

int main() {

  printResult(
    calculateIntegral(
      getInterval(), 0, getInterval().first
    )
  );

  return 0;
}

std::pair<double, double> getInterval() {
  double lowX = 2, highX = 3;
  int step = 0;
  
  return std::pair<double, double> (lowX, highX);
}

double calculateIntegral(
  std::pair<double, double> interval,
  int step,
  double x
) {
  double lowX = interval.first;
  double highX = interval.second;
  int accuracy = 10000;
  double deltaX = abs(highX - lowX) / accuracy;

  if (x == lowX) {
    x += deltaX / 2;
  }

  if (step == accuracy - 1) {
    return calculateFormula(x, deltaX);
  } else {
    return calculateIntegral(interval, ++step, x + deltaX) +
    calculateFormula(x, deltaX);
  }
}

double calculateFormula(double x, double deltaX) {
  return deltaX * (7 * pow(x, 3) - pow(x, 2) + 3 * x + 2);
};

void printResult(double result) {
  std::cout << "\nResult: " << result << std::endl << std::endl;
}
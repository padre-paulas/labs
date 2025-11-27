#include <iostream> 

double sum(double A[][5]);

int main() {

  double A[][5] = {{123.4}};

  double s = sum(A);
  std::cout << s << std::endl;

  return 0;
}

double sum(double A[][5]) {
  double s = 0;
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      s += A[i][j];
    }
  }
  return s;
}
#include <iostream>
#include <iomanip>
#define N 2
using namespace std;
// Variant 7;

void calculateSum();

int main() {

  calculateSum();

  return 0;
}

void calculateSum() {

  srand(time(0));

  int arr[N][N] = {{}};
  int sum(0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      
      arr[i][j] = rand() % 201 - 100;
      cout << setw(5) << arr[i][j] << "  ";
    }
    cout << endl;
    for (int k = i + 1; k < N; k++) {
      sum += arr[i][k];
    }
  }

  cout << "The sum is " << sum << endl;
}
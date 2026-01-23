#include <iostream>
#include <ctime>
#include <iomanip>
#define N 10
using namespace std;
// Variant 7

int main() {

  srand(time(0));

  int arr[N];

  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 201 - 100;
  }

  int count(1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {

      if (i == j) continue;

      if (arr[i] == arr[j]) {
        count++;
      }
    }
    cout << "Element " << setw(5) << arr[i] << " appeared " << setw(4) << count << " times" << endl; 
    count = 1;
  }
  return 0;
}


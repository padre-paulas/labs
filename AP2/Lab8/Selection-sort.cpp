#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
  size_t n = arr.size();
  for (size_t i = 0; i < n - 1; ++i) {
    size_t minIdx = i;
    for (size_t j = i + 1; j < n; ++j)
      if (arr[j] < arr[minIdx]) minIdx = j;
    if (minIdx != i) std::swap(arr[i], arr[minIdx]);
  }
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11, 1, 1, 1, 1, -999, 1 ,1 ,1 ,1 ,9};

  selectionSort(arr);

  for (int x : arr) std::cout << x << " ";
  std::cout << "\n";
}
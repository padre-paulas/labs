#include <algorithm>
#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr, int exp) {
  std::vector<int> output(arr.size());
  std::vector<int> count(10, 0);

  for (int x : arr) ++count[(x / exp) % 10];

  for (int i = 1; i < 10; ++i) count[i] += count[i - 1];

  for (int i = arr.size() - 1; i >= 0; --i) {
    output[--count[(arr[i] / exp) % 10]] = arr[i];
  }

  arr = output;
}

void radixSort(std::vector<int>& arr) {
  int maxVal = *std::max_element(arr.begin(), arr.end());

  for (int exp = 1; maxVal / exp > 0; exp *= 10) countingSort(arr, exp);
}

int main() {
  std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

  radixSort(arr);

  for (int x : arr) std::cout << x << " ";
  std::cout << "\n";
}
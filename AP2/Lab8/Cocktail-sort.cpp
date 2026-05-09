#include <iostream>
#include <vector>

void cocktailSort(std::vector<int>& arr) {
  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    for (int i = left; i < right; ++i)
      if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
    --right;

    for (int i = right; i > left; --i)
      if (arr[i] < arr[i - 1]) std::swap(arr[i], arr[i - 1]);
    ++left;
  }
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11, 90, 3, 1, 1, -999, 1, 1, 1, 1, -9999, 1, 1, 1, 1};

  cocktailSort(arr);

  for (int x : arr) std::cout << x << " ";
  std::cout << "\n";
}
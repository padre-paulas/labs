#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void modifier_thread(std::vector<std::vector<int>>& matrix,
                     std::vector<std::atomic<bool>>& row_ready) {
  for (size_t i = 0; i < matrix.size(); ++i) {
    if (matrix[i].empty()) continue;

    int last_element = matrix[i].back();

    for (size_t j = 0; j < matrix[i].size() - 1; ++j) {
      if (matrix[i][j] % 3 == 0) {
        matrix[i][j] = last_element;
      }
    }

    row_ready[i] = true;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}

void printer_thread(const std::vector<std::vector<int>>& matrix,
                    std::vector<std::atomic<bool>>& row_ready) {
  for (size_t i = 0; i < matrix.size(); ++i) {
    if (matrix[i].empty()) continue;

    while (!row_ready[i]) {
      std::this_thread::yield();
    }

    int last_element = matrix[i].back();
    bool meets_criteria = false;

    for (size_t j = 0; j < matrix[i].size() - 1; ++j) {
      if (matrix[i][j] == last_element) {
        meets_criteria = true;
        break;
      }
    }

    if (meets_criteria) {
      std::cout << "Row " << i << " matched! Output: ";
      for (int val : matrix[i]) {
        std::cout << val << " ";
      }
      std::cout << "\n";
    }
  }
}

int main() {
  std::vector<std::vector<int>> matrix = {
      {3, 5, 6, 9}, {1, 2, 4, 7}, {10, 12, 5, 8}};

  int num_rows = matrix.size();

  std::vector<std::atomic<bool>> row_ready(num_rows);
  for (int i = 0; i < num_rows; ++i) {
    row_ready[i] = false;
  }

  std::cout << "Starting concurrent processing...\n\n";

  std::thread t1(modifier_thread, std::ref(matrix), std::ref(row_ready));
  std::thread t2(printer_thread, std::cref(matrix), std::ref(row_ready));

  t1.join();
  t2.join();

  std::cout << "\nProcessing complete.\n";

  return 0;
}
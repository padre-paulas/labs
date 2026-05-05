#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class WordCounter {
 public:
  explicit WordCounter(size_t size = 16)
      : tableSize(size), count(0), buckets(size) {}

  void add(const std::string& word) {
    if (static_cast<double>(count) / tableSize > 0.75) resize();

    size_t index = hash(word);
    for (auto& entry : buckets[index]) {
      if (entry.first == word) {
        ++entry.second;
        return;
      }
    }
    buckets[index].push_back({word, 1});
    ++count;
  }

  void printAll() const {
    std::vector<std::pair<std::string, int>> all;
    for (const auto& bucket : buckets)
      for (const auto& entry : bucket) all.push_back(entry);

    std::sort(all.begin(), all.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    std::cout << "\n=== Word Frequencies ===\n";
    for (const auto& entry : all)
      std::cout << entry.first << ": " << entry.second << "\n";
    std::cout << "Unique words: " << count << "\n";
  }

 private:
  size_t tableSize, count;
  std::vector<std::vector<std::pair<std::string, int>>> buckets;

  size_t hash(const std::string& key) const {
    size_t h = 5381;
    for (char c : key) h = h * 33 ^ static_cast<size_t>(c);
    return h % tableSize;
  }

  void resize() {
    size_t newSize = tableSize * 2;
    std::vector<std::vector<std::pair<std::string, int>>> newBuckets(newSize);
    for (const auto& bucket : buckets)
      for (const auto& entry : bucket) {
        size_t h = 5381;
        for (char c : entry.first) h = h * 33 ^ static_cast<size_t>(c);
        newBuckets[h % newSize].push_back(entry);
      }
    tableSize = newSize;
    buckets = std::move(newBuckets);
  }
};

static std::string normalize(const std::string& word) {
  std::string result;
  for (char c : word)
    if (std::isalpha(static_cast<unsigned char>(c)))
      result += std::tolower(static_cast<unsigned char>(c));
  return result;
}

int main() {
  std::ifstream file("input.txt");
  if (!file) {
    std::cerr << "Cannot open input.txt\n";
    return 1;
  }

  WordCounter counter;
  std::string word;
  while (file >> word) {
    std::string clean = normalize(word);
    if (!clean.empty()) counter.add(clean);
  }

  counter.printAll();
  return 0;
}
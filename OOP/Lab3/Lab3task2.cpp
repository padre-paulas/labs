#include <iostream>
#include <fstream>
#include <string>

void isWordOdd(char ch, int& oddCount, int& charCount);
void areBracesCorrect(char ch, int &braceBalance, int &braceMistakes);
void copy();

int main() {
  copy();
  return 0;
}

void copy() {
  std::ifstream ifs("file_input.txt");
  if (!ifs.is_open()) return;
  std::ofstream ofs("file_output.txt", std::ios::trunc);
  if (!ofs.is_open()) return;
  char ch;
  int oddCount = 0;
  int charCount = 0;
  int letterCounts[26] = {0};
  int braceBalance = 0;
  int braceMistakes = 0;

  while (ifs.get(ch)) {
    ofs.put(ch);
    std::cout << ch;
    isWordOdd(ch, oddCount, charCount);
    areBracesCorrect(ch, braceBalance, braceMistakes);
  }
  braceMistakes += braceBalance;
  std::cout << " oddCount: " << oddCount << " charCount: " 
  << charCount << " brace mistakes: " << braceMistakes;
}

void isWordOdd(char ch, int& oddCount, int& charCount) {
  if (ch != '-') {
    if (isspace(ch) || ispunct(ch)) {
      if (charCount > 0) {
        if (charCount % 2 != 0) ++oddCount;
        charCount = 0;
      }
      return;
    }
  }
  ++charCount;
}

void countLetters(char ch, int letterCounts[]) {
  char lower = tolower(ch);

  if (lower >= 'a' && lower <= 'z') {
    letterCounts[lower - 'a']++;
  }
}

void areBracesCorrect(char ch, int &braceBalance, int &braceMistakes) {
  if (ch == '(') {
    ++braceBalance;
  }
  else if (ch == ')') {
    if (braceBalance > 0) {
      --braceBalance;
    } else {
      ++braceMistakes;
    }
  }
}

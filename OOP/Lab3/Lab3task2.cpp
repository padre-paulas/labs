#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>

void isWordOdd(char ch, int& oddCount, int& charCount);
void areBracesCorrect(char ch, int &braceBalance, int &braceMistakes);
void copy();
void deleteOddNumbers();
void countLetters(char ch, int letterCounts[]);
void printLetterCounts(int letterCounts[]);

int main() {
  copy();
  deleteOddNumbers();
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
    isWordOdd(ch, oddCount, charCount);
    areBracesCorrect(ch, braceBalance, braceMistakes);
    countLetters(ch, letterCounts);
  }
  braceMistakes += braceBalance;
  std::cout << "\nNumber of odd words: " << oddCount
  << "\nNumber of brace mistakes: " << braceMistakes;
  printLetterCounts(letterCounts);
}

void printLetterCounts(int letterCounts[]) {
  char letter = 'a';
  std::cout << "\nLetter counts:\n";
  for (int i = 0; i < 26; i++) {
    std::cout << letter << ": " << letterCounts[i] << std::endl;
    ++letter;
  }
  std::cout << std::endl;
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

void deleteOddNumbers() {
  std::ifstream ifs("file_output.txt");
  if (!ifs.is_open()) return;

  std::ofstream ofs("file_output_tmp.txt", std::ios::trunc);
  if (!ofs.is_open()) return;
  char ch;
  long long num = 0;
  int numLength = 0;
  bool inNumber = false;

  while (ifs.get(ch)) {
    if (std::isdigit(ch)) {
      inNumber = true;
      num = num * 10 + (ch - '0');
      ++numLength;
    } else {
      if (inNumber) {
        if (num % 2 == 0) {
          ofs << num; 
        } else {
          for (int i = 0; i < numLength; ++i) ofs << ' ';
        }
        num = 0;
        numLength = 0;
        inNumber = false;
      }
      ofs << ch;
    }
  }

  if (inNumber) {
    if (num % 2 == 0) {
      ofs << num;
    } else {
      for (int i = 0; i < numLength; ++i) ofs << ' ';
    }
  }

  ifs.close();
  ofs.close();
  std::remove("file_output.txt");
  std::rename("file_output_tmp.txt", "file_output.txt");
}
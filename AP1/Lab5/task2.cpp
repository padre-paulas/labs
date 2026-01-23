#include <iostream>
#include <cctype>
using namespace std;

void insertString();

int main() {

  insertString();

  return 0;
}

void insertString() {

  string S1, S2;

  cout << "\n==================================\n";
  cout << "Enter S1: ";
  getline(cin, S1);
  
  cout << "Enter S2: ";
  getline(cin, S2);

  for (int i = 0; i < S2.length(); i++) {
    if (!isalpha(S2[i]) && !isdigit(S2[i])) {
      S1 += ' ';
      S1 += S2[i];
    }
  }
  cout << S1 << endl;
  cout << "\n==================================\n";
}


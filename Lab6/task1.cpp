#include <iostream>

bool checkString();

int main() {
  fputs("\nThis program checks for double letters.\nEnter a string: ", stdout);
  bool result = checkString();
  result ? fputs("Your string has double letters.\n\n", stdout) :
  fputs("Your string doesn't have double letters.\n\n", stdout);

  return 0;
}

bool checkString() {
  char *string = new char[256];
 
  fgets(string, 256, stdin);

  int len = strlen(string) - 1;

  for (int i = 0; i < len; i++) {
    if (string[i] == string[i+1]) {
      delete[] string;
      return true;
    }
  }
  delete[] string;
  return false;
}
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS


int main() {

  char cat[20] = "cat";

  char *str;

  str = cat;

  std::cout << *str << std::endl;

  return 0;
}
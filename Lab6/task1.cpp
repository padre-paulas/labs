#include <iostream>


int main() {

  char *string = new char[256];
 
  fgets(string, 256, stdin);
  fputs(string, stdout);

  delete[] string;


  return 0;
}
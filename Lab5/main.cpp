#include <iostream>

int main() {

  // char text1[] = "We are learning";
  // char word[] = "hi";

  // for (int n = 0; n < 11; n++) {
  //   *(text1 + n) = *(word + n);
  // }
  // printf("%s", text1);

  // char text[30];

  // scanf("%s", text);
  // printf("%s\n", text);

  // char * gets(char * str);
  // int puts(const char *str); // deprecated

  // char * fgets(char * str, int num, FILE * stream);
  // int fputs(const char * str, FILE * stream);

  printf("\n**********************************************\n");
  printf("Hi! Enter your full name: ");

  char fullName[256];
  int i(0);
  // int first(0), second(0), third(0);
  char first[256], second[256], third[256];
  char ch;
  int spaces(0);
  int skip(0);

  while ((ch = getchar()) != '\n' && ch != EOF && i < 256) {
    // if (ch == *" ") {
    //   spaces++;
    // }
    // fullName[i] = ch;
    if (ch == ' ') {
      skip++;
    }
    if (skip == 0) {
      first[i] = ch;
    } else if (skip == 1) {
      second[i] = ch;
    } else if (skip == 2) {
      third[i] = ch;
    }
    std::cout << skip << std::endl;
    i++;
  }
  fullName[i] = '\0';
  first[i] = '\0';
  second[i] = '\0';
  third[i] = '\0';

  if (strlen(first) > strlen(second) && strlen(first) > strlen(third)) {
    printf("%s\n", first);
    std::cout << "well comeee" << std::endl;
  } else if (strlen(second) > strlen(third)) {
    printf("%s\n", second);
    std::cout << "well comeee 2222" << std::endl;
  } else {
    printf("%s\n", third);
    std::cout << "well comeee 3333" << std::endl;
  }

  

  return 0;
}
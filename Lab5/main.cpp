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

  while ((ch = getchar()) != '\n'&& ch != EOF && i < 256) {
    // if (ch == *" ") {
    //   spaces++;
    // }
    fullName[i++] = ch;
    if (ch == *" ") {
      skip++;
    }
    if (skip == 0) {
      first[i] = ch;
    } else if (skip == 1) {
      second[i] = ch;
    } else if (skip == 2) {
      third[i] = ch;
    }
  }
  fullName[i] = '\0';

  if (strlen(first) > strlen(second) && strlen(first) > strlen(third)) {
    printf("%s", first);
  } else if (strlen(second) > strlen(third)) {
    printf("%s", second);
  } else {
    printf("%s", third);
  }

  // printf("%s\n", fullName);
  // int longestPos = 0;
  // char *p = strtok(fullName, " ");

  // for (i = 0; i < strlen(fullName); i++) {
  //   p = strtok(NULL, " ");

  // }

  

  // std::tuple<int, char> first;
  // std::tuple<int, char> second;
  // std::tuple<int, char> third;

  // for (i = 0; i < strlen(fullName); i++) {
  //   if (fullName[i] != *(" ")) {
  //     i++;
  //   } 
  // }

  return 0;
}
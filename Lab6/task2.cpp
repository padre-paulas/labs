#include <iostream> 

char* getSentence();
void sortWords(char *sentence);

int main() {

  sortWords(getSentence());

  return 0;
}

char* getSentence() {

  char *sentence = new char[256];

  fputs("Hi! This program sorts the words by length in the sentence you input.\n", stdout);
  fputs("Enter a sentence: ", stdout);

  fgets(sentence, 256, stdin);

  return sentence;
}

void sortWords(char *sentence) {
  char *ptr[256][100];

  int i = 0;

  while (true) {
    if (sentence[i] == '0') break;
    *ptr[i][0] = sentence[i];

  }

  delete[] sentence;
}
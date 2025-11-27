#include <iostream> 

char* getSentence();
void sortWords(char *sentence);

int main() {

  sortWords(getSentence());

  return 0;
}

char* getSentence() {

  char *sentence = new char[256];

  fputs("\nHi! This program sorts the words by length in the sentence you input.\n", stdout);
  fputs("Enter a sentence: ", stdout);

  fgets(sentence, 256, stdin);

  return sentence;
}

void sortWords(char *sentence) {

  char *words[256];
  int w = 0, ch = 0;
  int longestWord = 0;

  words[w] = new char[256];

  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] == ' ' || sentence[i] == '\n') {
      if (ch > 0) {
        words[w][ch] = '\0';
        w++;
        words[w] = new char[256];
        ch = 0;
      }
    } else {
      words[w][ch++] = sentence[i];
    }
  }

  if (ch > 0) {
    words[w][ch] = '\0';
  }

  char *temp;

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (strlen(words[j]) > strlen(words[j + 1])) {
        temp = words[j];
        words[j] = words[j + 1];
        words[j + 1] = temp;
      }
    }
  }

  fputs("\n", stdout);

  for (int i = 0; i < w; i++) {
    fputs(words[i], stdout);
    fputs("\n", stdout);
    delete[] words[i];
  }

  fputs("\n", stdout);

  delete[] sentence;
}
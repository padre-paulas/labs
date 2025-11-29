#include <iostream> 
#include <fstream>

std::pair<int, int> readText();
std::string getFileName();

int main() {

  readText();

  return 0;
}

std::pair<int, int> readText() {
  std::fstream f1;
  int lineCount = 1, paragraphCount = 1;
  char previous = '\0', ch;
  std::string fileName = getFileName();

  f1.open(fileName, std::ios::in);

  if (!f1) {
    std::cout << "Couldn't access the file\n";
    return { -1, -1 };
  }

  while (f1.get(ch)) {
    if (ch == '\n') {
      lineCount++;
    }
    if (previous == '\n' && ch == '\n') {
      paragraphCount++;
    }

    previous = ch;
  }

  f1.close();

  std::cout << "\nLines: " << lineCount << " Paragraphs: " << paragraphCount << "\n\n";

  return { lineCount, paragraphCount };
}

std::string getFileName() {
  char fileName[256];
  std::cout << "\nEnter file name in currect directory: ";
  std::cin >> fileName; 
  return fileName;
}
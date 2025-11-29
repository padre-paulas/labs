#include <fstream> 
#include <iostream> 


int main() {

  std::ifstream is;
  std::ofstream os("file.txt");
  std::fstream fs;

  // os("file.txt");

  if (!os) {
    std::cout << "error opening file\n";
    return 1;
  }

  os << "Hello world!\n";
  os.close();
  

  return 0;
}
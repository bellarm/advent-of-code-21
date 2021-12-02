#include <iostream>
#include <fstream>
#include <list>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("input/day01.txt", std::ios::in);

  std::string line;
  int previous = -1;
  int increment = 0;
  while(getline(inputFile, line)) {
    int current = stoi(line);
    if (previous != -1) {
      if (current > previous) {
        increment++;
      }
    }
    previous = current;
  }
  inputFile.close();

  std::cout << "part 1: " << increment << "\n";

  return 0;
}


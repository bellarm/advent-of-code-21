#include <iostream>
#include <fstream>
#include <list>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("input/day01.txt", std::ios::in);

  std::string line;
  int p_1 = -1;
  int p_2 = -1;
  int p_3 = -1;
  int increment = 0;
  int previousSum = 0;
  int currentSum = 0;
  while(getline(inputFile, line)) {
    int current = stoi(line);
    if (p_1 == -1) {
      p_1 = current;
    } else if (p_2 == -1) {
      p_2 = current;
    } else if (p_3 == -1) {
      p_3 = current;
    } else {
      previousSum = p_1 + p_2 + p_3;
      currentSum = p_2 + p_3 + current;
      
      if (currentSum > previousSum) {
        increment++;
      }
      p_1 = p_2;
      p_2 = p_3;
      p_3 = current;
    }
  }
  inputFile.close();

  std::cout << "part 2: " << increment << "\n";

  return 0;
}


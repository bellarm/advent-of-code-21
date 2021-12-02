#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstring>

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("input/day02.txt", std::ios::in);

  std::string line;
  int y = 0;
  int x = 0; 
  int aim = 0;

  while(getline(inputFile, line)) {
    std::string direction  = strtok(const_cast<char*>(line.c_str()), " ");
    int value = atoi(strtok(NULL, " "));

    if (direction.compare("forward") == 0) {
      x += value;
      if (aim != 0) {
        y += aim * value;
      }
    } else if (direction.compare("up") == 0) {
      aim -= value;
    } else if (direction.compare("down") == 0) {
      aim += value;
    }
  }
  inputFile.close();

  int thing = x * y;
  std::cout << "x: " << x << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "part 2: " << thing << "\n";

  return 0;
}


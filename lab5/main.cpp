#include "DDList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void readFile();

int main()
{
  return 0;
}

void readFile()
{
  std::ifstream file("balls");
  std::string line;

  while (getline(file, line)) {
    //std::istringstream fileLine(line);
    //fileLine >> data.man >> data.sportType >> data.color >> data.size;
    //S.push(data);
  }
  file.close();
}
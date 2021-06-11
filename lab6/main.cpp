#include "tree.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void ReadFile(Tree **, Flower &);

int main()
{
  Tree* T = NULL;
  Flower data;
  ReadFile(*T, data);
  PrintLeftRightRight(T);
  return 0;
}

void ReadFile(Tree **T, Flower &data)
{
  std::ifstream file("flowers");
  std::string line;

  while (getline(file, line)) {
    std::istringstream fileLine(line);
    fileLine >> data.name >> data.amount >> data.price >> data.isWild;
    Add(T, data);
  file.close();
}
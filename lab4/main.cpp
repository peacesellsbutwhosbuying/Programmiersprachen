#include<iostream>
#include<fstream>
#include<sstream>
#include"queue.h"

using std::cout;
using std::cin;
using std::endl;

void readFile(Jurnal &, Queue &);

int main()
{
  
}

void readFile(Jurnal &data, Queue &prod) {
  std::ifstream file("bin_data", std::ios::binary);
  std::string line;
  char *binData = new char[30];
  while (file.read(binData, 30)) {
    data.id = *reinterpret_cast<int*>(binData);
    data.number = *reinterpret_cast<int*>(binData + 4);
    data.year = *reinterpret_cast<int*>(binData + 4 + 4);
    data.price = *reinterpret_cast<int*>(binData + 4 + 4 + 8);
    
    prod.push(data);
  }
  file.close();
}
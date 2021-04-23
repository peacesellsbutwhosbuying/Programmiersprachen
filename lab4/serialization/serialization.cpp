#include<fstream>
#include<sstream>

void serialization(int, int, int, double);
void clearFile();

int main()
{
  int id;
  int num; 
  int year;
  double price; 
  std::ifstream file("data");
  std::string line;

  while (getline(file, line)) {
    std::istringstream fileLine(line);
    fileLine >> id >> num >> year >> price;
    serialization(id, num, year, price);
  }
  file.close();
}

void serialization(int id, int number, int year, double price)
{
  char *binData;

  char *d1 = reinterpret_cast<char*>(&id);
  char *d2 = reinterpret_cast<char*>(&number);
  char *d3 = reinterpret_cast<char*>(&year);
  char *d4 = reinterpret_cast<char*>(&price);

  int n1 = sizeof(id);
  int n2 = sizeof(number);
  int n3 = sizeof(year);
  int n4 = sizeof(price);
  int n = n1 + n2 + n3 + n4;

  binData = new char[n];

  for(int i{}; i < n1; i++) binData[i] = d1[i];
  for(int i{}; i < n2; i++) binData[i + n1] = d2[i];
  for(int i{}; i < n3; i++) binData[i + n1 + n2] = d3[i];
  for(int i{}; i < n4; i++) binData[i + n1 + n2 + n3] = d4[i];

  //clearFile();

  //Зпись в файл
  std::fstream fileToOut("../bin_data", std::ios::out | std::ios::binary);
  fileToOut.write((char*)&n, sizeof(int));
  fileToOut.write(binData, n);
  fileToOut.close();
}

void clearFile()
{
  std::fstream clearing("../bin_data", std::ios::out | std::ios::binary);
  clearing.close();
}
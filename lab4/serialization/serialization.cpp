#include<fstream>
#include<sstream>

void serialization(int, int, int, double);

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

  int n = 30;//4 + 4 + 4 + 8

  binData = new char[n];

  for(int i{}; i < 4; i++) binData[i] = d1[i];
  for(int i{}; i < 4; i++) binData[i + 4] = d2[i];
  for(int i{}; i < 4; i++) binData[i + 8] = d3[i];
  for(int i{}; i < 8; i++) binData[i + 12] = d4[i];

  //Зпись в файл
  std::ofstream fileToOut("../bin_data", std::ios::binary);
  for(int i{1}; i <= n; i++) fileToOut.write(binData, n);
  fileToOut.close();
}
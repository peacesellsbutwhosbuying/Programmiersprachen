#include<fstream>
#include<sstream>
#include<string>

void serialization(char* &, int &, std::string, int, int, double);

int main()
{
  std::string name;
  int num; 
  int year;
  double price; 
  std::ifstream file("../data");
  std::fstream binData("../binData", std::ios::out | std::ios::binary);
    std::string line;
    char* data;
    int n;
    while (getline(file, line)) {
      std::istringstream fileLine(line);
      fileLine >> name >> num >> year >> price;
      serialization(data, n, name, num, year, price);
      binData.write((char*)&n, sizeof(int));
      binData.write(data, n);
    }
  file.close();
  delete [] data;
}

void serialization(char* &data, int &n, std::string name, int num, int year, double price)
{
   size_t s1 = name.size();
   int n1_size = sizeof(size_t);
   int n2 = s1;
   int n3 = sizeof(int);
   int n4 = sizeof(int);
   int n5 = sizeof(double);
   n = n1_size + n2 + n3 + n4 + n5;

   data = new char[n];
   char* d1 = reinterpret_cast<char*> (&s1);
   char* d2 = const_cast<char*> (name.c_str());
   char* d3 = reinterpret_cast<char*> (&num);
   char* d4 = reinterpret_cast<char*> (&year);
   char* d5 = reinterpret_cast<char*> (&price);

   for(int i{}; i <= n1_size; i++) data[i] = d1[i];
   for(int i{}; i <= n2; i++) data[i + n1_size] = d2[i];
   for(int i{}; i <= n3; i++) data[i + n1_size + n2] = d3[i];
   for(int i{}; i <= n4; i++) data[i + n1_size + n2 + n3] = d4[i];
   for(int i{}; i <= n5; i++) data[i + n1_size + n2 + n3 + n4] = d5[i];

}


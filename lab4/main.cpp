#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"queue.h"

using std::cout;
using std::cin;
using std::endl;

void getSeria(char* &, int &, Jurnal);
void getDeSeria(char* , int , Jurnal &);

int main()
{
  Jurnal j = {"mag", 12, 96, 89.4};
  Jurnal j1;
  j.out(); 
  int n;
  char* data;
  getSeria(data, n, j);
  getDeSeria(data, n, j1);
  j1.out();
  delete [] data;


  return 0;
}

void getSeria(char* &data, int &n, Jurnal prod)
 {
   size_t s1 = prod.name.size();
   int n1_size = sizeof(size_t);
   int n2 = s1;
   int n3 = sizeof(int);
   int n4 = sizeof(int);
   int n5 = sizeof(double);
   n = n1_size + n2 + n3 + n4 + n5;

   data = new char[n];
   char* d1 = reinterpret_cast<char*> (&s1);
   char* d2 = const_cast<char*> (prod.name.c_str());
   char* d3 = reinterpret_cast<char*> (&prod.number);
   char* d4 = reinterpret_cast<char*> (&prod.year);
   char* d5 = reinterpret_cast<char*> (&prod.price);

   for(int i{}; i <= n1_size; i++) data[i] = d1[i];
   for(int i{}; i <= n2; i++) data[i + n1_size] = d2[i];
   for(int i{}; i <= n3; i++) data[i + n1_size + n2] = d3[i];
   for(int i{}; i <= n4; i++) data[i + n1_size + n2 + n3] = d4[i];
   for(int i{}; i <= n5; i++) data[i + n1_size + n2 + n3 + n4] = d5[i];
 }

 void getDeSeria(char* data, int n, Jurnal &prod)
 {
   int n1_size, n2, n3, n4, n5;
   n1_size = sizeof(size_t);
   n3 = sizeof(int);
   n4 = sizeof(int);
   n5 = sizeof(double);
   size_t p = *reinterpret_cast<size_t*>(data);
   n2 = p;
   std::string s1(data + n1_size, p);
   prod.name = s1;
   prod.number = *reinterpret_cast<int*>(data + n1_size + n2);
   prod.year = *reinterpret_cast<int*>(data + n1_size + n2 + n3);
   prod.price = *reinterpret_cast<double*>(data + n1_size + n2 + n3 + n4);
 }
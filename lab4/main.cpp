#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


void getSeria(char* &, int &, Journal);
void getDeSeria(char* , int , Journal &);
bool readBinaryFile(Queue &);
void info(Queue);
void addJurnal(Queue &);
void removeJurnal(Queue &);
void clearQueue(Queue &);

int main()
{
  Journal j;
  Queue prod;
  readBinaryFile(prod);

  int key;
  
  do
  {
    cout << ">----------------MENU----------------<" << endl;
    cout << "(1) - Add journal" << endl;
    cout << "(2) - Remove journal" << endl;
    cout << "(3) - Clear the queue" << endl;
    cout << "(4) - View the queue" << endl;
    cout << "(0) - Escape" << endl;
    cout << ">------------------------------------<" << endl;

    cout << "--->";
    cin >> key;
    cout << endl;

    switch(key) 
    {
      case 1: addJurnal(prod); break;
      case 2: removeJurnal(prod); break;
      case 3: clearQueue(prod); break;
      case 4: info(prod); break;
      default: cout << "Error! Try again!" << endl; break;
      case 0: return 0;
    }
  } while (key);
  
  char* data;
  int n;
  while(prod.count)
  {
    prod.pop(data, n);
    delete[] data;
  }

  return 0;
}

void getSeria(char* &data, int &n, Journal prod)
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

 void getDeSeria(char* data, int n, Journal &prod)
 {
   int n1_size, n2, n3, n4, n5;
   n1_size = sizeof(size_t);
   n3 = sizeof(int);
   n4 = sizeof(int);
   n5 = sizeof(double);
   size_t p = *reinterpret_cast<size_t*>(data);
   n2 = p;
   string s1(data + n1_size, p);
   prod.name = s1;
   prod.number = *reinterpret_cast<int*>(data + n1_size + n2);
   prod.year = *reinterpret_cast<int*>(data + n1_size + n2 + n3);
   prod.price = *reinterpret_cast<double*>(data + n1_size + n2 + n3 + n4);
 }

 bool readBinaryFile(Queue &prod) 
 {
   std::fstream binaryInput("binData", std::ios::in | std::ios::binary);
   if(!binaryInput) 
   {
     cout << "There's no such file :(" << endl;
     return false;
   }

   int n;
   Journal j;
   while (!binaryInput.eof())
   {
     if(binaryInput.read((char*)&n, sizeof(int)))
     {
       char* binaryData = new char[n];
       binaryInput.read(binaryData, n);
       prod.push(binaryData, n);

       getDeSeria(binaryData, n, j);
       cout << "--------------------------------" << endl;
       j.out();
       cout << "--------------------------------" << endl;
       delete [] binaryData;
     }
   }
   binaryInput.close();
   return true;
 }

 void info(Queue prod)
 {
   if(prod.count)
   {

   
   Journal j;
   int n;
   getDeSeria(prod.first->data, n, j);
   cout << ">---------------------------<" << endl;
   cout << "Size: " << prod.count << endl;
   cout << "Name: " << j.name << endl;
   cout << "Number:" << j.number << endl;
   cout << "Year: " << j.year << endl;
   cout << "Price: " << j.price << endl;
   cout << ">---------------------------<" << endl;
   }
   else 
   {
     cout << "The queue is empty" << endl;
   }

 }

void addJurnal(Queue &prod)
 {
  int n;
  Journal j;
  char* data;

  cout << "Name --> "; cin >> j.name; cout << endl;
  cout << "Number --> "; cin >> j.number; cout << endl;
  cout << "Year --> "; cin >> j.year; cout << endl;
  cout << "Price --> "; cin >> j.price; cout << endl;

  getSeria(data, n, j);

  prod.push(data, n);

  cout << "Journal is added" << endl;
  delete[] data;
 }

void removeJurnal(Queue &prod)
{
  if(prod.count)
  {
    Journal j;
    Journal tj;
    Queue temp;
    cout << "Name: "; cin >> tj.name; cout << endl;
    cout << "Number: "; cin >> tj.number; cout << endl;
    cout << "Year: "; cin >> tj.year; cout << endl;
    cout << "Price: "; cin >> tj.price; cout << endl;
    char* data;
    int n;
    bool flag = false;

    while(prod.count)
    {
      prod.pop(data, n);
      getDeSeria(data, n, j);
      delete [] data;
      if(j.name != tj.name || j.number != tj.number || j.year != tj.year || j.price != tj.price)
      {
        getSeria(data, n, j);
        temp.push(data, n);
      }
      else
      {
        cout << "Journal is removed" << endl;
        flag = true;
        
      }
      
    }   
    if(!flag) cout << "No such journal was found" << endl;

    while(temp.count)
    {
      temp.pop(data, n);
      prod.push(data, n);
    }
    delete[] data;
  }  
  else 
  {
    cout << "The queue is empty" << endl;
  }

}

void clearQueue(Queue &prod) {
  char* data;
  int n;
  while(prod.count)
  {
    prod.pop(data, n);
    delete[] data;
  }
  cout << "Now the queue is empty" << endl;
}
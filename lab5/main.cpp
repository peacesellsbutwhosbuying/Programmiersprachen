#include "DDList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void readFile(Bunny &, DLList &);
void addFirstPosition(Bunny &, DLList &);
void addLastPosition(Bunny &, DLList &);
void addKPosition(Bunny &, DLList &);

int main()
{
  DLList S;
  Bunny data;
  readFile(data, S);

  int key;
  
  do {
    std::cout << "----------------MENU----------------" << std::endl;
    std::cout << "(1) - Add bunny first" << std::endl;
    std::cout << "(2) - Add bunny last" << std::endl;
    std::cout << "(3) - Clear the cart" << std::endl;
    std::cout << "(4) - View the cart" << std::endl;
    std::cout << "(0) - Escape" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    std::cout << "--->  ";
    std::cin >> key;
    std::cout << std::endl;

    switch(key) {
      case 1: addFirstPosition(data, S); break;
      case 2: addKPosition(data, S); break;
      case 3: cout << S.current->data.name; break;
      case 4: S.out(); break;
      default: std::cout << "Error! Try again!" << std::endl;
      case 0: return 0;
    }
  } while (key);
  S.clear();
  return 0;
}

void readFile(Bunny &data, DLList &S)
{
  std::ifstream file("bunny");
  std::string line;

  while (getline(file, line)) {
    std::istringstream fileLine(line);
    fileLine >> data.name >> data.age >> data.weight >> data.isHungry;
    S.addNext(data);
  }
  file.close();
}

void addFirstPosition(Bunny &data, DLList &S)
{
  cout << "Name: "; cin >> data.name; cout << endl;
  cout << "Age: "; cin >> data.age; cout << endl;
  cout << "Weight: "; cin >> data.weight; cout << endl;
  cout << "Hunger: "; cin >> data.isHungry; cout << endl;
  S.addFirst(data);
}

void addLastPosition(Bunny &data, DLList &S)
{
  cout << "Name: "; cin >> data.name; cout << endl;
  cout << "Age: "; cin >> data.age; cout << endl;
  cout << "Weight: "; cin >> data.weight; cout << endl;
  cout << "Hunger: "; cin >> data.isHungry; cout << endl;
  S.addLast(data);
}
//!
void addKPosition(Bunny &data, DLList &S)
{
  cout << "Count " << S.count << endl;

  int k = 0;
  while (k <= 0 || k >= S.count) 
  {
    cout << "k = "; cin >> k; cout << endl;    
  }
  cout << "Name: "; cin >> data.name; cout << endl;
  cout << "Age: "; cin >> data.age; cout << endl;
  cout << "Weight: "; cin >> data.weight; cout << endl;
  cout << "Hunger: "; cin >> data.isHungry; cout << endl;
  if(k == 1)
  {
    S.addFirst(data);
  }
  else
  {
    S.moveFirst();
    for(int i{1}; i < k-1; i++)
    {
      S.current = S.current->next;
    }
    S.addNext(data);
  }

}
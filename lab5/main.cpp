#include "DLList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void readFile(Bunny &, DLList &);
void getData(Bunny &);

void addToTheTop(Bunny &, DLList &);
void addToTheEnd(Bunny &, DLList &);
void addToTheK(Bunny &, DLList &);

void removeFromTheTop(Bunny &, DLList &);
void removeFromTheEnd(Bunny &, DLList &);
void removeFromTheK(Bunny &, DLList &);

void clearTheList(Bunny &, DLList &);

void writeFile(Bunny, DLList);

void sortByAge(Bunny &, DLList &);

int main()
{
  DLList S;
  Bunny data;
  readFile(data, S);

  int key;
  
  do {
    cout << "----------------MENU----------------" << endl;
    cout << "-Add bunny-:" << endl;
    cout << "(1) - to the top" << endl;
    cout << "(2) - to the end" << endl;
    cout << "(3) - to the k position" << endl;
    cout << "-Remove a bunny-" << endl;
    cout << "(4) - from the top" << endl;
    cout << "(5) - from the end" << endl;
    cout << "(6) - from the k position" << endl;
    cout << "-Sort-" << endl;
    cout << "(7) - by age" << endl;
    cout << "-Other-" << endl;
    cout << "(8) - Clear the list" << endl;
    cout << "(9) - Write file" << endl;
    cout << "(10) - Out" << endl;
    cout << "(0) - Escape" << endl;
    cout << "------------------------------------" << endl;

    cout << "--->  ";
    cin >> key;
    cout << endl;

    switch(key) {
      case 1: addToTheTop(data, S); break;
      case 2: addToTheEnd(data, S); break;
      case 3: 
      {
        if(S.count == 0)
        {
          addToTheTop(data, S);
        }
        else
        {
          addToTheK(data, S);
        }
      }; break;
      case 4: removeFromTheTop(data, S); break;
      case 5: removeFromTheEnd(data, S); break;
      case 6:
      {
        if(S.count == 0)
        {
          cout << "Error! The list is empty." << endl;
        }
        else
        {
          removeFromTheK(data, S);
        }
      }; break;
      case 7: sortByAge(data, S); break;
      case 8: system("clear"); S.clear(); break;
      case 9: writeFile(data, S); break;
      case 10: S.out(); break;
      default: cout << "Error! Try again!" << endl;
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

void getData(Bunny &data)
{
  cout << "Name: "; cin >> data.name; cout << endl;
  cout << "Age: "; cin >> data.age; cout << endl;
  cout << "Weight: "; cin >> data.weight; cout << endl;
  cout << "Hunger: "; cin >> data.isHungry; cout << endl;
}

void addToTheTop(Bunny &data, DLList &S)
{
  system("clear");
  if(S.count != 0)
  {
    getData(data);
    S.addFirst(data);
  }
  else
  {
    getData(data);
    S.init(data);
  }
  
}

void addToTheEnd(Bunny &data, DLList &S)
{
  system("clear");
  getData(data);
  S.addLast(data);
}

void addToTheK(Bunny &data, DLList &S)
{
  system("clear");
  cout << "Count " << S.count << endl;

  int k = 0;
  while (k <= 0 || k > S.count) 
  {
    cout << "k = "; cin >> k; cout << endl;    
  }
  getData(data);
  if(k == 1)
  {
    S.addFirst(data);
  }
  else
  {
    if(k == S.count){
      S.addLast(data);
    }
    else{
      S.moveFirst();
      for(int i{1}; i < k-1; i++)
      {
        S.current = S.current->next;
      }
      S.addNext(data);
    }
  }
}

void removeFromTheTop(Bunny &data, DLList &S)
{
  system("clear");
  if(S.count != 0)
  {
    S.delFirst(data);
  }
  else
  {
    cout << "Error! The list is empty." << endl;
  }
}

void removeFromTheEnd(Bunny &data, DLList &S)
{
  system("clear");
  if(S.count != 0)
  {
    S.delLast(data);
  }
  else
  {
    cout << "Error! The list is empty." << endl;
  }
}

void removeFromTheK(Bunny &data, DLList &S)
{
  system("clear");
  cout << "Count " << S.count << endl;

  int k = 0;
  while (k <= 0 || k > S.count) 
  {
    cout << "k = "; cin >> k; cout << endl;    
  }

  if(k == 1)
  {
    S.delFirst(data);
  }
  else
  {
    if(k == S.count){
      S.delLast(data);
    }
    else{
      S.moveFirst();
      for(int i{1}; i < k+1; i++)
      {
        S.current = S.current->next;
      }
      S.delPrev(data);
    }
  }
}

void writeFile(Bunny data, DLList S)
{
  system("clear");
  if(S.count == 0)
  {
    cout << "Warning! The list is empty." << endl;
  }
  system("clear");
  std::ofstream out("bunnyOut");
  S.moveFirst();
  for(int i{}; i < S.count; i++)
  {
    Bunny outData = S.current->data;
    out << outData.name << " " << outData.age << " " << outData.weight << " " << outData.isHungry << endl;
    S.moveNext();
  }
  out.close();
}

void sortByAge(Bunny &data, DLList &S)
{
  system("clear");

  Bunny temp;

  for(int i{}; i < S.count; i++)
  {
    S.moveLast();
    for(int j{S.count - 1}; j >= (i+1); j--)
    {
      if(S.current->data.age < S.current->prev->data.age)
      {
        temp = S.current->data;
        S.current->data = S.current->prev->data;
        S.current->prev->data = temp;
      }
      S.movePrev();
    }
  }
  S.out();
}
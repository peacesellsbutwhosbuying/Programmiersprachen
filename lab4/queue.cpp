#include <iostream>
#include<fstream>
#include "queue.h" 

bool Queue::push(char* data, int n) 
{
  
  /*char* d2 = reinterpret_cast<char*>(&data.number);
  char* d3 = reinterpret_cast<char*>(&data.year);
  char* d4 = reinterpret_cast<char*>(&data.price);
  char* binData = new char[30];
  
  for(int i{}; i < 4; i++) binData[i + 4] = d2[i];
  for(int i{}; i < 4; i++) binData[i + 4 + 4] = d3[i];
  for(int i{}; i < 8; i++) binData[i + 4 + 4 + 4] = d4[i];*/

  if (!first)
  {
    first = new Node;
    first->next = NULL;
    first->data = new char[n];
    first->n = n;

    for(int i{}; i < n; i++) 
    {
      first->data[i] = data[i];
    }
    count = 1;
  } 
  else 
  {
    Node *temp = first;
    while (temp->next != NULL) 
    {
      temp = temp->next;
    }
    temp->next = new Node;
    temp->next->data = new char[n];
    temp->next->n = n;
    for(int i{}; i < n; i++)
    {
      first->data[i] = data[i];
    }
    temp->next->next = NULL;
    count++;
  }
  //delete [] binData;
  return true;
}

bool Queue::pop(char* &data, int &n) 
{
  if (!first) return false;

  Node *temp = first->next;
  //data = first->data;
  n = first->n;
  for(int i{}; i < n; i++)
  {
    data[i] = first->data[i];
  }
  delete first->data;
  delete first;
  first = temp;
  count--;
  return true;
}


void Queue::info() {
  if(!first) {
    std::cout << "Queue is empty" << std::endl;
  }
  else {
    std::cout << "SIZE: " << count << std::endl;
    /*std::cout << "Id:" << first->data.name << std::endl;
    std::cout << "Number:" << first->data.number << std::endl;
    std::cout << "Year:" << first->data.year << std::endl;
    std::cout << "FIRST PRICE: " << first->data.price << std::endl;
    std::cout << ">----------------------<\n" << std::endl;*/
  }
}

void Jurnal::out()
{
  std::cout << "Jurnal:";
  std::cout << "\nName: " << name;
  std::cout << "\nNumber: " << number;
  std::cout << "\nYear: " << year;
  std::cout << "\nPrice: " << price << std::endl;
}
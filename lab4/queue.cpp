#include <iostream>
#include<fstream>
#include "queue.h" 

bool Queue::push(Jurnal data) 
{
  if (!first) {
    first = new Node;
    first->next = NULL;
    first->data = data;
    count = 1;
  } 
  else {
    Node *temp = first;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new Node;
    temp->next->data = data;
    temp->next->next = NULL;
    count++;
  }
  return true;
}

bool Queue::pop(Jurnal &data) 
{
  if (!first) return false;

  Node *temp = first->next;
  data = first->data;
  delete first;
  first = temp;
  count--;
  return true;
}

 void Queue::serialization(Jurnal &data) 
{
  int n, n1, n2, n3, n4;
  char *binData;

  char *d1 = reinterpret_cast<char*>(&data.id);
  char *d2 = reinterpret_cast<char*>(&data.number);
  char *d3 = reinterpret_cast<char*>(&data.year);
  char *d4 = reinterpret_cast<char*>(&data.price);

  n1 = sizeof(d1);
  n2 = sizeof(d2);
  n3 = sizeof(d3);
  n4 = sizeof(d4);
  n = n1 + n2 + n3 + n4;

  binData = new char[n];

  for(int i{}; i < n1; i++) binData[i] = d1[i];
  for(int i{}; i < n2; i++) binData[i + n1] = d2[i];
  for(int i{}; i < n2; i++) binData[i + n1 + n2] = d3[i];
  for(int i{}; i < n2; i++) binData[i + n1 + n2 + n3] = d4[i];

  //Зпись в файл
  std::ofstream fileToOut("bin_data", std::ios::binary);
  for(int i{1}; i <= 5; i++) fileToOut.write(binData, n);
  fileToOut.close();
}


/*void Queue::info() {
  if(!first) {
    std::cout << "The warehouse is empty" << std::endl;
  }
  else {
    std::cout << "\n>----WAREHOUSE INFO----<" << std::endl;
    std::cout << "SIZE: " << count << std::endl;
    std::cout << "FIRST PRICE: " << first->data.price << std::endl;
    std::cout << ">----------------------<\n" << std::endl;
  }
}*/
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
#include <iostream>
#include "queue.h"

bool Queue::push(Product data) {
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

bool Queue::pop(Product &data) {
  if (!first) return false;

  Node *temp = first->next;
  data = first->data;
  delete first;
  first = temp;
  count--;
  return true;
}
#include "stack.h"
#include <iostream>

using namespace std;

bool Stack::push(Ball data) {
  if (top == NULL) {
    top = new Node;
    top->prev = NULL;
    count = 1;
  }
  else {
    Node *temp = new Node;
    temp->prev = top;
    top = temp;
    count++;
  }
  top->data = data;
  return true;
}

bool Stack::pop(Ball &data) {
  if (top == NULL) return false;

  Node *temp = top->prev;
  data = top->data;
  delete top;
  top = temp;
  count--;
  return true;
}

void Stack::info() {
  if(!top) cout << "Stack is empty." << endl;

  else {
    cout << "---STACK INFO--- \n" << endl;
    cout << "Stack size: " << count << endl;
    cout << "Top manufacturer: " << top -> data.man << endl;
    cout << "Top sport type: " << top -> data.sportType << endl;
    cout << "Top color: " << top -> data.color << endl;
    cout << "Top size :" << top -> data.size << endl;
  }

}
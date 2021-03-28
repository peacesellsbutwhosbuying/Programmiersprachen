#include "stack.h"
#include <iostream>

using namespace std;

bool Stack::push(Ball d) {
  if (!top) {
    top = new Node;
    top->prev = NULL;

    count = 1;
  }

  else {
    Node *temp;
    temp = new Node;
    temp->prev = top;
    top = temp;

    count++;
  }

  top-> data.man = d.man;
  top->data.sportType = d.sportType;
  top->data.color = d.color;
  top->data.size = d.size;

  return true;
}

bool Stack::pop(Ball &d) {
  if (!top) return false;

  Node *temp = top -> prev;

  d.man = top->data.man;
  d.sportType = top->data.sportType;
  d.color = top->data.color;
  d.size = top->data.size;
  
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
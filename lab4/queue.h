#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include<string>

struct Jurnal {
  std::string name;  
  int number;
  int year;
  double price;

  void out();
};

struct Queue {
  struct Node {
    char* data;
    int n; //Seria leinght
    Node *next;
  };

  Node *first = NULL;
  int count = 0;

  bool push(char*, int);
  bool pop(char* &, int &);
  //void deSerialization();
  void info();
};

#endif
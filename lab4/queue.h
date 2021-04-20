#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>

struct Jurnal {
  int id;
  int number;
  int year;
  double price;
};

struct Queue {
  struct Node {
    Jurnal data;
    Node *next;
  };

  Node *first = NULL;
  int count = 0;
  bool push(Jurnal);
  bool pop(Jurnal &);
  void deSerialization(Jurnal &);
  void info();
};

#endif
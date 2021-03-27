#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>

struct Product {
  int amount;
  double price;
};

struct Queue {
  struct Node {
    Product data;
    Node *next;
  };

  Node *first = NULL;
  int count;
  bool push(Product);
  bool pop(Product &);
  void info();
};

#endif
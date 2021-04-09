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
  int count = 0;
  int totalAmount = 0;
  double profit = 0;
  bool push(Product);
  bool pop(Product &);
  void info();
};

#endif
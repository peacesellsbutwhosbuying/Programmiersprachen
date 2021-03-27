#ifndef STACK_H
#define STACK_H

#include <string>

struct Ball {
  std::string man;
  std::string sportType;
  std::string color;
  float size;
};

struct Stack {
  struct Node {
    Ball data;
    Node *prev;
  };
  Node *top = NULL;
  int count;
  bool push(Ball);
  bool pop(Ball &);
  void info();
};

#endif
#ifndef TREE_H
#define TREE_H
#include<string>

struct Flower
{
  std::string name;
  int amount;
  double price;
  bool isWild;
};

struct Tree
{
  Flower data;
  Tree* left;
  Tree* right;
};

int GetTreeSize(Tree*);
void Add(Tree**, int);
void PrintLeftRightRight(Tree*);
Tree* Search(Tree*&, int);
void Delete(Tree*&);

#endif
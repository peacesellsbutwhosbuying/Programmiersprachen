#ifndef TREE_H
#define TREE_H

struct Tree
{
  int data;
  Tree* left;
  Tree* right;
};

int GetTreeSize(Tree*);
void Add(Tree**, int);
void PrintLeftRightRight(Tree*);
Tree* Search(Tree*&, int);
void Delete(Tree*&);

#endif
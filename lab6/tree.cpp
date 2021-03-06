#include "tree.h"
#include <stddef.h>
#include <iostream>

int GetTreeSize(Tree* T)
{
  if(T == NULL)
  {
    return 0;
  }

  if(T->left == NULL && T->right == NULL)
  {
    return 1;
  }

  int left = 0;
  int right = 0;

  if(T->left)
  {
    left = GetTreeSize(T->left);
  }

  if(T->right)
  {
    right = GetTreeSize(T->right);
  }

  return left + right + 1;
}

void Add(Tree*& T, Flower* data)
{
  if(T == NULL)
  {
    T = new Tree;
    T->data = *data;
    T->left = NULL;
    T->right = NULL;
    return;
  }

  if(data->price < T->data.price)
  {
    Add(T->left, data);
    std::cout << "Left added" << std::endl;
  }
  else
  {
    Add(T->right, data);
    std::cout << "Right added" << std::endl;
  }
}

void PrintLeftRightRight(Tree* T)
{
  if(T == NULL)
  {
    return;
  }
  PrintLeftRightRight(T->left);
  std::cout << T->data.name << " " << T->data.amount << " " << T->data.price << T->data.isWild  << std::endl;
  PrintLeftRightRight(T->right);
}

Tree* Search(Tree*& T, Flower data)
{
  if(T == NULL)
  {
    return NULL;
  }

  while(T->data.price != data.price)
  {
    if(data.price < T->data.price)
    {
      T = T->left;
    }
    else
    {
      T = T->right;
    }

    if(T == NULL)
    {
      break;
    }
  }
  return T;
}

void Delete(Tree*& T)
{
  if(T)
  {
    if(T->left)
    {
      Delete(T->left);
    }
    
    if(T->right)
    {
      Delete(T->right);
    }

    delete T;
    T = NULL;
  }
  else
  {
    std::cout << "Tree is empty" << std::endl;
  }
}
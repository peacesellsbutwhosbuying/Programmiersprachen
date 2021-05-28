#include "tree.h"
#include "iostream"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  int n = 5;
  int mas[] = {2,5,3,4,1};
  Tree* T = NULL;
  for(int i = 0; i < n; i++) 
  {
    Add(&T, mas[i]);
  }
  PrintLeftRightRight(T);
  cout << endl;
  cout << "Tree size = " << GetTreeSize(T) << endl;
  return 0;
}

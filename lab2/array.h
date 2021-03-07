#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

double *createArray(int n) {
  double *x;
  x = new double [n];
  return x;
}

void printArray(double *&x, int &n) {
  for (int i{}; i < n; i++) {
    cout << "x" << i << " = " << x[i];
    cout << endl;
  }
  cout << endl;
}

void deleteArray(double *&x) {
  delete [] x;
}

void fillArray(double *&x, int &n) {
  for (int i{}; i < n; i++) {
    cout << "x" << i << " = ";
    cin >> x[i];
  }
}

#endif
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

double **createMatrix(int n, int m) {
  double **M;
  M = new double*[n];
  for (int i{}; i < n; i ++) {
    M[i] = new double [m];
  }
  return M;
}

void printMatrix(double **&M, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      cout << M[i][j] << "\t";
    }
    cout << endl << endl;
  }
  cout << endl;
}

void deleteMatrix(double **&M, int &n) {
  for (int i = 0; i<n; i++) {
    delete[]M[i];
  }
  delete[] M;
  M = NULL;
}

void fillMatrix(double **&M, int &n, int &m) {
  for (int i{}; i < n; i++) {
    for (int j{}; j < m; j ++) {
      cout << "A" << i + 1 << j + 1 << " = ";
      cin >> M[i][j];
    }
    cout << endl;
  }
  cout << endl << endl;
}

#endif
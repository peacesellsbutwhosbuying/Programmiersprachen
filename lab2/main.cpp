#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int **CreateMatrix(int, int);
void FillMAtrix(int **&, int &, int &);
void PrintMatrix(int **&, int &, int &);
void DelMatrix(int **&, int &);


int main() {
  int n = 3;
  int m = 3;
  int **matrix = CreateMatrix(n, m);
  FillMAtrix(matrix, n, m);
  PrintMatrix(matrix, n, m);
  DelMatrix(matrix, n);
  return 0;
}

int **CreateMatrix(int N, int M) {
  int **matrix;
  matrix = new int*[N];
  for (int i = 0; i<N; i++) {
    matrix[i] = new int [M];
  }
  return matrix;
}

void FillMAtrix(int **&matrix, int &n, int &m) {
  srand(time(0));
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      matrix[i][j] = rand()%10-2;
    }
  }
}

void PrintMatrix(int **&matrix, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl << endl;
  }
}

void DelMatrix(int **&matrix, int &n) {
  for (int i = 0; i<n; i++) {
    delete[]matrix[i];
  }
  delete[] matrix;
  matrix = NULL;
}
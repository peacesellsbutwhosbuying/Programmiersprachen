#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int GetN();
int **CreateMatrix(int, int);
double *CreateArray(int);

void FillMAtrixRandom(int **&, int &, int &);
void FillMatrix(int **&, int &, int &);
void FillTheEquation(int **&, double *&, int &, int &);

void PrintMatrix(int **&, int &, int &);
void PrintTheEquation(int **&,double *&, int &, int &);

void DelMatrix(int **&, int &);
void DelArray(double *&);

int Maxi(int **&, int &, int &, int);
void Permutation(int **&, int &n, int &m, int, int);
void Gaus(int **&, double *&, int &, int &);

int main() {
  int n, m;
  cout << "Enter number of lines";
  n = GetN();
  cout << "Enter number of columns";
  m = GetN();
  int **matrix = CreateMatrix(n, m);
  double *y = CreateArray(n);
  FillTheEquation(matrix,y, n, m);
  PrintTheEquation(matrix, y, n, m);
  DelArray(y);
  DelMatrix(matrix, n);
  return 0;
}

int GetN() {
  float n;

  do {
    cout << " --> ";
    cin >> n;
    if (n <= 0 || (n - (int)n)) {
      cout << "ERROR! Try again...";
    }
  } while(n <= 0 || (n - (int)n));

  return n;
}

double *CreateArray(int n) {
  double *y = new double[n];
  return y;
}

int **CreateMatrix(int N, int M) {
  int **matrix;
  matrix = new int*[N];
  for (int i = 0; i<N; i++) {
    matrix[i] = new int [M];
  }
  return matrix;
}

void FillMAtrixRandom(int **&matrix, int &n, int &m) {
  srand(time(0));
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      matrix[i][j] = rand()%10-2;
    }
  }
}

void FillMatrix(int **&matrix, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      cout <<  "A" << i + 1 << j + 1 << " = "; cin >> matrix[i][j];
      cout << endl; 
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

void PrintTheEquation(int **&matrix,double *&y, int &n, int &m) { 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << "*x" << j;
      if (j < m - 1)
        cout << " + ";
    }
    cout << " = " << y[i] << endl;
  }
}

void FillTheEquation(int **&matrix, double *&y, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      cout <<  "A" << i + 1 << j + 1 << " = "; cin >> matrix[i][j];
      cout << endl; 
    }
    cout << "B" << i + 1 << " = "; cin >> y[i];
  }
}

void DelMatrix(int **&matrix, int &n) {

  for (int i = 0; i<n; i++) {
    delete[]matrix[i];
  }
  delete[] matrix;
  matrix = NULL;
}

void DelArray(double *&y) {
  delete[] y;
  y = NULL;
}

int Maxi(int **&matrix, int &n, int&m, int k) {
  /*Эта функция находит индекс строки с максимальным элементом, внутри одного столбца*/
  int maxi = matrix[0][0], index{0};
   for (int i = 0; i < n; i++) {
     if ( matrix[i][k] > maxi) {
       maxi = matrix[i][k];
       index = i;
     }
   }
  return index;
}

void Permutation(int **&matrix, int &n, int &m, int k, int index) {
  double t;
  for (int i{0}; i < n; i++) {
    t = matrix[k][i];
    matrix[k][i] = matrix[index][i];
    matrix[index][i] = t;
  }
}

void Gaus(int **&a, double *&y, int &n, int &m) {
  int k{0};
  while(k < n) {
    int index = Maxi(a, n, m, k);
    Permutation(a, n, m, k, index);
    double t = y[k];
    y[k] = y[index];
    y[index] = t;
    //to be continued...
  }
}
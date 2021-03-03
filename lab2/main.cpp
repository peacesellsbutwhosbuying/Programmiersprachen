#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

int GetN();
double **CreateMatrix(int, int);
double *CreateArray(int);

void FillMAtrixRandom(double **&, int &, int &);
void FillMatrix(double **&, int &, int &);
void FillTheEquation(double **&, double *&, int &, int &);

void PrintMatrix(double **&, int &, int &);
void PrintTheEquation(double **&,double *&, int &, int &);
void PrintArr(double *&, int &);

void DelMatrix(double **&, int &);
void DelArray(double *&);

int Maxi(double **&, int &, int &, int);
void Permutation(double **&, int &, int &, int, int);
void Normize(double **&, double *&, int &, int &, int);
void Reverse(double **&, double *&, double *&, int &, int &, int);
void Gaus(double **&, double *&, int &, int &);


int main() {
  int n, m;
  cout << "Enter number of lines";
  n = GetN();
  cout << "Enter number of columns";
  m = GetN();
  double **matrix = CreateMatrix(n, m);
  double *y = CreateArray(n);
  FillTheEquation(matrix,y, n, m);
  PrintTheEquation(matrix, y, n, m);
  Gaus(matrix, y, n, m);
  
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

double **CreateMatrix(int N, int M) {
  double **matrix;
  matrix = new double*[N];
  for (int i = 0; i<N; i++) {
    matrix[i] = new double [M];
  }
  return matrix;
}

void FillMAtrixRandom(double **&matrix, int &n, int &m) {
  srand(time(0));
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      matrix[i][j] = rand()%10-2;
    }
  }
}

void FillMatrix(double **&matrix, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      cout <<  "A" << i + 1 << j + 1 << " = "; cin >> matrix[i][j];
      cout << endl; 
    }
  }
}

void PrintMatrix(double **&matrix, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl << endl;
  }
}

void PrintTheEquation(double **&matrix,double *&y, int &n, int &m) { 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << "*x" << j;
      if (j < m - 1)
        cout << " + ";
    }
    cout << " = " << y[i] << endl;
  }
  cout << endl;
}

void PrintArr(double *&a, int &n) {
  for (int i{0}; i < n; i++) {
    cout << "x" << i << " = " << a[i] << endl;
  }
}

void FillTheEquation(double **&matrix, double *&y, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      cout <<  "A" << i + 1 << j + 1 << " = "; cin >> matrix[i][j];
      cout << endl; 
    }
    cout << "B" << i + 1 << " = "; cin >> y[i]; cout << endl;
  }
}

void DelMatrix(double **&matrix, int &n) {

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

int Maxi(double **&matrix, int &n, int&m, int k) {
  /*Эта функция находит индекс строки с максимальным элементом, внутри одного столбца*/
  double maxi = matrix[k][k]; int index{k};
   for (int i = k; i < n; i++) {
     if ( matrix[i][k] > maxi) {
       maxi = matrix[i][k];
       index = i;
     }
   }
   //cout << "maxi = " << maxi << endl;
   //cout << "index = " << index << endl;
  return index;
}

void Permutation(double **&matrix, int &n, int &m, int k, int index) {
   
  double t;
  for (int i{0}; i < n; i++) {
    t = matrix[k][i];
    matrix[k][i] = matrix[index][i];
    matrix[index][i] = t;
  }
  
}

void Normize(double **&a, double *&y, int &n, int &m, int k) {

  for (int i = k; i<n; i++) {
    double t = a[i][k];
    if (fabs(t) < 0.00001) continue;
    for (int j{0}; j < m; j++) {
      a[i][j] = a[i][j] / t ;
    }
    y[i] = y[i] / t;
    if (i == k) continue;
    for (int j{0}; j < m; j++) {
      a[i][j] -= a[k][j];
    }
    y[i] -= y[k];
  }
}

void Reverse(double **&a, double *&y, double *&x, int &n, int &m, int k) {
  for (k = m - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  
}

void Gaus(double **&a, double *&y, int &n, int &m) {
  int k{0};
  int index;
  double t;
  while(k < n) {
    //Находим строку с максимальным элементом в текущем столбце
    index = Maxi(a, n, m, k);
    // Совершаем перестановку строк
    Permutation(a, n, m, k, index);
    // Отдельная перестановка y;
    t = y[k];
    y[k] = y[index];
    y[index] = t;
    // Норируем ур-е
    Normize(a, y, n, m, k);
    k++;
  }
  double *x = CreateArray(m);
  Reverse(a, y, x, n, m, k);
  PrintArr(x, m);
  DelArray(x);
  
}
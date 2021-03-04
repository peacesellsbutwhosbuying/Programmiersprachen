#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

void menu();
void task1();
void task2();
void task3();

int GetN();
double **CreateMatrix(int, int);
double *CreateArray(int);

void FillMAtrixRandom(double **&, int &, int &);
void FillMatrix(double **&, int &, int &);
void FillTheEquation(double **&, double *&, int &, int &);
void FillTheEquationRandom(double **&, double *&, int &, int &);
void fillIdentityMatrix(double **&, int &, int &);
void fillIdentityEq(double **&, double *&, int &, int &);

void PrintMatrix(double **&, int &, int &);
void PrintTheEquation(double **&,double *&, int &, int &);
void PrintArr(double *&, int &);

void DelMatrix(double **&, int &);
void DelArray(double *&);

int Maxi(double **&, int &, int &, int);
void Permutation(double **&, int &, int &, int, int);
void NormizeEq(double **&, double *&, int &, int &, int);
void Normize(double **&, int &, int&);
void Reverse(double **&, double *&, double *&, int &, int &, int);
void Gauss(double **&, double *&, int &, int &);
void Determenant(double **&, int &, int &);


int main() {
  int n, m;
  cout << "Enter number of lines";
  n = GetN();
  cout << "Enter number of columns";
  m = GetN();
  double **matrix = CreateMatrix(n, m);
  double *y = CreateArray(n);
  FillMatrix(matrix, n, m);
  PrintMatrix(matrix, n, m);
  Determenant(matrix, n, m);
  DelMatrix(matrix, n);
  DelArray(y);
  //menu();
  return 0;
}

void menu() {
    int key;  

    do {
        cout << " ---------------- " <<endl;
        cout << " 1 - Gauss Method" << endl;
        cout << " 2 - Determinant" << endl;
        cout << " 3 - Inverse matrix" << endl;
        cout << " 0 - Escape" << endl;
        cout << " ---------------- " << endl;

        cin >> key;

        switch (key)
        {
            case 1: task1();  break;
            //case 2: task2();  break;
            //case 3: task3();  break;
        case 0:cout << "'ll see ya" << endl; return;
        default:cout << "!!!Error, try again... " << endl; break;
        }
    } while (key);
    
  
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

void fillIdentityMatrix(double **&a, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      if (i == j) {
        a[i][j] = 1;
      } else {
        a [i][j] = 0;
      }
    }
  }
}

void fillIdentityEq(double **&a, double *&y, int &n, int &m) {
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      if (i == j) {
        a[i][j] = 1;
      } else {
        a [i][j] = 0;
      }
    }
    y[i] = 0;
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

void FillTheEquationRandom(double **&matrix, double *&y, int &n, int &m) {
  srand(time(0));
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      matrix[i][j] = rand()%10-2;
       
    }
     y[i] = rand()%10-2;
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

void NormizeEq(double **&a, double *&y, int &n, int &m, int k) {

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

void Normize(double **&a, int &n, int&m, int k) {
  for (int i = k; i<n; i++) {
    double t = a[i][k];
    if (fabs(t) < 0.00001) continue;
    for (int j{0}; j < m; j++) {
      a[i][j] = a[i][j] / t ;
    }
    if (i == k) continue;
    for (int j{0}; j < m; j++) {
      a[i][j] -= a[k][j];
    }
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

void Gauss(double **&a, double *&y, int &n, int &m) {
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
    NormizeEq(a, y, n, m, k);
    k++;
  }
  double *x = CreateArray(m);
  Reverse(a, y, x, n, m, k);
  PrintArr(x, m);
  DelArray(x);
  
}

void Determenant(double **&a, int &n, int &m) {
  int k{0};
  int index;
  double t;
  while(k < n) {
    //Находим строку с максимальным элементом в текущем столбце
    index = Maxi(a, n, m, k);
    // Совершаем перестановку строк
    Permutation(a, n, m, k, index);
    // Отдельная перестановка y;
    // Норируем ур-е
    Normize(a, n, m, k);
    k++;
  }
  PrintMatrix(a, n, m);
  double Det = 1;
  for (int i{0}; i < n; i++) {
    for (int j{0}; j < m; j ++) {
      if (i == j) { 
        Det *= a[i][j];
      }
    }
  }
  cout << "Determenant = " << Det << endl;
}

void task1() {
  int key;  

    do {
        cout << " ---------------- " <<endl;
        cout << " 1 - Enter matrix" << endl;
        cout << " 2 - Test matrix" << endl;
        cout << " 3 - Random matrix" << endl;
        cout << " 4 - Identity matrix" << endl;
        cout << " 5 - ..." << endl;
        cout << " 6 - Hilbert's matrix" << endl;
        cout << " 0 - Escape" << endl;
        cout << " ---------------- " << endl;

        cin >> key;

        switch (key)
        {
            case 1:{
              int n, m;
              cout << "Enter number of lines";
              n = GetN();
              cout << "Enter number of columns";
              m = GetN();
              double **matrix = CreateMatrix(n, m);
              double *y = CreateArray(n);
              FillTheEquation(matrix,y, n, m);
              PrintTheEquation(matrix, y, n, m);
              Gauss(matrix, y, n, m);
              DelArray(y);
              DelMatrix(matrix, n);
            } ;  break;

            case 2: cout << "dev" << endl;  break;

            case 3:{
              int n, m;
              cout << "Enter number of lines";
              n = GetN();
              cout << "Enter number of columns";
              m = GetN();
              double **matrix = CreateMatrix(n, m);
              double *y = CreateArray(n);
              FillTheEquationRandom(matrix,y, n, m);
              PrintTheEquation(matrix, y, n, m);
              Gauss(matrix, y, n, m);
              DelArray(y);
              DelMatrix(matrix, n);
            };  break;

            case 4: {
              int n, m;
              cout << "Enter number of lines";
              n = GetN();
              cout << "Enter number of columns";
              m = GetN();
              double **matrix = CreateMatrix(n, m);
              double *y = CreateArray(n);
              fillIdentityEq(matrix,y, n, m);
              PrintTheEquation(matrix, y, n, m);
              Gauss(matrix, y, n, m);
              DelArray(y);
              DelMatrix(matrix, n);
            } ;  break;

            case 5: cout << "dev" ;  break;
            case 6: cout << "dev" ;  break;
        case 0:cout << "'ll see ya" << endl; return;
        default:cout << "!!!Error, try again... " << endl; break;
        }
    } while (key);
}
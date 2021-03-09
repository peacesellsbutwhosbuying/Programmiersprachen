/*includings*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <math.h>

using namespace std;

/*functions*/
double **createMatrix(int , int );
void printMatrix(double **&, int &, int &);
void deleteMatrix(double **&, int &);
void fillMatrix(double **&, int &, int &);
double **copyMatrix(double **&, int &, int &);
double *createArray(int );
void printArray(double *&, int &);
void deleteArray(double *&);
void fillArray(double *&, int &);
int getNum();
void permutation(double **&, int &, int &, int);
bool triangularMatrix(double **&, int &, int &);
bool solutionCreation(double **&, double *&, int &, int &);
void testMenu(double **&, int &, int &);
double determinant(double **&, int &, int &, double);
bool inverseMatrix(double **&, double **&,  int &, int &, double &det);
void selectTask();

int main() {
  selectTask();
}

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

double **copyMatrix(double **&M, int &n, int &m) {
  double **A = createMatrix(n, m);
  for (int i{}; i < n; i++) {
    for (int j{}; j < m; j++) {
      A[i][j] = M[i][j];
    }
  }
  return A;
}

int getNum() {
  float n;

  do {
    cout << " ---> "; 
    cin >> n;
    if (n <= 0 || (n - (int)n)) {
      cout << "ERROR! Please, try again...";
      cout << endl;
    }
  } while (n <= 0 || (n - (int)n));
  
  return n;
}

void permutation(double **&M, int &n, int &m, int k) {
  for (int i{k+1}; i < n; i++) {
    if (M[i][k] != 0) {
      for (int j{}; j < m; j++) {
        double t = M[k][j];
        M[k][j] = M[i][j];
        M[i][j] = t;
      }
      
      break;
    }
  }  
}

bool triangularMatrix(double **&M, int &n, int &m) {
  for (int i{}; i < n; i++) {
    if (M[i][i] == 0) {
      permutation(M, n, m, i);
    }
    if (M[i][i] == 0) {
      return false;
    }
    double K;
    for (int k = 0; k < n; k++) {
      for (int i = k + 1; i < n; i++) {
        K = -1. * M[i][k] / M[k][k];
        for (int j = k; j < n+1; j++) {
          M[i][j] = M[i][j] + M[k][j] * K;
        }
      }
    }
  }
  printMatrix(M, n, m);
  
  return true;
}

bool solutionCreation(double **&M, double *&x, int &n, int &m) {
  double result = 0;
  if (!triangularMatrix(M, n, m)) return false;
  for(int i = n - 1; i >= 0; i--)
  {
    result = 0;
    for(int j = i + 1; j <= n - 1; j++)
      result = result - x[j] * M[i][j];
    result += M[i][n];
    x[i] = result / M[i][i];
  }
  return true;
}

void testMenu(double **&M, int &n, int &m){
  int key;
  
    cout << "\t\t\t" << 
    "---TEST_MENU---" << 
    endl << endl;
    cout << " ---------------- " <<endl;
    cout << " 1 - Test matrix" << endl;
    cout << " 2 - Random matrix" << endl;
    cout << " 3 - Identity matrix" << endl;
    cout << " 4 - Null matrix" << endl;
    cout << " 5 - Hilbert matrix" << endl;
    cout << " 6 - Enter matrix" << endl;
    cout << " 0 - Escape" << endl;
    cout << " ---------------- " << endl;
  
    cin >> key;
    cout << endl;
    switch(key) {
      case 1: {
        ifstream data ("data");

        for (int i{}; i < n; i++) {
          for (int j{}; j < m; j++) {
            data >> M[i][j];
          }
        }
        data.close();
        break;
      }
    
      case 2: {
        double a,b;
        srand(time(0));
        a = -10;
        b = 10;
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < m; j++) {
            M[i][j] = a + ((double) rand() / RAND_MAX) * (b - a);
          }
        }
        break;
      }

      case 3: {
        srand(time(0));
        for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++)
            if (j == m - 1) {
              M[i][j] = rand()%10-2;
            }
            else{
              if (i == j) {
                M[i][j] = 1;
              }
              else {
                M[i][j] = 0;
              }
            }
        break;
      }

      case 4: {
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < m; j++) {
            M[i][j] = 0;
          }
        }
        break;
      }

      case 5: {
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < m; j++) {
            M[i][j] = 1. / (i + j + 1);
          }
        }
        break;
      }

      case 6 :{
        fillMatrix(M, n, m);
        break;
      }

      case 0: {
        cout << "Testing completed" << endl;
        return;
      }
      default : cout << "Error... Try again." << endl;

    }
}

double determinant(double **&M, int &n, int &m, double det) {
  for(int i = 0; i < n; i++) {
    if (M[i][i] == 0) {
      return 0;
    }
    det *= M[i][i] ;
  }
  return det;
}

bool inverseMatrix(double **&M, double **&R, int &n, int &m) {
  
  double *x = new double [n];
  for(int i{}; i < n; i++)
  {
    double **C = copyMatrix(M, n, m);
    for(int j = 0; j < n; j++)
    {
      if (i == j) C[j][m - 1] = 1;
      else C[j][m - 1] = 0;
    }
    if (!solutionCreation(C, x, n, m)) {
      return false;
    }
    for(int j = 0; j < n; j++)
      R[j][i] = x[j];
    deleteMatrix(C, n);
  }
  delete [] x;
  x = NULL;
  return true;
}

void selectTask() {
  int key; 

    do {
        cout << " ---------------- " <<endl;
        cout << " 1 - Equation solution" << endl;
        cout << " 2 - Determinant" << endl;
        cout << " 3 - Inverse matrix" << endl;
        cout << " 0 - Escape" << endl;
        cout << " ---------------- " << endl;

        cin >> key;

        switch (key)
        {
            case 1: {
              cout << "Enter matrix size";
              int n;
              n = getNum();
              int m;
              m = n + 1;
              double **M = createMatrix(n, m);
              double *x = createArray(n);
              testMenu(M, n, m);
              printMatrix(M, n, m);
              if (solutionCreation(M, x, n, m)) {
                cout << "\t\tSolution:" << endl;
                printArray(x, n);
              } 
              else {
                cout << "No solution!" << endl;
              }
              deleteArray(x);
              deleteMatrix(M, n);
              break;
            }

            case 2: {
              cout << "Enter matrix size";
              int n;
              n = getNum();
              int m;
              m = n + 1;
              double det{1};
              double **M = createMatrix(n, m);

              double *x = createArray(n);
              testMenu(M, n, m);
              printMatrix(M, n, m);

              solutionCreation(M, x, n, m);
              
              det = determinant(M, n, m, det);
              cout << "DETERMINANT = " << det << endl;
              
              deleteArray(x);
              deleteMatrix(M, n);
              break;
            }
            case 3: {
              cout << "Enter matrix size";
              int n;
              n = getNum();
              int m;
              m = n + 1;
              double det{1};

              double **M = createMatrix(n, m);
              double *x = createArray(n);
              testMenu(M, n, m);

              double **A = copyMatrix(M, n, m);

              solutionCreation(M, x, n, m);

              double **I = createMatrix(n, n);
              if (determinant(M, n, m, det) != 0) {
                if (inverseMatrix(A, I, n, m)) {
                  cout << "Inverse matrix:" << endl;
                  printMatrix(I, n, n);
                }
                else {
                  cout << "No inverse matrix" << endl;
                }
              }
              else {
                cout << "No inverse matrix" << endl;
              }

              deleteArray(x);
              deleteMatrix(I, n);
              deleteMatrix(A, n);
              deleteMatrix(M, n);
              break;
            }
        case 0:cout << "'ll see ya" << endl; return;
        default:cout << "!!!Error, try again... " << endl; break;
        }
    } while (key);
    
  
}
/*includings*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <math.h>
#include "array.h"
#include "matrix.h"


using namespace std;

/*functions*/
int getNum();
void permutation(double **&M, int &n, int &m, int k, double &);
bool currentMinorMethod(double **&, int &, int &, double &);
bool solutionCreation(double **&, double *&, int &, int &, double &);
void testMenu(double **&, int &, int &);
double determinant(double **&, int &, int &, double);
bool inverseMatrix(double **&, double **&,  int &, int &, double &det);
void selectTask();

int main() {
  selectTask();
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

void permutation(double **&M, int &n, int &m, int k, double &det) {
  for (int i{k+1}; i < n; i++) {
    if (M[i][k] != 0) {
      for (int j{}; j < m; j++) {
        double t = M[k][j];
        M[k][j] = M[i][j];
        M[i][j] = t;
      }
      det *= -1;
      break;
    }
  }  
}

bool currentMinorMethod(double **&M, int &n, int &m, double &det) {
  for (int i{}; i < n; i++) {
    if (M[i][i] == 0) {
      permutation(M, n, m, i, det);
    }
    if (M[i][i] == 0) {
      return false;
    }
    for (int j{i+1}; j < n; j++) {
      for (int z{i+1}; z < m; z++) {
        M[j][z] = M[i][i] * M[j][z] - M[j][i] * M[i][z];
      }
    }
    for (int j{i + 1}; j < n; j++) {
      M[j][i] = 0;
    }
  }
  
  return true;
}

bool solutionCreation(double **&M, double *&x, int &n, int &m, double &det) {
  double result = 0;
  if (!currentMinorMethod(M, n, m, det)) return false;
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
    det *= M[i][i] / pow(M[i][i], n - i - 1);
    cout << M[i][i] << " / " << pow(M[i][i], n - 1 -i) << endl;
    cout << n - 1 - i << endl;
  }
  return det;
}

bool inverseMatrix(double **&M, double **&R, int &n, int &m, double &det) {
  
  double *x = new double [n];
  for(int i{}; i < n; i++)
  {
    double **C = copyMatrix(M, n, m);
    for(int j = 0; j < n; j++)
    {
      if (i == j) C[j][m - 1] = 1;
      else C[j][m - 1] = 0;
    }
    if (!solutionCreation(C, x, n, m, det)) {
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
              double det{1};
              double **M = createMatrix(n, m);
              double *x = createArray(n);
              testMenu(M, n, m);
              printMatrix(M, n, m);
              if (solutionCreation(M, x, n, m, det)) {
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

              solutionCreation(M, x, n, m, det);
              
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

              solutionCreation(M, x, n, m, det);

              double **I = createMatrix(n, n);
              if (determinant(M, n, m, det) != 0) {
                if (inverseMatrix(A, I, n, m, det)) {
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
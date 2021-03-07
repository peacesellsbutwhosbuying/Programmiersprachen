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

int main() {
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
    printArray(x, n);
  } 
  else {
    cout << "U GAY" << endl;
  }
  printMatrix(M, n, m);
  
  det = determinant(M, n, m, det);
  cout << "DET = " << det << endl;

  deleteArray(x);
  deleteMatrix(M, n);
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
        for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++) {
            M[i][j] = a + ((double) rand() / RAND_MAX) * (b - a);
          }
        break;
      }

      case 3: {
        for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++)
            if (i == j) M[i][j] = 1;
            else M[i][j] = 0;
        break;
      }

      case 4: {
        for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++)
            M[i][j] = 0;
        break;
      }

      case 5: {
        for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++)
            M[i][j] = 1. / (i + j + 1);
        break;
      }

      case 6 :{
        fillMatrix(M, n, m);
        break;
      }

      case 0: {
        cout << "Testing completed" << endl;
        break;
      }
      default : cout << "Error... Try again." << endl;

    }
}

double determinant(double **&M, int &n, int &m, double det) {
  for(int i = 0; i < n; i++) {
    if (M[i][i] == 0) {
      return 0;
    }
    det *= M[i][i] / pow(M[i][i], n - 1 - i);
  }
  return det;
}
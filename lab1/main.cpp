#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#define RAND (rand()%20)+5
#define FLOAT_RAND  (rand()%1000+1)*0.1

using namespace std;

void Menu();
void TasksMenu();
void CreateFiles();
int Num();
double * CreateArr(int);
void FillArr(double *, int);
void PrintArr(double *, int);

void Task1_1(double *&, int &);
void Task1_2(double *&, int &);

void Task2_1(double *&, int &);
void Task2_2(double *&, int &);

void Task3_1(double *&, int &);
void Task3_2(double *&, int &);

void Task4(double *&, int &);

void Task5(double *&, int &);

void Task6(double *&, int &);

void Task7(double *&, int &);

void Task8_2(double *&, int &);




int main() {
  CreateFiles();
  
  Menu();
  return 0;
}

void Menu() {
    int key; 
    int n = Num();
    double *arr = CreateArr(n);
    FillArr(arr, n);
    PrintArr(arr, n); 

    do {
        cout << " ---------------- " <<endl;
        cout << " 1 - Task 1(random)" << endl;
        cout << " 2 - Task 1(enter)" << endl;
        cout << " 3 - Task 2(random)" << endl;
        cout << " 4 - Task 2(enter)" << endl;
        cout << " 5 - Task 3(random)" << endl;
        cout << " 6 - Task 3(enter)" << endl;
        cout << " 7 - Task 4" << endl;
        cout << " 8 - Task 5" << endl;
        cout << " 9 - Task 6" << endl;
        cout << " 10 - Task 7" << endl;
        cout << " 11 - Task 8" << endl;
        cout << " 0 - Escape" << endl;
        cout << " ---------------- " << endl;

        cin >> key;

        switch (key)
        {
            case 1: Task1_1(arr, n); break;
            case 2: Task1_2(arr, n); break;
            case 3: Task2_1(arr, n); break;
            case 4: Task2_2(arr, n); break;
            case 5: Task3_1(arr, n); break;
            case 6: Task3_2(arr, n); break;
            case 7: Task4(arr, n); break;
            case 8: Task5(arr, n); break;
            case 9: Task6(arr, n); break;
            case 10: Task7(arr, n); break;
            case 11: Task8_2(arr, n); break;
        case 0:cout << "'ll see ya" << endl; return;
        default:cout << "!!!Error, try again... " << endl; break;
        }
    } while (key);
    delete[] arr;
  
}

void CreateFiles() {
  // открытие файла для записи массива
  ofstream file ("arr.txt");
  srand(time(0));
  // кол-во элементов в массиве
  int elements = RAND;
  //int &s = elements;
  for (int i = 0; i<elements; i++) {
    
    file << FLOAT_RAND << " ";
  }
  file.close();

}

int Num() {
    ifstream file("arr.txt");
    int count = 0;
    double num;
    while(file >> num) {
        count++;
    }
    file.close();
    return count;
}

double * CreateArr(int n) {
  double *arr = new double[n];
  return arr;
}

void FillArr(double *arr, int n) {
  n = Num();
  ifstream file ("arr.txt");
  for (int i = 0; i < n; i++) {
    file >> arr[i];
  }
  file.close();
}

void PrintArr(double *arr, int n) {
  cout << "[ ";
  for (int i = 0; i < n; i++) {
    if (i != n-1) {
      cout << arr[i] << "; ";
    }
    else {
      cout<< arr[i] <<" ]" << endl;
    }
    
  }
}

void Task1_1(double *&arr, int &n) {
  
  double random = RAND;
  cout << "random number = " << random << endl;

  double *buff = new double[n+1];
  for (int i = 0; i < n; i++) {
    buff[i] = arr[i];
  }
  buff[n] = random;
  n++;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);
}

void Task1_2(double *&arr, int &n) {
  double k;
  cout<<"Enter numebr = ";cin>>k;cout<<endl;
  double *buff = new double[n+1];
  for (int i = 0; i < n; i++) {
    buff[i] = arr[i];
  }
  buff[n] = k;
  n++;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);
}

void Task2_1(double *&arr, int &n) {
  double random = RAND;
  cout << "random number = " << random << endl;

  double *buff = new double[n+1];
  buff[0] = random;
  for (int i = 0; i < n; i++) {
    buff[i+1] = arr[i];
  }
  n++;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);
}

void Task2_2(double *&arr, int &n) {
  double k;
  cout<<"Enter numebr = ";cin>>k;cout<<endl;

  double *buff = new double[n+1];
  buff[0] = k;
  for (int i = 0; i < n; i++) {
    buff[i+1] = arr[i];
  }
  n++;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);
}

void Task3_1(double *&arr, int &n) {
  double random = RAND;
  cout << "random number = " << random << endl;
  int k = rand()%n+1;
  cout<< "random index:" << k-1 << endl;

  double *buff = new double[n+1];
    for (int i = 0; i < k-1; i++) {
      buff[i] = arr[i];
    }
    buff[k-1] = random;
    for (int i = k;i < n+1; i++) {
      buff[i] = arr[i-1];
    }
    n++;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);
}

void Task3_2(double *&arr, int &n) {
  int k;
  cout << "Enter k --> ";cin>>k; cout << endl;
  if (k>0 && k<=n) {
    double *buff = new double[n+1];
    for (int i = 0; i < k-1; i++) {
      buff[i] = arr[i];
    }
    buff[k-1] = k;
    for (int i = k;i < n+1; i++) {
      buff[i] = arr[i-1];
    }
    n++;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);
  } else {
    cout<<"ERROR! try again..." << endl;
  }
  
}

void Task4(double *&arr, int &n) {

  double *buff = new double[n-1];
  for (int i = 0; i < n-1; i++) {
    buff[i] = arr[i];
  }
  n--;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);

}

void Task5(double *&arr, int &n) {

  double *buff = new double[n-1];
  for (int i = 1; i < n; i++){
    buff[i-1] = arr[i];
  }
  n--;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);
}

void Task6(double *&arr, int &n) {
  int k;
  cout << "Enter k --> ";cin>>k; cout << endl;
  if (k>0 && k<=n) {
    double *buff = new double[n-1];
    for(int i = 0; i < k-1; i++) {
      buff[i] = arr[i];
    }
    for (int i = k; i < n; i++) {
      buff[i-1] = arr[i];
    }
    n--;
    delete[] arr;
    arr = buff;
    PrintArr(arr, n);
  } else {
    cout << "ERROR! Try again..." << endl;
  }
  
}

void Task7(double *&arr, int &n) {

  double num;
  cout << "Enter number --> ";cin>>num; cout << endl;
  double k;
  cout << "Enter k --> ";cin>>k; cout << endl;
  bool ind = true;
  int count = 0;

  for (int i = 0; i < n && ind != false; i++) {
    count ++;
    if (arr[i] == num) {
      ind = false;
    }
  }
  if (count >= 1) {
    double *buff = new double[n+1];
    for (int i = 0; i < count; i++) {
      buff[i] = arr[i];
    }
    buff[count] = k;
    for (int i = count + 1; i < n+1; i++) {
      buff[i] = arr[i-1];
    }
    n++;
    delete[] arr;
    arr = buff;
    PrintArr(arr, n);
  } else {
    cout << "ERROR! There's no such element in the array..." << endl;
  }
}

void Task8_2(double *&arr, int &n) {
  double el;
  cout << "Enter element ---> "; cin >> el; cout << endl;
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] == el) {
      count++;
    }
  }
  cout<<"count = " << count << endl;

  double *buff = new double[n-count];
  int kf = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != el) {
      buff[i-kf] = arr[i];
      
    } else {
      kf++;
    }
  }
  n-=count;
  delete[] arr;
  arr = buff;
  PrintArr(arr, n);

}
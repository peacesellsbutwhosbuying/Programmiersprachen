#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include<limits.h>
#include<stack>

using std::cout;
using std::cin;
using std::endl;


int **ReadFile(int&);
int FindMinDistance(int, int*, bool*);
void Dijkstra(int, int**, int, int);
void Path(int, int**, int, int, int *);

int main()
{
  int graphSize = 0;
  int **M = ReadFile(graphSize);

  //print
  for(int i{}; i < graphSize; i++)
  {
    for(int j{}; j < graphSize; j++)
    {
      cout << std::setw(8) << M[i][j];
    }
    cout << endl;
  }

  int source, dest;
  cout << "Enter start point --> "; cin >> source; cout << endl;
  cout << "Enter end point --> "; cin >> dest; cout << endl;

  Dijkstra(graphSize, M, source, dest);

  //delete
  for (int i{}; i < graphSize; i++) 
  {
    delete[] M[i];
  }
  delete[] M;
   
  return 0;
}

int **ReadFile(int & graphSize)
{
  std::ifstream input("data");
  if (!input.is_open())
  {
    cout << "Error! Couldn't read the file" << endl;
    exit(1);
  } 

  std::ifstream data("data");

  int count{};
  int temp{};
  while(data >> temp)
  {
    count++;
  }
  data.close();

  graphSize = sqrt(count);

  int** M;
  M = new int*[graphSize];
  for(int i{}; i < graphSize; i++)
  {
    M[i] = new int[graphSize];
  }

  for(int i{}; i < graphSize; i++)
  {
    for(int j{}; j < graphSize; j++)
    {
      input >> M[i][j];
    }
  }
  input.close();

  return M;
}

int FindMinDistance(int grapSize, int* dist, bool* visited)
{
  int min = INT_MAX;
  int minIndex;

  for (int i{}; i < grapSize; i++) 
  {
    if (visited[i] == false && dist[i] <= min) 
    {
      min = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void Dijkstra(int graphSize, int **G, int source, int dest) {
  int *dist = new int[graphSize];
  bool *visited = new bool[graphSize];

  for (int i{}; i < graphSize; i++) {
    dist[i] = INT_MAX;
    visited[i] = false;
  }
  dist[source] = 0;

  for (int i{}; i < graphSize - 1; i++) 
  {
    int u = FindMinDistance(graphSize, dist, visited);
    visited[u] = true;

    for (int v{}; v < graphSize; v++) 
    {
      if (!visited[v] && G[u][v] && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v]) 
      {
        dist[v] = dist[u] + G[u][v];
      }
    }
  }

  cout << "Vertex \t\t Distance from source " << endl;
  for (int i{}; i < graphSize; i++)
  {
    cout << i << " \t\t " << dist[i] << endl;
  }

  Path(graphSize, G, source, dest, dist);

  delete[] dist;
  delete[] visited;
}

void Path(int graphSize, int** M, int source, int dest, int *dist) 
{
  std::stack<int> path;
  path.push(dest);

  int w = dist[dest];
  while (dest != source) 
  {
    for (int i{}; i < graphSize; i++) 
    {
      if (M[i][dest] != 0) 
      {
        int temp = w - M[i][dest];
          if (temp == dist[i]) 
          {
            w = temp;
            dest = i;
            path.push(i);
          }
      }
    }
  }

  cout << "Path: ";
  while(!path.empty()) 
  {
    cout << path.top();
    path.pop();
  }
  cout << endl;
}
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

typedef struct func{
  vector<int> edges;
}func;

vector<func> list_functions;
int n_functions;

// we use floyd warshall because it gives the shortest path between two points in any graph
void floyd_warshall(){
  int i, j, k;
  int matrix[n_functions+1][n_functions+1];

  // necessary?
  for(i = 0; i < n_functions; i++){
    for(j = 0; j < n_functions; j++){
      matrix[i][j] = 0;
    }
  }

  for(i = 0; i < n_functions; i++){
    for(j = 0; j < n_functions; j++){
      if(list_functions[i].edges[j] != -1){
        matrix[i][j] = 1;
      } else {
        matrix[i][j] = 0;
      }
    }
  }

  for(k = 0; k < n_functions; k++){
    for(i = 0; i < n_functions; i++){
      for(j = 0; j < n_functions; j++){
        if(matrix[i][k] == 1 && matrix[k][j] == 1){
          matrix[i][j] = 1;
        }
      }
    }
  }

  for(i = 0; i < n_functions; i++){
    if(matrix[i][i]){
      printf("%d\n", i);
    }
  }
}

int main() {
  int i, j, k;
  int a, b;

  scanf("%d", &n_functions);

  for(i = 0; i < n_functions; i++){
    func f;
    for(k = 0; k < n_functions; k++){
      f.edges.push_back(-1);
    }
    scanf("%d", &a);
    for(j = 0; j < a; j++){
      scanf("%d", &b);
      f.edges[b] = b;
    }
    list_functions.push_back(f);
  }

  floyd_warshall();
  return 0;
}

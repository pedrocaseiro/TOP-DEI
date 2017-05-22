#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

typedef struct node{
  vector<int> edges;
}node;

int n_bolts;
vector<node> nodes;

// we use floyd warshall because it gives the shortest path between two points in any graph
// we use floyd warshall because it gives the shortest path between two points in any graph
void floyd_warshall(){
  int i, j, k;
  long int matrix[n_bolts+1][n_bolts+1];

  // necessary?
  for(i = 0; i < n_bolts; i++){
    for(j = 0; j < n_bolts; j++){
      matrix[i][j] = 0;
    }
  }

  for(i = 0; i < n_bolts; i++){
    for(j = 0; j < n_bolts; j++){
      if(nodes[i].edges[j] != -1){
        matrix[i][j] += 1;
      } else {
        matrix[i][j] = INT_MAX;
      }
    }
  }

  for(k = 0; k < n_bolts; k++){
    for(i = 0; i < n_bolts; i++){
      for(j = 0; j < n_bolts; j++){
        if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
          matrix[i][j] = matrix[i][k] + matrix[k][j];
        }
      }
    }
  }

  //for(i = 0; i < n_bolts; i++){
    //for(j = 0; j < n_bolts; j++){
      //printf("%lu\t", matrix[i][j]);
    //}
    //printf("\n");
  //}
  vector<int> values;
  for(i = 0; i < n_bolts; i++){
    values.push_back(-1);
  }

  int maximum = 0;
  int minimum = INT_MAX;
  for(i = 0; i < n_bolts; i++){
    for(j = 0; j < n_bolts; j++){
      if(matrix[i][j] > values[i]){
        maximum = max(maximum, (int)matrix[i][j]);
        values[i] = matrix[i][j];
      }     
    }
    minimum = min(minimum, values[i]);
  }
  printf("Shortest:");
  for(i = 0; i < n_bolts; i++){
    if(values[i] == minimum){
      printf(" %d", i+1);
    }
  }
  printf("\n");
  printf("Tallest:");
  for(i = 0; i < n_bolts; i++){
    if(values[i] == maximum){
      printf(" %d", i+1);
    }
  }
  printf("\n");
}

int main() {
  int i, j;
  int a, b;

  scanf("%d", &n_bolts);

  for(i = 0; i < n_bolts; i++){
    node n;
    for(j = 0; j < n_bolts; j++){
      n.edges.push_back(-1);
    }
    nodes.push_back(n);
  }
  for(i = 0; i < n_bolts - 1; i++){
    scanf("%d %d", &a, &b);
    nodes[a-1].edges[b-1] = b;
    nodes[b-1].edges[a-1] = a;
  }
  floyd_warshall();
  return 0;
}

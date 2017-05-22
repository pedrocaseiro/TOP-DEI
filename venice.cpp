#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

typedef struct node{
  vector<int> edges;
  int used;
}node;
vector<node> nodes_first;
vector<node> nodes_second;

int n_connections;

// we use floyd warshall because it gives the shortest path between two points in any graph
void floyd_warshall(){
  int i, j, k;
  int matrix_a[27][27];
  int matrix_b[27][27];

  // necessary?
  for(i = 0; i < 27; i++){
    for(j = 0; j < 27; j++){
      matrix_a[i][j] = 0;
      matrix_b[i][j] = 0;
    }
  }

  for(i = 0; i < 26; i++){
    for(j = 0; j < 26; j++){
      if(nodes_first[i].edges[j] != -1){
        matrix_a[i][j] = 1;
      } else {
        matrix_a[i][j] = 0;
      }
      if(nodes_second[i].edges[j] != -1){
        matrix_b[i][j] = 1;
      } else {
        matrix_b[i][j] = 0;
      }

    }
  }

  int equal_flag = 0;
  for(k = 0; k < 26; k++){
    for(i = 0; i < 26; i++){
      for(j = 0; j < 26; j++){
        if(matrix_a[i][k] == 1 && matrix_a[k][j] == 1){
          matrix_a[i][j] = 1;
        }
        if(matrix_b[i][k] == 1 && matrix_b[k][j] == 1){
          matrix_b[i][j] = 1;
        }
      }
    }
  }
  for(i = 0; i < 26; i++){
    for(j = 0; j < 26; j++){
      if(matrix_a[i][j] != matrix_b[i][j]){
        equal_flag = 1;
        break;
      }
    }
    if(equal_flag) break;
  }

  if(!equal_flag) printf("YES\n"); else printf("NO\n");
}

int main() {
  int i, j, k;
  char a, b;
  int n_cases;

    scanf("%d\n", &n_cases);
  for(i = 0; i < n_cases; i++){
    nodes_first.clear();
    nodes_second.clear();
    for(k = 0; k < 26; k++){
      node n;
      node n2;
      for(j = 0; j < 26; j++){
        n.edges.push_back(-1);
        n2.edges.push_back(-1);
      }
      nodes_first.push_back(n);
      nodes_second.push_back(n2);
    }

    if(i > 0) printf("\n");
    scanf("\n%d\n", &n_connections);
    for(j = 0; j < n_connections; j++){
      scanf("\n%c %c", &a, &b);
      nodes_first[a-65].edges[b-65] = 1;
    }
    scanf("%d", &n_connections);
    for(j = 0; j < n_connections; j++){
      scanf("\n%c %c", &a, &b);
      nodes_second[a-65].edges[b-65] = 1;
    }

    floyd_warshall();
  }
  

  return 0;
}

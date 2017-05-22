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

int n_functions, n_calls;
vetor<node> nodes;
int n_edges = 0;

int main() {
  scanf("%d", &n_functions);
  int i = 0;
  int j = 0;
  int a = 0;
  for(i = 0; i < n_functions; i++){
    node n; 
    scanf("%d", &n_calls);
    n_edges++;
    for(j = 0; j < n_calls; j++){
      scanf("%d", &a);
      n.edges.push_back(a);
    }
  }
  for(i = 0; i < n_edges; i++){
    dfs.push_back(-1);
  }
  return 0;
}


function FW(G):
  for(i = 1; i <  n_edges; i++){
    for(j = 1; j < n_edges; j++){
      for(k = 0; k < nodes[i].edges.size(); k++){
        if(nodes[i].edges[k] ==)
      }
        C[i][j] = true
      else
        C[i][j] = false
    }
  } 
    for k= 1 to |V|
  for i= 1 to |V|
  for j= 1 to |V|
  If C[i][k] = true and C[k][j] = true
   C[i][j] = true

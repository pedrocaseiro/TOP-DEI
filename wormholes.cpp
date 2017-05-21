#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

typedef struct star_system{
  int n;
  vector<int> edges;
  vector<int> weight;
}star_system;

vector<star_system> universe;
int n_cases, n_star_systems, n_wormholes;

void bellman(){
  vector<int> distances;
  int i, j, k;
 
  for(int i = 0; i < n_star_systems; i++){
    distances.push_back(INT_MAX);
  }

  distances[0] = 0;

  for(i = 0; i < n_star_systems - 1; i++){
    for(j = 0; j < n_star_systems; j++){
      for(k = 0; k < (int)universe[j].edges.size(); k++){
        int u = j;
        int v = universe[j].edges[k];
        int weight = universe[j].weight[k];
        if(distances[v] > distances[u] + weight){
          distances[v] = distances[u] + weight;
        }
      }
    }
  }

  for(j = 0; j < n_star_systems; j++){
    for(k = 0; k < (int)universe[j].edges.size(); k++){
      int u = j;
      int v = universe[j].edges[k];
      int weight = universe[j].weight[k];
      if(distances[v] > distances[u] + weight){
        printf("possible\n");
        return;
      }
    }
  } 
  printf("not possible\n");
  return;
}

int main() {
  int i, j;
  int a, b, c;

  scanf("%d", &n_cases);
  for(i = 0; i < n_cases; i++){
    universe.clear();
    scanf("%d %d", &n_star_systems, &n_wormholes);
    star_system aux;
    for(int k = 0; k < n_star_systems; k++){
      aux.n = k;
      universe.push_back(aux);
    }
    for(j = 0; j < n_wormholes; j++){
      scanf("%d %d %d", &a, &b, &c);
      universe[a].edges.push_back(b);
      universe[a].weight.push_back(c);
    }

    bellman();
  }





  return 0;
}

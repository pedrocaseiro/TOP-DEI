#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef struct node{
  vector<int> edges;
  int index;
}node;

vector<node> nodes;

vector<int> dfs;
vector<int> low;

int t = 0;
void articulation_points(int i){
  int j;
  low[i] = dfs[i] = t = t + 1;
  for(j = 0; j < nodes[i].edges.size(); j++){
    if(dfs[nodes[i].edges[j]] == -1){
      articulation_points(nodes[i].edges[j]);
      low[i] = min(low[i], low[nodes[i].edges[j]]);
      if(dfs[i] == 1 && dfs[nodes[i].edges[j]] != 2){
          printf("bridge11: %d %d\n", i, nodes[i].edges[j]);
        if(low[nodes[i].edges[j]] > dfs[i]){
          printf("bridge1: %d %d\n", i, nodes[i].edges[j]);
        }
      }
      if(dfs[i] != 1 && low[nodes[i].edges[j]] >= dfs[i]){
          printf("bridge22: %d %d\n", i, nodes[i].edges[j]);
        if(low[nodes[i].edges[j]] > dfs[i]){
          printf("bridge2: %d %d\n", i, nodes[i].edges[j]);
        }
      }
    } else if(find(nodes[nodes[i].edges[j]].edges.begin(), nodes[nodes[i].edges[j]].edges.end(), i) == nodes[nodes[i].edges[j]].edges.end()) {
      printf("LUL123\n");
      low[i] = min(low[i], dfs[nodes[i].edges[j]]);
    }
  }
}

int main() {
  int i;
  int n_nodes, n_roads, a, b;

  while(scanf("%d %d", &n_nodes, &n_roads) != EOF){
    nodes.clear();
    low.clear();
    dfs.clear();
    t = 0;
    for(i = 0; i < n_nodes; i++){
      node n;
      n.index = i;
      nodes.push_back(n);
      low.push_back(-1);
      dfs.push_back(-1);
    }
    for(i = 0; i < n_roads; i++){
      scanf("%d %d", &a, &b);
      nodes[a].edges.push_back(b);
    }
    //for(i = 0; i < nodes.size(); i++){
    articulation_points(0);
    //}
  } 


  return 0;
}

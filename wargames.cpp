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
  int j, k;
  int parent;
  low[i] = dfs[i] = t = t + 1;
  for(j = 0; j < nodes[i].edges.size(); j++){
    if(dfs[nodes[i].edges[j]] == -1){
      articulation_points(nodes[i].edges[j]);
      low[i] = min(low[i], low[nodes[i].edges[j]]);
      if(dfs[i] == 1 && dfs[nodes[i].edges[j]] != 2){
        if(low[nodes[i].edges[j]] > dfs[i]){
          printf("bridge1: %d %d\n", i, nodes[i].edges[j]);
        }
      }
      if(dfs[i] != 1 && low[nodes[i].edges[j]] >= dfs[i]){
        if(low[nodes[i].edges[j]] > dfs[i]){
          printf("bridge2: %d %d\n", i, nodes[i].edges[j]);
        }
      }
    } else {
      parent = 0;
      for(k = 0; k < (int)nodes[nodes[i].edges[j]].edges.size(); k++){
        if(nodes[nodes[i].edges[j]].edges[k] == i){
          parent = 1;

        }

      }
      if(parent == 0) low[i] = min(low[i], dfs[nodes[i].edges[j]]);
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
      nodes[b].edges.push_back(a);
    }
    //for(i = 0; i < nodes.size(); i++){
    articulation_points(0);
    //}
  } 


  return 0;
}

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
        printf("articulation\n");
      }
      if(dfs[i] != 1 && low[nodes[i].edges[j]] >= dfs[i]){
        printf("articulation");
      }
    } else if(find(nodes[nodes[i].edges[j]].edges.begin(), nodes[nodes[i].edges[j]].edges.end(), i) == nodes[nodes[i].edges[j]].edges.end()) {
      low[i] = min(low[i], dfs[nodes[i].edges[j]]);
    }
  }
}

int main() {
  int i, j;
  int n_nodes, id;
  int aux;
  char c;

  while(scanf("%d", &n_nodes)){
    if(n_nodes == 0){
      break;
    } else {
      dfs.clear();
      low.clear();
      t = 0;
      nodes.clear();
      for(i = 0; i < n_nodes; i++){
        node n;
        nodes.push_back(n);
        low.push_back(-1);
        dfs.push_back(-1);
      }
      for(i = 0; i < n_nodes; i++){
        scanf("%d", &id);
        if(id == 0){
          break;
        } else {
          for(j = 0; j < n_nodes; i++){
            if(scanf("%d", &aux) == 1){
              nodes[id-1].edges.push_back(aux-1);
              scanf("%c", &c);
              if(c == '\n'){
                break;
              }
            }
          }
        }
      }
      articulation_points(id - 1);
    }
  } 
  return 0;
}

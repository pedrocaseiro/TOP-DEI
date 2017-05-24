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

int n_nodes;
vector<node> nodes;
int indio;
vector<int> dfs;
vector<int> low;

vector<int> stack;
vector<vector<int> > list;

void tarjanAlgorithm(int n){
  int i;
  dfs[n] = indio;
  low[n] = indio;
  indio++;
  stack.push_back(n);
  for(i = 0; i < (int)nodes[n].edges.size(); i++){
    if(dfs[nodes[n].edges[i]] == -1){
      tarjanAlgorithm(nodes[n].edges[i]);
      low[n] = min(low[n], low[nodes[n].edges[i]]);
    }else if(find(stack.begin(), stack.end(), nodes[n].edges[i]) != stack.end()){
      low[n] = min(low[n], dfs[nodes[n].edges[i]]);
    }
  }
  int w;
  vector<int> component;
  if(low[n] == dfs[n]){
    do{
      w = stack.back();
      stack.pop_back();
      component.push_back(w);
    }while(n != w);
    sort(component.begin(), component.end());
    list.push_back(component);
  }
}

void tarjan(){
  int i;
  for(i = (int) nodes.size() - 1; i >= 0; i--){
    if (dfs[i] == -1){
      tarjanAlgorithm(i);
    }
  } 
}
  
int main() {
  int i, id, a; 

  scanf("%d", &n_nodes);
  for(i = 0; i < n_nodes; i++){
    node n;
    nodes.push_back(n);
    dfs.push_back(-1);
    low.push_back(-1);
  }
  indio = 0;
  for(i = 0; i < n_nodes; i++){
    scanf("%d", &id);
    while(scanf("%d", &a) == 1){
      if(a != 0){
        nodes[id-1].edges.push_back(a-1);
      } else {
        break;
      }
    }
  }
  tarjan();
  for(i = 0; i < (int) list.size(); i++){
    printf("Stage %d:\n", i+1);
    for(a = 0; a < (int) list[i].size(); a++){
      printf("%d", list[i][a]+1);
      if(a + 1 < (int) list[i].size()) printf(" ");
    }
    printf("\n");
  }
  return 0;
}

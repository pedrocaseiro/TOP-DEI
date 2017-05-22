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
  vector<int> dependents;
}node;

int n_nodes;
vector<node> nodes;
vector<vector<int> > cycles;

void bdj(int n, vector<int> resolved, vector<int> unresolved){
  int i, j;

  unresolved.push_back(n);
  for(i = 0; i < (int)nodes[n].edges.size(); i++){
    if(find(resolved.begin(), resolved.end(), nodes[n].edges[i]) == resolved.end()){
      if(find(unresolved.begin(), unresolved.end(), nodes[n].edges[i]) != unresolved.end()){
        vector<int> cycle;
        j = (int)unresolved.size() - 1;
        while(j >= 0){
          cycle.push_back(unresolved[j]);
          if (unresolved[j] == nodes[n].edges[i]) break;
          j--;
        }
        sort(cycle.begin(), cycle.end());
        cycles.push_back(cycle);
        bdj(n, unresolved, resolved);
        break; 
      }
      bdj(nodes[n].edges[i], resolved, unresolved);
    }
  }
  resolved.push_back(n);
  unresolved.erase(find(unresolved.begin(), unresolved.end(), n));
}

int stage = 1;
vector<int> nodes_expanded;
vector<int> cycles_expanded;
void stages(int n){
  if (find(nodes_expanded.begin(), nodes_expanded.end(), n) != nodes_expanded.end()){
    return;
  }
  nodes_expanded.push_back(n);
  int i, j, k, l;
  int aux;
  int cycle_flag = 0;
  for (i = 0; i < (int) nodes[n].edges.size(); i++){
    cycle_flag = 0;
    aux = nodes[n].edges[i];
    for (j = 0; j < (int) cycles.size(); j++){
      if(find(cycles_expanded.begin(), cycles_expanded.end(), j) == cycles_expanded.end() && find(cycles[j].begin(), cycles[j].end(), aux) != cycles[i].end()){
        cycles_expanded.push_back(j);
        cycle_flag = 1;
        for(k = 0; k < (int) cycles[j].size(); k++){
          nodes_expanded.push_back(cycles[j][k]);
        }
        for(k = 0; k < (int) cycles[j].size(); k++){
          for (l = 0; l < (int) nodes[cycles[j][k]].edges.size(); l++){
            if(find(cycles[j].begin(), cycles[j].end(), nodes[cycles[j][k]].edges[l]) == cycles[j].end()){
              stages(nodes[cycles[j][k]].edges[l]);
            }
          }
        }
        printf("Stage %d:\n", stage);
        for(k = 0; k < (int) cycles[j].size(); k++){
          printf("%d", cycles[j][k]+1);
          if (k < (int) cycles[j].size()-1){
            printf(" ");
          }
        }
        printf("\n");
        stage++;
        break;
      }
    }
    if(!cycle_flag){
      stages(aux);
    }
  }
  cycle_flag = 0;
  for(i = 0; i < (int)cycles.size(); i++){
    if(find(cycles[i].begin(), cycles[i].end(), n) != cycles[i].end()){
      cycle_flag = 1;
      break;
    }
  }
  if(!cycle_flag){
    printf("Stage %d:\n", stage);
    printf("%d\n", n+1);
    stage++;
  }
}

int main() {
  int i, id, a; 
  vector<int> resolved;
  vector<int> unresolved;

  scanf("%d", &n_nodes);
  for(i = 0; i < n_nodes; i++){
    node n;
    nodes.push_back(n);
  }
  for(i = 0; i < n_nodes; i++){
    scanf("%d", &id);
    while(scanf("%d", &a) == 1){
      if(a != 0){
        nodes[id-1].edges.push_back(a-1);
        nodes[a-1].dependents.push_back(id-1);

      } else {
        break;
      }
    }
  }
  bdj(n_nodes - 1, resolved, unresolved);
  stages(n_nodes - 1);
  return 0;
}

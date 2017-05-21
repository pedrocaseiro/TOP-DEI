#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

struct {
  int color;
  int n_edges;
  int edges[30];

}typedef Node;

int n_persons, n_cases, a, b = 0;
int n_colors;

int inspetormax = 0;

int colors[30];
Node nodes[30];

bool gcp(int number){
  bool feasible;

  if(number == n_persons + 1){
    return true;
  }

  for(int i = 1; i <= n_colors; i++){ // cores
    feasible = true;
    int size_edges = nodes[number].n_edges;
    for(int j = 0; j < size_edges; j++){
      if(nodes[nodes[number].edges[j]].color == i){
        feasible = false;
        break;
      }
    }
    if(feasible == true){
      nodes[number].color = i;
      if(gcp(number+1)){
        return true;
      }
      nodes[number].color = 0;
    }
  }
  return false;
}

int binarySearch(int low, int high){
  n_colors = (low + high)/2;
  if (n_colors == low)
    return 1;
  if (gcp(0)){
    for(int l = 0; l < n_persons; l++){
      colors[nodes[l].color]++;
      int aux = colors[nodes[l].color];
      if(aux > inspetormax){
        inspetormax = aux;
      }
    }
    return binarySearch(low, n_colors);
  }
  else
    return binarySearch(n_colors + 1, high);
}

int main(){
  scanf("%d %d", &n_persons, &n_cases);
  for(int j = 0; j < n_persons; j++){
    Node node;
    node.color= 0;
    node.n_edges = 0;
    nodes[j] = node;
    colors[j] = 0;
  }
  for(int i = 0; i < n_cases; i++){
    scanf("%d %d", &a, &b);
    nodes[a].edges[nodes[a].n_edges] = b;
    nodes[a].n_edges++;
    nodes[b].edges[nodes[b].n_edges] = a;
    nodes[b].n_edges++;
  }
  binarySearch(1,n_persons);
  printf("%d\n", inspetormax);
  
  return 0;
}

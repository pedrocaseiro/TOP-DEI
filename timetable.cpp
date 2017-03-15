#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

struct {
  int color;
  //vector<int> edges;
  int n_edges;
  int edges[30];

}typedef Node;

int n_examinations, n_cases, a, b = 0;
int n_colors;

Node nodes[30];

bool gcp(int number){
  bool feasible;

  if(number == n_examinations + 1){
    return true;
  }

  for(int i = 1; i <= n_colors; i++){ // cores
    feasible = true;
    int size_edges = nodes[number].n_edges;
    for(int j = 0; j < size_edges; j++){
      if(nodes[nodes[number].edges[j]-1].color == i){
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
  if (gcp(0))
    return binarySearch(low, n_colors);
  else
    return binarySearch(n_colors + 1, high);
}

int main(){
  scanf("%d %d", &n_examinations, &n_cases);
  for(int j = 0; j < n_examinations; j++){
    Node node;
    node.color= 0;
    node.n_edges = 0;
    nodes[j] = node;
  }
  for(int i = 0; i < n_cases; i++){
    scanf("%d %d", &a, &b);
    nodes[a-1].edges[nodes[a-1].n_edges] = b;
    nodes[a-1].n_edges++;
    nodes[b-1].edges[nodes[b-1].n_edges] = a;
    nodes[b-1].n_edges++;
  }
  binarySearch(1,n_examinations);
  printf("%d\n", n_colors);
  return 0;
}

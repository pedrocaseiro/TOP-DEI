#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

struct {
  int color;
  vector<int> edges;
}typedef Node;

int n_examinations, n_cases, a, b = 0;

Node nodes[30];

bool gcp(int number){
  bool feasible;

  if(number == n_examinations + 1){
    return true;
  }

  for(int i = 1; i <= n_examinations; i++){ // cores
    feasible = true;
    for(int j = 0; j < (int)nodes[number].edges.size(); j++){
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

int main(){

  scanf("%d %d", &n_examinations, &n_cases);
  for(int j = 0; j < n_examinations; j++){
    Node node;
    node.color= 0;
    nodes[j] = node;
  }
  for(int i = 0; i < n_cases; i++){
    scanf("%d %d", &a, &b);
    nodes[a-1].edges.push_back(b);
    nodes[b-1].edges.push_back(a);
  }
 
  gcp(0);
  int colors[30] = {0};
  int n=0;
  for(int l = 0; l < n_examinations; l++){
    if (colors[nodes[l].color] == 0){
      colors[nodes[l].color]++;
      n++;
    }
  }

  printf("%d\n", n);
  return 0;
}

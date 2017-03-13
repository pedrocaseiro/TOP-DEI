#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int visited_nodes[12];
int nodes[12][2]; 
int number_of_nodes;


double best;

void solve(int i, double distance){

  int number_visited_nodes = 0;

  double calc = 0;
  if(distance == 0)
    visited_nodes[i] = 1;

  for(int j = 0; j < number_of_nodes; j++){
    if(visited_nodes[j] == 0){
      visited_nodes[j] = 1;
      calc = sqrt(pow((nodes[j][0] - nodes[i][0]),2) + pow((nodes[j][1] - nodes[i][1]),2));
      distance += calc;

      if(distance <= best){
        solve(j, distance);
      }
      distance -= calc;
      visited_nodes[j] = 0;
    } else {
      number_visited_nodes++;
    }
  }
  if(number_visited_nodes == number_of_nodes){
    if(best == 0){
      best = distance;
    }
    else if(distance < best){
      best= distance;
    }

  }
  return;
}

int main(){

  int a, b = 0;

  best = 100000;

  memset(visited_nodes,0,sizeof(visited_nodes));

  scanf("%d", &number_of_nodes);

  for(int i = 0; i < number_of_nodes; i++){
    scanf("%d %d", &a, &b);
    nodes[i][0] = a;
    nodes[i][1] = b;
  }

  for(int i = 1; i < number_of_nodes; i++){
    visited_nodes[i-1] = 0;
    solve(i, 0);
  }
  printf("%.3f\n", best);
   
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> weight;
vector<int> value;

int table[600][250][1000];

int knapsack(int i, int w, int v){
  if(i==0){
    return 0;
  }  
  if(table[i][w][v] >= 0){
    return table[i][w][v];
  }

  if(weight[i] > w){
    table[i][w][v] = knapsack(i-1, w, v);
  } else if(value[i] > v){
    table[i][w][v] = knapsack(i-1, w, v);
  } else {
    table[i][w][v] = max(knapsack(i-1, w, v), value[i] + knapsack(i-1, w - weight[i], v - value[i]));
  }
  return table[i][w][v];
}

int main(){
  int a, b, n_objects_supermarket, n_objects_choose, max_money = 0;
  
  scanf("%d\n%d\n%d", &n_objects_supermarket, &n_objects_choose, &max_money);
  for(int i = 0; i < n_objects_supermarket; i++){
    scanf("%d %d", &a, &b);
    weight.push_back(a);
    value.push_back(b);
  }
  int nunca_na_vida = knapsack(n_objects_supermarket, n_objects_choose, max_money);
  printf("%d", nunca_na_vida);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;


int sum = 0;
vector<int> coins;

int knapsack(int n, int w){
  int table[n+1][w+1];
  for(int j = 1; j <= w; j++){
    table[0][j] = 0;
  }

  for(int i = 0; i <= n; i++){
    table[i][0] = 0;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= w; j++){
      if(coins[i] > j){
        table[i][j] = table[i-1][j];
      }else {
        table[i][j] = max(table[i-1][j], coins[i] + table[i-1][j-coins[i]]);
      }
    }
  }
  return table[n][w];


}

int main(){
  int n_problems, n_coins, aux = 0;

  scanf("%d", &n_problems);
  for(int i = 0; i < n_problems; i++){
    sum = 0;
    coins.clear();
    scanf("%d", &n_coins);
    for(int j = 0; j < n_coins; j++){
      scanf("%d", &aux);
      coins.push_back(aux);
      sum += aux;
    }
    printf("%d\n", sum - 2*knapsack(n_coins, (int)sum/2));
  }
}

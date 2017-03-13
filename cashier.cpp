#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int result = 0;

vector<int> coins;

int number_of_changes(int change){

  int table[coins.size() + 1][change + 1];
  
  for(int i = 0; i <= coins.size(); i++){
    table[i][0] = 1;
  }

  for(int i = 1; i <= change; i++){
    table[0][i] = 0;
  }

  for(int i = 1; i <= coins.size(); i++){
    for(int j = 1; j <= change; j++){
      if(coins[i-1] <= j){ // verificar se a minha moeda tem valor maior do que aquele que preciso
        table[i][j] = table[i-1][j] + table[i][j - coins[i-1]];
      } else {
        table[i][j] = table[i-1][j]; // tem, vou ao valor da linha de cima
        printf("%d %d\n", table[i-1][j], table[i][j-coins[i-1]]);
      }
    }
  }

  //for(int i = 0; i < change; i++){
    //printf("\n");
    //for(int j = 0; j < coins.size(); j++){
      //printf("%d ", table[i][j]);
    //}
  //}

  return table[coins.size() - 1][change - 1];
}


// SOLUÇÃO DP BOTTOM UP!!
// PODIA SER RECURSIVA USANDO A SOLUÇÃO DA AULA MAS NÃO TEM AS CONSTRAINTS NO EUNCIADO
int main(){

  int n_test_cases, n_coins, change, aux = 0;

  scanf("%d", &n_test_cases);

  for(int i = 0; i < n_test_cases; i++){
    coins.clear();
    scanf("%d %d", &change, &n_coins);
    for(int j = 0; j < n_coins; j++){
      scanf("%d", &aux);
      coins.push_back(aux);
    }
    result = number_of_changes(change);
    printf("%d\n", result);
  }

  return 0;
}

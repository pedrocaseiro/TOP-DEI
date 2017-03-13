#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int number_of_changes(int coins[], int n_coins, int change){

  if(change == 0) return 1; // o troco é 0
  if(n_coins < 0) return 0; // não tenho moedas

  if(n_coins <= 0 && change >= 1) return 0; // fiquei sem moedas
  
  return number_of_changes(coins, n_coins - 1, change) + number_of_changes(coins, n_coins, change - coins[n_coins - 1]);


}

int main(){

  int n_test_cases, n_coins, change, aux = 0;
  int coins[] = {0};

  scanf("%d", &n_test_cases);

  for(int i = 0; i < n_test_cases; i++){
    scanf("%d %d", &change, &n_coins);
    memset(coins, 0, sizeof(int)*n_coins);
    for(int j = 0; j < n_coins; j++){
      scanf("%d", &aux);
      coins[j] = aux;
    }
    printf("%d\n", number_of_changes(coins, n_coins, change));
  }

  return 0;
}

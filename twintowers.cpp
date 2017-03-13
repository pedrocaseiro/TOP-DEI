#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> tiles_tower_1;
vector<int> tiles_tower_2;

int lcs(int n1, int n2){
  int table[n1+1][n2+1];
  for(int i = 0; i <= n1; i++){
    table[i][0] = 0;
  }

  for(int j = 0; j <= n2; j++){
    table[0][j] = 0;
  }

  for(int i = 1; i <= n1; i++){
    for(int j = 1; j <= n2; j++){
      if(tiles_tower_1[i-1] == tiles_tower_2[j-1]){
        table[i][j] = table[i-1][j-1] + 1;
      }else {
        table[i][j] = max(table[i-1][j], table[i][j-1]);
      }
    }
  }
  return table[n1][n2];


}

int main(){
  int n1, n2, aux, k = 0;

  while(scanf("%d %d", &n1, &n2) == 2){
    if(n1 == 0 && n2 == 0){
      return 0;
    }
    k++;
    tiles_tower_2.clear();
    tiles_tower_1.clear();
    for(int i = 0; i < n1; i++){
      scanf("%d", &aux);
      tiles_tower_1.push_back(aux); 
    }
    for(int i = 0; i < n2; i++){
      scanf("%d", &aux);
      tiles_tower_2.push_back(aux); 
    }
    int result = lcs(n1, n2);
    printf("Twin Towers #%d\n", k);
    printf("Number of Tiles : %d\n\n", result);
  }
  
  return 0;
}

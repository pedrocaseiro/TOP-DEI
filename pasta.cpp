#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int id, number_of_pastas, budget, cooking_time, taste_value = 0;

int pastas[5000][2];

double get_max_taste(){
  double cache[number_of_pastas+1][budget+1];
  int i,j,b;

  for(j = 0; j <= budget; j++){
    cache[0][j] = 0;
  }

  for(j = 0; j <= number_of_pastas; j++){
    cache[j][0] = 0;
  }

  for(i = 1; i <= number_of_pastas; i++){
    for(j = 1; j <= budget; j++){
      int inspetormax= 0;
      for(b = 1; b <= j; b++){
        inspetormax = max(cache[i-1][j], pastas[budget*(i-1) + b - 1][1] + cache[i-1][j-b]);
        if(inspetormax > cache[i][j]){
          cache[i][j] = inspetormax;
        }
      }
    }
  }
  return cache[number_of_pastas][budget];
}

int main() {
  int result = 0;

  scanf("%d %d", &number_of_pastas, &budget);
  for(int i = 0; i < number_of_pastas; i++){
    for(int j = 0; j < budget; j++){
      scanf("%d %d %d", &id, &cooking_time, &taste_value);
      pastas[budget*i + j%budget][0] = cooking_time;
      pastas[budget*i + j%budget][1] = taste_value;
    }
  }
  result = get_max_taste();
  printf("%d\n", result);
  return 0;
}

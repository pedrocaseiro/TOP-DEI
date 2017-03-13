#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int n = 0;

int lis(int *numbers, int k){
  int LIS[5001];
  int maximum = 0;

  for(int x = 0; x < n; x++){
    LIS[x] = 0;
  }

  LIS[0] = 1;
  for(int i = 0; i < k; i++){
    LIS[i] = 0;
    for(int j = 0; j<= i-1; j++){
      if(numbers[j] < numbers[i] && LIS[j] > LIS[i]){
        LIS[i] = LIS[j];
      }
    } 
    LIS[i] = LIS[i] + 1;
    if(LIS[i] > maximum){
      maximum = LIS[i];
    }
  } 

  return maximum;
}

int main(){
  int number_test_cases,aux, result = 0; 
  int numbers[5001];
  int reversed[5001];

 int best = 0;

  scanf("%d", &number_test_cases);

  for(int i = 0; i < number_test_cases; i++){
    scanf("%d", &n);
    for(int z = 0; z < n; z++){
      numbers[z] = 0;
      reversed[z] = 0;
    }
    for(int j = 0; j < n; j++){
      scanf("%d", &aux);
      numbers[j] = aux;
      reversed[n-1-j] = aux;
    }

    for(int k = 0; k < n; k++){
      if(k > 0 && k < n - 1){
        result = lis(numbers, k) + lis(reversed, n - 1 - k);
      } else if(k == 0){
        result = lis(numbers, k);
      } else if(k == n - 1){
        result = lis(reversed, 0);
      }

      if(result > best){
        best = result;
      }
    }
    printf("%d\n", best);
  }

  return 0;

}

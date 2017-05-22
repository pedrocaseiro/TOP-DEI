#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int n_objects, range, a = 0;
int table[100000];

int compare(const void * a, const void * b){
    return(*(int*)a - *(int*)b);
}

int main(){
  
  scanf("%d", &n_objects);
  scanf("%d", &range);

  for(int i = 0; i < n_objects; i++){
    scanf("%d", &a);
    table[i] = a;
  }

  // sort in non decreasing order by starting time
  qsort(table, n_objects , sizeof(int), compare);

  int sum = 0;
  int counter = 0;
  for(int i = 0; i < n_objects; i++){
    if(table[i] > sum){
      sum = table[i] + range*2;
      counter++;
    }
  }

  printf("%d\n", counter);

  return 0;
}

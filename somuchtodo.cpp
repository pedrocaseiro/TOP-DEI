#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int n_activities, a, b = 0;
int table[201][2];

int compare(const void * pa, const void * pb){
    const int *a = (int*)pa;
    const int *b = (int*)pb;

    return(a[1] - b[1]);
}

int main(){
  
  scanf("%d", &n_activities);

  for(int i = 0; i < n_activities; i++){
    scanf("%d %d", &a, &b);
    table[i][0] = a;
    table[i][1] = b;
  }

  // sort in non decreasing order by starting time
  qsort(table, n_activities, 2*sizeof(int), compare);

  int total = 1;

  int finishing_time = table[0][1];
  for(int j = 1; j < n_activities; j++){
    if(table[j][0] >= finishing_time){
      total++;
      finishing_time = table[j][1];
    }
  }

  printf("%d\n", total);
  return 0;
}

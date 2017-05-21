#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int n_routers, a, b, l, start, finish = 0;
int table[100001][2];
int solutions[100001][2];

int compare(const void * pa, const void * pb){
    const int *a = (int*)pa;
    const int *b = (int*)pb;

    if(a[0] == b[0])
      return((a[1] - a[0]) - (b[1] - b[0]));
    else
      return(a[0] - b[0]);
}

int main(){
  
  scanf("%d", &l);
  scanf("%d", &n_routers);

  for(int i = 0; i < n_routers; i++){
    scanf("%d %d", &a, &b);
    table[i][0] = a - b;
    table[i][1] = a + b;
  }

  // sort in non decreasing order by starting time
  qsort(table, n_routers, 2*sizeof(int), compare);

  int total = 0;
  int aux = 1;
  solutions[0][0] = table[0][0];
  solutions[0][1] = table[0][1];
  for(int j = 1; j < n_routers; j++){
    if(table[j][0] >= solutions[aux-1][0] && table[j][1] <= solutions[aux-1][1]){ // está contido
      total++;
    } else if(table[j][0] > solutions[aux-1][0] && table[j][1] > solutions[aux-1][1] && table[j][0] < solutions[aux-2][1] && aux != 1){
      total++;
      solutions[aux-1][0] = table[j][0];
      solutions[aux-1][1] = table[j][1];
    }else if(table[j][0] == solutions[aux-1][1] || (table[j][0] > solutions[aux-1][0] && table[j][0] < solutions[aux-1][1])){
      solutions[aux][0] = table[j][0];
      solutions[aux][1] = table[j][1];
      aux++;
    }
  }

  printf("%d\n", total);
  return 0;
}

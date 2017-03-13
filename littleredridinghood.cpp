#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

unsigned long wolves[101][101];
unsigned long grid[101][101];

unsigned long count(unsigned long w, unsigned long h){
  unsigned long table[w+1][h+1];

  for(unsigned long i = 0; i < w; i++){
    table[i][0] = 1;
  }

  for(unsigned long j = 0; j < h; j++){
    table[0][j] = 1;
  }

  for(unsigned long i=0; i < w; i++){
    for(unsigned long j=0; j < h; j++){
      if(wolves[i][j] == 1){
        table[i][j] = 0;
      } else {
        if(j==0 && i==0){
          table[i][j] = 1;
        }else if(i==0){
          table[i][j] = table[i][j-1];
        }else if(j==0){
          table[i][j] = table[i-1][j];
        } else{
          table[i][j] = table[i-1][j] + table[i][j-1];
        }
      }
    }
  }
  
  return table[w-1][h-1];
}

int main(){
  
  unsigned long w, h, n_wolves, wolf_w, wolf_h, result = 0;

  while(scanf("%ld %ld", &w, &h) == 2 && (w || h)){
    for(unsigned long i = 0; i < w; i++){
      for(unsigned long j = 0; j < h; j++){
        wolves[i][j] = 0;
        grid[i][j] = 0;
      }
    }
    scanf("%ld", &n_wolves);
    for(unsigned long i = 0; i < n_wolves; i++){
      scanf("%ld %ld", &wolf_w, &wolf_h);
      wolves[wolf_w][wolf_h] = 1; // posições onde estão lobos
    }
    w++;
    h++;
    result = count(w,h);

    if(result == 0){
      printf("There is no path.\n");
    }else if(result == 1){
      printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
    } else {
      printf("There are %lu paths from Little Red Riding Hood's house to her grandmother's house.\n", result);
    }
  }

  return 0;
}

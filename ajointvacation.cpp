#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

typedef struct place{
  vector<int> costs;
}place;

vector<place> places;
int n_places, finish;

// we use floyd warshall because it gives the shortest path between two points in any graph
void floyd_warshall(){
  int i, j, k;
  long int matrix[n_places+1][n_places+1];

  // necessary?
  for(i = 0; i < n_places; i++){
    for(j = 0; j < n_places; j++){
      matrix[i][j] = 0;
    }
  }

  for(i = 0; i < n_places; i++){
    for(j = 0; j < n_places; j++){
      if(places[i].costs[j] != -1){
        matrix[i][j] = places[i].costs[j];
      } else {
        matrix[i][j] = INT_MAX;
      }
    }
  }

  for(k = 0; k < n_places; k++){
    for(i = 0; i < n_places; i++){
      for(j = 0; j < n_places; j++){
        if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
          matrix[i][j] = matrix[i][k] + matrix[k][j];
        }
      }
    }
  }

  //for(i = 0; i < n_places; i++){
    //for(j = 0; j < n_places; j++){
      //printf("%lu\t", matrix[i][j]);
    //}
    //printf("\n");
  //}
  printf("%ld\n", matrix[0][finish-1]);
}

int main() {
  int i, j;
  int a, b;

  scanf("%d %d", &n_places, &finish);
  
  // indices do enunciado começam a 1, isto é necessário?
  for(i = 0; i < n_places; i++){
    scanf("%d", &a);
    place p;
    for(j = 0; j < n_places; j++){
      scanf("%d", &b);
      p.costs.push_back(b);
    }
    places.push_back(p);

  }

  floyd_warshall();
  //for(i = 0; i < n_places; i++){
    //for(j = 0; j < n_places; j++){
      //printf("%d\t", places[i].costs[j]);
    //}
    //printf("\n");
  //}
  return 0;
}

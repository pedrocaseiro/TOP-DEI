#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int n_test_cases, n;
int starting_x = -1;
int starting_y = -1;
int minimum_moves;
int remaining_black_rooks;

int board[8][8];
int visited[8][8];


void get_minimum_moves(int x, int y, int moves, int remaining_black_rooks){
  if(visited[y][x] || moves >= minimum_moves){
    return;
  }

  if(board[y][x] == 1){
    remaining_black_rooks--;
  }

  if(remaining_black_rooks == 0){
    if(moves < minimum_moves) minimum_moves = moves;
    return;
  }

  visited[y][x] = 1;

  if(y >= 1){
    get_minimum_moves(x, y - 1, moves + 1, remaining_black_rooks);
  }

  if(y < n - 1){
    get_minimum_moves(x, y + 1, moves + 1, remaining_black_rooks);
  }

  if(x >= 1){
    get_minimum_moves(x - 1, y, moves + 1, remaining_black_rooks);
  }

  if(x < n - 1){
    get_minimum_moves(x + 1, y, moves + 1, remaining_black_rooks);
  }

  visited[y][x] = 0;
}

int main(){

  scanf("%d", &n_test_cases);
  scanf("%d", &n);

  for(int k = 0; k < n_test_cases; k++){
    remaining_black_rooks = 0;
    minimum_moves = 100;

    memset(board, 0, sizeof board);
    memset(visited, 0, sizeof visited);


    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        scanf("%d", &board[i][j]);

        if(board[i][j] == 1) remaining_black_rooks++;
        else if(board[i][j] == 2){
          starting_x = j;
          starting_y = i;
        }
      }
    }
    get_minimum_moves(starting_x, starting_y, 0, remaining_black_rooks);

    printf("%d\n", minimum_moves);
  }

  return 0;
}

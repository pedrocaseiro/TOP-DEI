#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

struct {
  int courses[15][2];
}typedef Department;

int result, num_departments, max_ECTS, n_courses, ects, satisfaction = 0;
Department departments[300];
vector<int> aux;

double get_max_satisfaction(){
  double cache[num_departments+1][max_ECTS+1];
  int i,j,b;

  for(j = 0; j <= max_ECTS; j++){
    cache[0][j] = 0;
  }

  for(j = 0; j <= num_departments; j++){
    cache[j][0] = 0;
  }

  for(i = 1; i <= num_departments; i++){
    for(j = 1; j <= max_ECTS; j++){
      int inspetormax= 0;
      int size = aux[i-1];
      for(b = 1; b <= size; b++){
        inspetormax = max(cache[i-1][j], departments[i-1].courses[b-1][1] + cache[i-1][j-b*departments[i-1].courses[b-1][0]]);
        if(inspetormax > cache[i][j]){
          cache[i][j] = inspetormax;
        }
      }
    }
  }
  return cache[num_departments][max_ECTS];
}

int main() {

  scanf("%d %d", &num_departments, &max_ECTS);

  for(int i = 0; i < num_departments; i++){
    scanf("%d", &n_courses);
    aux.push_back(n_courses);
    Department department;
    for(int j = 0; j < n_courses; j++){
      scanf("%d %d", &ects, &satisfaction);
      department.courses[j][0] = ects;
      department.courses[j][1] = satisfaction;
    }
    departments[i] = department;
  }
  result = get_max_satisfaction();
  printf("%d\n", result);
  return 0;
}

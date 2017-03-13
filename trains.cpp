#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j,k,l,size_train,max;
    unsigned int cars[5001];
    int aux[5001];
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&cars[i]);
    }
    
    aux[0] = 1;
    for (j=1;j<n;j++){
        size_train = 0;
        for (k=j-1;k>=0;k--){
            if (cars[j] > cars[k] && size_train < aux[k]){
                size_train = aux[k];
            }
        }
        aux[j] = ++size_train;
    }
    
    max = 0;
    for (l=0;l<n;l++){
        if (aux[l] > max){
            max = aux[l];
        }
    }
    printf("%d\n",max);
    return 0;
}

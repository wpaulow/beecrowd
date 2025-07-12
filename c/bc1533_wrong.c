#include <stdio.h>
#include <stdlib.h>
#include "lista-ord.h"

int main(void) {
    int N, i;

    while(1){
        scanf("%d", &N);
        if(N == 0) break;
        Lista OrdList = NULL;
        int x;

        for(i = 1; i <= N; i++){
            scanf("%d", &x);
            ins_inv_sr(x, &OrdList);
        }
        printf("%d\n", OrdList->prox->item); // aqui está retornando o item, e o desafio pede o índice
    }

    return 0;
}
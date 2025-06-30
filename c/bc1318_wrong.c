/**
*   https://judge.beecrowd.com/pt/problems/view/1318
*   Entrada
*       A entrada contém dados de diversos casos de teste. Cada caso de teste contém duas linhas. A primeira linha contém dois inteiros N e M, que indicam, 
*   respectivamente, o * número de bilhetes originais e o número de pessoas presentes na festa (1 ≤ N ≤ 10000 e 1 ≤ M ≤  20000). A segunda linha do caso 
*   de testes contém M inteiros Ti representando os números dos bilhetes contidos no pacote que o diretor lhe deu (1 ≤ Ti ≤ N). O final da entrada é 
*   indicado por N = M = 0.

*   Saída
*       Para cada caso de teste seu programa deverá imprimir uma linha, contendo o número de bilhetes do pacote que contém outro bilhete com o mesmo número 
*   da sequência.
* 
* 
*   Observação Pessoal      
*       O resultado final por si só não consegue dizer nada. Pois, saber quantos bilhetes tem ao menos uma repetição, não garante que são esses algum 
*   desses bilhetes que se repetiram eram originais, e nem sequer que existiu algum original, mesmo dentre aqueles que não tiveram repetições.
*   De modo que saber também quantas repetições há de ao total existem entre os bilhetes, incluindo os que se repetem mais de uma vez, pode ajudar na 
*   definição das probabilidades envolvendo um cenário parecido com o do problema.  
*
*   Autor
*       GitHub: @wpaulow
* 
**/
#include <stdio.h>
#include <math.h>
#include "pilhaTeste.h"
 
int main(int argc, char *argv[]) {
    int tickets = 1, people = 1, out_size = 1;
    int *repetidos = (int*)calloc(tickets + 1, sizeof(int));

    scanf("%d %d", &tickets, &people);

    while(tickets != 0 && people != 0){
        int  pilha_size = 0, pack_tickets[people]; // pack of tickets
        for(int i = 0; i < people; i++) scanf("%d", &pack_tickets[i]);
        // empilha bilhetes únicos
        Pilha tickets_rep = pilha(people-1);
        for(int i = 0; i < people-1; i++) {
            for(int j = i+1; j < people; j++){
                if(pack_tickets[i] == pack_tickets[j]){
                    empilha(pack_tickets[i], tickets_rep);
                    pilha_size++;
                    j = people;                
                }            
            }        
        }
        destroiP(tickets_rep);
        out_size++;
        *repetidos = (int*)realloc(repetidos, sizeof(int)*out_size);
        scanf("%d %d", &tickets, &people);
    }
    while(*repetidos) printf("%d\n", *(repetidos)+1);
    
    return 0;
}

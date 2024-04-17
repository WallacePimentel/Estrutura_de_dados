//Lista 2 - Estrutura de Dados - 2024.1
//Autor: Wallace da Rocha Pimentel Júnior

#include "TABB.h"

//Questão 1
TABB* maior (TABB* a){
    if (!a) return NULL;
    if (!a->dir) return a;
    return maior(a->dir);
}

//Questão 2
TABB* menor(TABB* a){
    if (!a) return NULL;
    if (!a->esq) return a;
    return menor(a->esq);
}

//Questão 3 --------COM PROBLEMA--------
TABB* retira_impares(TABB* a){
    if (!a) return NULL;
    if (a->esq) retira_impares(a->esq);
    if (a->dir) retira_impares(a->dir);
    if ((a->info % 2) != 0) return TABB_retira(a,a->info);
    return a;
}

//Questão 4 Auxiliar 1
int nn(TABB* a){
    if (!a) return 0;
    return 1 + nn(a->esq) + nn(a->dir);
}

//Questão 4 Auxiliar 2
void vetorizante(TABB* a, int* vet, int *pos){
    if (!a) return;
    vetorizante(a->esq,vet,pos);
    vet[(*pos++)] = a->info;
    vetorizante(a->dir,vet,pos);
}

//Questão 4
int* mN(TABB* a){
    if (!a) return NULL;
    int *resp = (int*) malloc (sizeof(int) * nn(a)), pos = 0;
    vetorizante(a,resp,&pos);
    return resp;
}

//Questão 5

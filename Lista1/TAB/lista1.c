//Lista 1 - Estrutura de Dados - 2024.1
//Autor: Wallace da Rocha Pimentel Júnior

#include "TAB.h"

//Questão 01
TAB* copia (TAB *a){
    if (!a) return NULL;
    return TAB_cria(a->info,copia(a->esq),copia(a->dir));
}

//Questão 02
TAB* espelho (TAB *a){
    if (!a) return NULL;
    return TAB_cria(a->info,espelho(a->dir),espelho(a->esq));
}

//Questão 03 Auxiliar
TAB* cmp_maior (TAB* a1, TAB* a2){
    if (a1 && a2){
        if (a1->info > a2->info) return a1;
        return a2;
    }
    if (!a1) return a2;
    if (!a2) return a1;
    return NULL;
}

//Questão 03
TAB *maior_arv (TAB* a){
    if (!a) return NULL;
    TAB *maior_esq = maior_arv(a->esq);
    TAB *maior_dir = maior_arv(a->dir);
    return cmp_maior(cmp_maior(maior_esq,maior_dir),a);
}

//Questão 04 Auxiliar
TAB* cmp_menor (TAB* a1, TAB* a2){
    if (a1 && a2){
        if (a1->info > a2->info) return a2;
        return a1;
    }
    if (!a1) return a2;
    if (!a2) return a1;
    return NULL;
}

//Questão 04
TAB *menor_arv (TAB* a){
    if (!a) return NULL;
    TAB *menor_esq = menor_arv(a->esq);
    TAB *menor_dir = menor_arv(a->dir);
    return cmp_menor(cmp_menor(menor_esq,menor_dir),a);
}

//Questão 05
int igual (TAB* a1, TAB* a2){
    if ((!a1) && (!a2)) return 1;
    if ((!a1) || (!a2)) return 0;
    if ((a1->info) == (a2->info)){
        return (igual(a1->esq,a2->esq) && igual(a1->dir,a2->esq));
    }
    return 0;
}

//Questão 06
TAB* retira_pares(TAB* a){

}

//Questão 07
void colore (TAB *arv){

}

//Questão 08
int ni(TAB* a){
    if (!a) return 0;
    if (a->esq && a->dir) return (1 + ni(a->esq) + ni(a->dir));
    if (a->esq) return (1 + ni(a->esq));
    if (a->dir) return (1 + ni(a->dir));
    return 0;
}

//Questão 09
int nf(TAB* a){
    if (!a) return 0;
    if (!a->esq && !a->dir) return 1;
    return (nf(a->esq) + nf(a->dir));
}
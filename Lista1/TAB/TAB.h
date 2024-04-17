#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

TAB *TAB_inicializa(void);
TAB *TAB_cria(int raiz, TAB *esq, TAB *dir);

void TAB_imp_pre(TAB *a);
void TAB_imp_pos(TAB *a);
void TAB_imp_sim(TAB *a);
void TAB_imp_ident(TAB *a);

void TAB_libera(TAB *a);

TAB *TAB_busca(TAB *a, int elem);

int TAB_altura(TAB *a);

//Funções da Lista 1
//Questão 1
TAB* copia (TAB *a);
//Questão 2
TAB* espelho (TAB *a);
//Questão 3
TAB *maior_arv (TAB* a);
//Questão 4
TAB *menor_arv (TAB* a);
//Questão 5
int igual (TAB* a1, TAB* a2);
//Questão 6
TAB* retira_pares(TAB* a);
//Questão 7
void colore (TAB *arv);
//Questão 8
int ni(TAB* a);
//Questão 9
int nf(TAB* a);
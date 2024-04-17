#include "TABB.h"
#include "TLSE.h"

//Questão 1
int nn_maior (TABB* a, int num){
	if (!a) return 0;
	if (a->info < num) return 0 + nn_maior(a->esq,num) + nn_maior(a->dir,num);
	return 1 + nn_maior(a->esq,num) + nn_maior(a->dir,num);
}

void preenche_vetor(int* vet, TABB* a, int* tam, int num){
	if (!a) return;
	if (a->info > num) vet[(*tam)++] = a->info;
	preenche_vetor(vet, a->esq, tam, num);
	preenche_vetor(vet, a->dir, tam, num);
}

int* mN_maior (TABB* a, int num, int *tam){
	if (!a) return NULL;
	int* resp = (int*) malloc (sizeof(int) * nn_maior(a,num));
	preenche_vetor(resp, a, tam, num);
	return resp;
}

//Questão 2
int zz_aux(TABB* a){
	if (!a) return 1;
	if (a->esq && a->dir) return 0;
	if (a->esq) return zz_aux(a->esq);
	return zz_aux(a->dir);
}

int zz(TABB *a){
	if (!a) return 1;
	if ((zz_aux(a->esq)) && (zz_aux(a->dir))) return 1;
	return 0; 
}

//Questão 3
TLSE* ancestrais(TABB* a, int elem){
	if (!a || (a->info == elem)) return NULL;
	TLSE* resp = TLSE_insere(NULL,a->info);
	if (a->info > elem) resp->prox = ancestrais(a->esq, elem);
	else resp->prox = ancestrais(a->dir, elem); 
	return resp;
}

//Questão 4
int estbin (TABB* a){
	if (!a) return 1;
	if (a->esq && !a->dir) return 0;
	if (!a->esq && a->dir) return 0;
	if (!estbin(a->esq)) return 0;
	return estbin(a->dir);
}

//Questão 5
//Aux1
int nn(TABB* a){
    if (!a) return 0;
    if (a) return 1 + nn(a->esq) + nn(a->dir);
}

//Aux2
void vetorizante(TABB* a, int* vet, int *pos){
    if (!a) return;
    vetorizante(a->esq,vet,pos);
    vet[(*pos++)] = a->info;
    vetorizante(a->dir,vet,pos);
}

//Aux3
int* mN(TABB* a){
    if (!a) return NULL;
    int *resp = (int*) malloc (sizeof(int) * nn(a)), pos = 0;
    vetorizante(a,resp,&pos);
    return resp;
}

//Main
int mi(TABB *a1, TABB *a2){
    if (!a1 && !a2) return 1;
    if (!a1 || !a2) return 0;
    if (nn(a1) != nn(a2)) return 0;
    int i, *resp_a1 = mN(a1), *resp_a2 = mN(a2);
    for(i = 0; i < nn(a1);i++){
        if (resp_a1[i] != resp_a2[i]) {
            free(resp_a1);
            free(resp_a2);
            return 0;
        }
    }
    free(resp_a1);
    free(resp_a2);
    return 1;
}
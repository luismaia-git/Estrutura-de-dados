#include <stdlib.h>
#include <stdio.h>

struct _regInt {
  int val;
  int vis;
  struct _regInt *esq, *dir;
};

typedef struct _regInt RegInt;

RegInt* cria_no(int val){
  RegInt* aux = malloc(sizeof(RegInt));
  aux ->val = val;
  aux ->vis = 0;
  aux ->esq = NULL;
  aux ->dir = NULL;
  return aux;
}

RegInt* insercao(int K, RegInt *P){
  RegInt *aux, *q1, *q2;
  aux = cria_no(K);

  if(P == NULL) return aux;
  q1 = P;
  q2 = NULL;
  while (q1 != NULL) { // walking down the tree (down)
    q2 = q1;
    if (K < q1->val) 
      q1 = q1->esq;
    else if (K > q1->val)
      q1 = q1->dir;
    else 
      return P;
  };
  
  if(K < q2->val){ //if the K is less than the value of the Parent record
      q2 -> esq = aux;
    }
    else
      q2 -> dir = aux;
  return P;

};

//percorrer em ordem
void percorrerOrdem(RegInt *P){
    
    if (P == NULL)
        return;

    percorrerOrdem(P->esq);
    printf("%d " , P->val);
    percorrerOrdem(P->dir);

}


RegInt remove_menor_rec(RegInt *P) {
  RegInt *m=NULL, *q = NULL;
  if(P == NULL) return;

  if (P ->esq == NULL) {
    m = P;
    P = P->dir;
    m->dir = NULL;
    return(m,P);
  }
  else {
    m = remove_menor_rec(P->esq);
    q = remove_menor_rec(P->esq);
    P->dir = q;
    return (m,P);
  }
}

RegInt algoritmo_remocao(int k,RegInt *P){
  RegInt *m=NULL, *q = NULL;

  if (P == NULL)
    return;
  
  if (k == P->val) {
    m = remove_menor_rec(P->dir);
    q = remove_menor_rec(P->dir);

    if(m == NULL) return(P->esq);
    else {
      m->esq = P->esq;
      m->dir = q;
    }
  }
  if (k < P->val) 
    P->esq = algoritmo_remocao(k,P->esq);
  else 
    P->dir = algoritmo_remocao(k,P->dir);
  return(P);
}


void questao1(RegInt *P, int *k){
  if (P == NULL)
    return;
  
  questao1(P->esq, k);
  if (*k != 1) 
    (*k)--;
  else {
    printf("%d ", P->val);
    (*k)--;
    return;
  }
  questao1(P->dir, k);
  
}

void questao2(RegInt *P, int k){
  if (P == NULL)
    return;
  
  if (k == 1){
    printf("%d ", P->val);
  }
  questao2(P->esq, k-1);
  questao2(P->dir, k-1);
}

void questao4(RegInt *P, int k){
  if (P == NULL)
    return;
  
  if (k == 1){
    algoritmo_remocao(P->val, P);
  }
  questao4(P->esq, k-1);
  questao4(P->dir, k-1);
}


void questao5(RegInt *P, int k, int *val){
  
  if (P == NULL)
    return;
  
  questao5(P->esq, k, val);
  if(abs(k-*val) > abs(k-P->val)) {
    *val = P->val;
  }
  questao5(P->dir, k, val);
  
}


int main (int narg, char *argv[]) {
  RegInt *P= NULL, *J= NULL , *L=NULL , *M=NULL;

//questao 1
  P = insercao(10, P);
  P = insercao(8, P);
  P = insercao(15, P);
  P = insercao(3, P);
  P = insercao(9, P);
  P = insercao(11, P);
  P = insercao(20, P);

//questao 2
  J = insercao(25, J);
  J = insercao(16, J);
  J = insercao(32, J);
  J = insercao(4, J);
  J = insercao(9, J);
  J = insercao(27, J);
  J = insercao(54, J);

//questao 4
  M = insercao(6, M);
  M = insercao(2, M);
  M = insercao(8, M);
  M = insercao(1, M);
  M = insercao(3, M);
  M = insercao(7, M);
  M = insercao(10, M);

//questao 5
  L = insercao(13, L);
  L = insercao(5, L);
  L = insercao(20, L);
  L = insercao(2, L);
  L = insercao(6, L);
  L = insercao(15, L);
  L = insercao(31, L);

  int k1 = 5;
  printf("Questao 1\n");
  printf("Print da arvore: \n");
  percorrerOrdem(P);
  printf("\n\n");
  printf("Imprimir o k-esimo menor elemento da arvore: \n");
  printf("Valores: k = %d\n", k1);
  questao1(P, &k1);
  printf("\n\n");


  int k2=4;
  printf("Questao 2\n");
  printf("Print da arvore: \n");
  percorrerOrdem(J);
  printf("\n\n");
  printf("Imprimir todos os elementos do nivel k: \n");
  printf("Nivel: %d \n", k2);
  questao2(J,k2);
  printf("\n\n");

  int k4=2;
  printf("Questao 4\n");
  printf("Print da arvore: \n");
  percorrerOrdem(M);
  printf("\n\n");
  printf("Remover todos os elementos do nivel k: \n");
  printf("Nivel: %d \n", k4);
  questao4(M,k4);
  percorrerOrdem(M);
  printf("\n\n");


  int k5=200, valor=1000;
  printf("Questao 5\n");
  printf("Print da arvore: \n");
  percorrerOrdem(L);
  printf("\n\n");
  printf("Procurar pelo elemento k na arvore: \n");
  printf("K: %d \n", k5);
  questao5(L,k5,&valor);
  printf("%d\n", valor);
  printf("\n\n");

  return EXIT_SUCCESS;
}
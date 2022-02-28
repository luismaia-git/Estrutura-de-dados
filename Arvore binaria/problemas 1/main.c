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

void questao1(RegInt *P, int *cont){
  
  if (P == NULL)
    return;
  *cont = *cont +1;
  questao1(P->esq, cont);
  questao1(P->dir, cont);
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

void questao5(RegInt *P, int *k){
  if (P == NULL)
    return;
  
  questao5(P->dir, k);
  if (*k != 1) 
    (*k)--;
  else {
    printf("%d ", P->val);
    (*k)--;
    return;
  }
  questao5(P->esq, k);
  
}


void questao6(RegInt *P, int k, int l){
  if (P == NULL)
    return;
  
  if (P->val >= k && P->val <= l){
    printf("%d ", P->val);
  }
  questao6(P->esq, k, l);
  questao6(P->dir, k, l);
}



//percorrer em ordem
void percorrerOrdem(RegInt *P){
    
    if (P == NULL)
        return;

    percorrerOrdem(P->esq);
    printf("%d " , P->val);
    percorrerOrdem(P->dir);

}

int main (int narg, char *argv[]) {
  RegInt *P= NULL, *J = NULL, *M= NULL, *V= NULL;

//questao 1
  P = insercao(13, P);
  P = insercao(5, P);
  P = insercao(20, P);
  P = insercao(2, P);
  P = insercao(6, P);
  P = insercao(15, P);
  P = insercao(31, P);

//questao 2
  J = insercao(25, J);
  J = insercao(16, J);
  J = insercao(32, J);
  J = insercao(4, J);
  J = insercao(9, J);
  J = insercao(27, J);
  J = insercao(54, J);

//questao 5
  V = insercao(13, V);
  V = insercao(5, V);
  V = insercao(20, V);
  V = insercao(2, V);
  V = insercao(6, V);
  V = insercao(15, V);
  V = insercao(31, V);

//questao 6
  M = insercao(22, M);
  M = insercao(15, M);
  M = insercao(36, M);
  M = insercao(12, M);
  M = insercao(17, M);
  M = insercao(29, M);
  M = insercao(61, M);
  

  int i=0;
  printf("Questao 1\n");
  printf("Print da arvore: \n");
  percorrerOrdem(P);
  printf("\n\n");
  printf("Contar os elementos da arvore:\n");
  questao1(P,&i);
  printf("%d\n", i);
  printf("\n");

  int k2=3;
  printf("Questao 2\n");
  printf("Print da arvore: \n");
  percorrerOrdem(J);
  printf("\n\n");
  printf("Imprimir todos os elementos do nivel k: \n");
  printf("Nivel: %d \n", k2);
  questao2(J,k2);
  printf("\n\n");
  
  int k5 = 3;
  printf("Questao 5\n");
  printf("Print da arvore: \n");
  percorrerOrdem(V);
  printf("\n\n");
  printf("Imprimir o k-esimo maior elemento da arvore: \n");
  printf("Valores: k = %d\n", k5);
  questao5(V, &k5);
  printf("\n\n");



  int k6=15, l6=25;
  printf("Questao 6\n");
  printf("Print da arvore: \n");
  percorrerOrdem(M);
  printf("\n\n");
  printf("Imprimir todos os elementos da arvore que estao entre os valores k e l: \n");
  printf("Valores: k=%d e l=%d\n", k6, l6);
  questao6(M,k6,l6);
  printf("\n\n");
 



  return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

struct No{
  int info;
  struct No * prox;
};
typedef struct No * PtrNo;

void criaLista(PtrNo *l);
void menu(PtrNo *l);
void insere(PtrNo *l);
int busca(PtrNo l, int x);
void remove_n(PtrNo *l);
void imprime(PtrNo *l);
void verifica(PtrNo *l);

int main(void) {
  
  PtrNo l = (PtrNo)malloc(sizeof(struct No*));
  if(!l)
    printf("Erro ao criar nó.");
  
  criaLista(&l);
  menu(&l);
  
  return 0;
}

void criaLista(PtrNo *l){
  (&(**l))->prox = NULL;
}

void menu(PtrNo *l){
  
  int op;
  PtrNo aux = *l;
  
  do{
    system("clear");
    printf("\n========================");
    printf("\n========= MENU =========\n");
    printf("\n1 - Inserir elementos.\n2 - Remover elementos.\n3 - Mostrar estrutura.\n4 - Verificar lista.\n0 - Sair\n");
    printf("\n========================\n");
    scanf("%d",&op);

    switch(op){
      case 1:
        insere(&aux);
      break;
      
      case 2:
        remove_n(&aux);
      break;
      
      case 3:
        imprime(&aux);
      break;

      case 4:
        verifica(&aux);
      break;
    }
  }while(op != 0);
  
}

void insere (PtrNo *l){

  int op;
  
  do{
    system("clear");
    int elem;
    PtrNo novoNo;
    novoNo = (struct No*)malloc(sizeof(struct No));
    if(!novoNo)
      printf("Erro ao criar nó.");
    
    printf("Digite o elemento para inserir: ");
    scanf("%d",&elem);
    novoNo->info = elem;
    novoNo->prox = *l;
    *l= novoNo;
    
    printf("\n 1 - Continuar\n 0 - Sair\n");
    scanf("%d",&op);
    getchar();
    
  }while(op != 0);

}

int busca (PtrNo l, int x){

  if(l == NULL)
    return 0;
  else{
    if(x == l->info)
      return 1 + busca(l->prox, x);
    return 0 + busca(l->prox, x);
  }
  
  return 0;
}

void remove_n (PtrNo *l){
  int op;
  
  do{
  
    system("clear");
    int n, flag = 0;
  
    printf("Digite o valor para retirar da lista: ");
    scanf("%d",&n);
  
    PtrNo aux = *l, ant, apaga;
  
    flag = busca(aux, n);
  
    if(flag != 0){
            
      aux = ant = *l;
      
      while(aux != NULL){
        if(aux->info == n){
          if(ant == aux){
            *l = ant = aux->prox;
            apaga = aux;
            free(apaga);
            aux = *l;
  
          }else{
            ant->prox = aux->prox;
            apaga = aux;
            free(apaga);
            aux = ant;
          }
        }
        ant = aux;
        aux = aux->prox;
      }
      printf("Valor retirado com sucesso!");
    }
    else
      printf("Valor não encontrado na lista, tente novamente.");
    
    printf("\n 1 - Continuar\n 0 - Sair\n");
    scanf("%d",&op);
    getchar();
    
  }while(op != 0);
}

void imprime(PtrNo *l){
  system("clear");

  int op;
  PtrNo aux = *l;

  printf("Lista: ");
  
  while(aux->prox != NULL){
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n\nTecle 0 para sair\n");
  scanf("%d",&op);
  getchar();
  
}

void verifica_(PtrNo *l){
  system("clear");

  int op;
  PtrNo aux = *l;
  if(aux->prox == NULL)
    printf("Lista vazia");
  else
    printf("Lista não está vazia");

  printf("\n\nTecle 0 para sair\n");
  scanf("%d",&op);
  getchar();
}
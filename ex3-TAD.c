#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"ex3-TAD.h"

struct no
{
    int coef;
    int expo;
    struct no *prox;
};

/*
   Operação cria_lista, aloca um espaço na memória pra ser alocado o polinômio.
*/
Lista cria_lista()
{
// aloca nó cabeçalho
   Lista cab;
   cab =(Lista)malloc(sizeof(struct no));

   if(cab !=NULL){
    cab->prox = NULL;
    cab -> coef = 0;
    cab -> expo = 0;
   }
   return cab;
}
/*
A operação esvazia lista esvazia o polinômmio e ele volta para a posição Inial dele;
*/
int esvazia_lista(Lista *lst)

{
    if(lista_vazia(*lst)== 1)
      return 0;

    /*Lista aux = *lst;
    Lista aux2 = *lst;

    if(aux->prox != NULL)
     aux = aux->prox;

   while(aux->prox != NULL){
    free(aux2);
    aux2 = aux;
    aux= aux->prox;
   }

   free(aux);

   aux = cria_lista();
   aux= *lst;

   return 1;
*/
    else
    {
       (*lst)->prox = NULL;
    }

}
/*
A operação Lista vazia retorna se há algum valor dentro do polinômio;
*/
int lista_vazia(Lista lst)
{

  if(lst->prox==NULL)
    return 1; // Lista Vazia
  else
    return 0; // Lista Não vazia.
}

// Inserindo um novo termo em um polinômio já criado
int insere_term(Lista *lst, int baixo, int cima)
{
    if(*lst==NULL  || cima<0){return 0;}
    Lista aux = *lst; // Faz auz apontar para o cabeçalho
     while(aux->prox != NULL && aux->prox->expo<cima)


        aux = aux->prox;  // avança


    Lista N = (Lista)malloc(sizeof(struct no));
    if(N==NULL){return 0;}

    N->coef= baixo;
    N->expo= cima;




    // Insere o novo nó na lista
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}
// Remove o K-ésimo termo da Lista,
//Removendo tanto o expoente quanto o coeficiente ligado ao expoente escolhido
int remove_kesi(Lista *lst, int cima)
{
    if(lista_vazia(*lst)|| cima< (*lst)->expo)
      return 0;
      // alocando ponteiro para começar
    Lista aux= *lst;
   // caso esteja no início d lista tira


   //procurar na lista
   while(aux->prox!=NULL && aux->prox->expo<cima)
   aux=aux->prox;

   // Se o while acabar no fim, elem não esta na Lista
   if(aux->prox ==NULL || aux->prox->expo>cima )
     return 0;

    // operação para remover
    Lista aux2 = aux->prox;    // apontando pro nó
    aux->prox = aux2->prox;    // tira o nó
    free(aux2);                // Libera o que foi alocado
    return 1;
}

// Função Get_elem seleciona o elemento com base na posição solicitada,
// No caso desse programa o get_elem foi utilizado para auxiliar na operação de imprimir
int Get_elem(Lista lst,int *c, int *e, int posi)
{
   Lista aux = lst;
   int pl=0;
   while(aux->prox != NULL && posi!= pl){
    aux=aux->prox;
    pl++;
   }
   if(aux->prox == NULL && posi != pl)
    return 0;
   *c = aux->coef;
   *e = aux->expo;
   return 1;


}
/* Essa operação ela deixa o usuário do programa escolher qual será o valor
a ser substituído na variável X;
*/
int calc_poli(Lista *lst, int x)
{
    Lista aux = *lst;
    int r = 0;
    while(aux->prox != NULL){
       r += aux->coef *(pow(x, aux->expo));
       aux = aux->prox;
    }

      r += aux->coef *(pow(x, aux->expo));
      return r;
}

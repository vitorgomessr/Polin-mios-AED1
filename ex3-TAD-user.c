#include <stdio.h>
#include<stdlib.h>
#include "ex3-TAD.h"

void imprime_lista(Lista lst)
{
    int expo, coef, i = 1;
    while(1){
        if(Get_elem(lst,&expo,&coef, i)== 0)
            break;
        if(coef > 0)
            printf("+");
        printf("%d^%d \n", coef, expo);
        i++;
    }
    printf("\n");
}

void remove_elem(Lista *lst)
{
    int a;
    printf("DIGITE O COEFICIENTE DO TERMO QUE DESEJA REMOVER: ");
    scanf("%d", &a);
    if(remove_kesi(lst,a))
    printf("Elemento foi removido!! \n");
    else
    printf("Elemento nao esta na lista\n");
    return;
}


int main()
{

      Lista lst = cria_lista();

      int option;
      int expo;
      int coef;

      int r;
      int x;

      while(1){
    printf("\t\t\t+------------------------------------+\n");
    printf("\t\t\t| SELECIONE UMA OPCAO PARA INICIAR   |\n");
    printf("\t\t\t| 1 - criar um polinommio            |\n");
    printf("\t\t\t| 2 - Esvaziar o polinômio           |\n");
    printf("\t\t\t| 3 - inserir elemento               |\n");
    printf("\t\t\t| 4 - remover elemento               |\n");
    printf("\t\t\t| 5 - Calcular o resultado polinômio |\n");
    printf("\t\t\t| 6 - imprime polinomio              |\n");
    printf("\t\t\t| 7 - sair                           |\n");
    printf("\t\t\t+------------------------------------+\n");
    printf("DIGITE UM COMANDO: ");
        scanf("%d", &option);
        setbuf(stdin,NULL);
        switch(option){
    case 1:
        lst= cria_lista();
        printf("POLINOMIO CRIADO COM SUCESSO\n");
        break;

    case 2:
    if(esvazia_lista(&lst) == 0)
    {
       printf("A lista já esta vazia\n");
       break;
    }

    else
    {
        printf("A lista foi esvaziada\n");
        break;
    }

    case 3:
        printf("Qual número voce deseja inserir? ");
        scanf("%d", &coef);
        printf("Qual expoente voce deseja inserir? ");
        scanf("%d", &expo);

        insere_term(&lst, expo, coef);
        printf("Elemento ordenado\n");
        break;


    case 4:
            remove_elem(&lst);
            break;

    case 5:

        printf("Insira valor de X: ");
        scanf("%d", &x );
         r = calc_poli(&lst, x);
         printf("O valor total eh: %d\n", r);
         break;


    case 6:
        if(lista_vazia(lst)==1)
        {
            printf("A LISTA ESTÁ VAZIA!\n");
        }
        else
        {
            imprime_lista(lst);
        }
        break;


    case 7:
          printf("Programa encerrado até a proxima!\n");

          return 0;



     break;
      }


}
    return 0;

}

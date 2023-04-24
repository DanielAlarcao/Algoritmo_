#include<stdio.h>
int main(){

    int e = 0;
    int q = 0;
    int t = 0; 

    do{

        printf("Lista de compras:\n1 -> Abacaxi - 5,00 a unidade.\n2 -> Maca - 1,00 a unidade.\n3 -> Pera - 4,00 a unidade.\n4 - Finalizar compra\n>");
        scanf("%d", &e);


        switch(e){

            case 1:
                printf("Insira a quantidade de frutas:");
                scanf("%d", &q);
                t += 5 * q;
            break;
            case 2:
                printf("Insira a quantidade de frutas:");
                scanf("%d", &q);
                t += 1 * q;
            break;
            case 3:
                printf("Insira a quantidade de frutas:");
                scanf("%d", &q);
                t += 4 * q;
            break;

        }

    }while(e!=4);

    printf("Total de compras: %d", t);

    return 0;
}
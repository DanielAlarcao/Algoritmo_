#include<stdio.h>
int main(){

    signed int n1 = 0;
    signed int n2 = 1;
    int n3 = 0;

    printf("Digite um numero:");
    scanf("%d",&n3);
                
    printf("Sequencia de Fibonacci:\n");
    printf(" %i %i", n1, n2);

    for(int i = 0; i <= n3; i++){

        n1 += n2;
        n2 += n1;

        printf(" %i %i", n1, n2);

    }

    return 0; 
}
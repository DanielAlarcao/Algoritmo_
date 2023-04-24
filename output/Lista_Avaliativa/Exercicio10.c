#include<stdio.h>
int main(){

    int n1 = 0;
    int t = 0;

    printf("Insira 10 valores(Um de cada vez):");

    for(int i = 1; i<=10; i++){

        scanf("%d", &n1);
        t += n1;

    }

    printf("\n\nTotal:%d", t);

    return 0;
}
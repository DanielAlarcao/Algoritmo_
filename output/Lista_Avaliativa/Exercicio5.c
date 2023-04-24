#include<stdio.h>
int main(){

    int n1;
    printf("Digite um numero:");
    scanf("%d", &n1);
    printf("Os divisores do numeros %d sao:", n1);
    
    for(int i = 1; i<=n1; i++){
        if(i%2 ==0){
            printf("%d ", i);
        }
    }


    return 0;
}
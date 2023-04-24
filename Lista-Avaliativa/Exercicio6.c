#include<stdio.h>
int main(){

    int som = 0;

    for(int i=1;i<=1000;i++){

        if(i%3==0 || i%5==0){

            som+=i;
            printf("%d ", i);

        }

    }

    printf(" %d", som);

    return 0;
}
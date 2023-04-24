#include<stdio.h>
int main(){

    float x = 0;
    float y = 0;
    
    printf("Digite dois valores para X e Y:");
    scanf("%f %f", &x, &y);

    if(y == 0 && x == 0){
        printf("Origem");
    }else if(x == 0) {
        printf("Eixo Y");
    }else if(y == 0){
        printf("Eixo X");
    }else if(x>0 && y>0){
        printf("Q1");
    }else if(x<0 && y>0){
        printf("Q2");
    }else if(x<0 && y<0){
        printf("Q3");
    }else if(x>0 && y<0){
        printf("Q4");
    }
    
    return 0; 
}
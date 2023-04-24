#include<stdio.h>
int main(){

    int a;
     int b;
      int c;
       int d;
        int diferenca = 0;

         printf("Digite 4 valores:");
          scanf("%d %d %d %d", &a, &b, &c, &d);
           
           diferenca=(a*b-d*c);

            printf("Difirenca = (%d * %d - %d * %d)\n", a,b,c,d);
             printf("Diferenca = (%d)", diferenca);


    return 0;
}
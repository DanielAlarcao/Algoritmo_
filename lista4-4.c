#include <stdio.h>

int main()
{
    int n1,i;

    printf ("digite um numero inteiro:");
        scanf ("%d\n",&n1);

         for(i=10; i<=100 && n1> 0; i+=2){

            printf ("%d\n", i);

            n1--;
        
         }






    return 0;
}
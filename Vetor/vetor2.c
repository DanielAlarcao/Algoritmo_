#include <stdio.h>

    int main(){

        int n1[5], n2 [5], total [5],i;
        
          

          for (i=0;i<5;i++){;
            printf ("Digite o %d numero 1:\n", i);
             printf ("Digite o %d numero 2:\n", i);  

               scanf ("%d%d", &n1[i], &n2[i]);
              total[i] = n1[i] + n2[i];
               printf ("%2.d", total[i]);

          }

        
        return 0;
    }
    
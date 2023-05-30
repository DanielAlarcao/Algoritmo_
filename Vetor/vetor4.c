#include <stdio.h>
    int main(){

        int vetor [6], i, nBusca, posicao[6], contador =0;

        for (i=0;i<6;i++){
           
               vetor [i] = i*5;
              printf ("%d",&vetor[i]);

              
            }
             printf ("Digite o numero");
             scanf ("%d", &nBusca); 
              for (i=0;i<6;i++){
               if (nBusca == vetor[i]){
                posicao[contador] = i;
                 contador++;
                  
                  }
                    }
                 printf("Qauntidade de vezes que o numero %d aparece: %d", nBusca, contador);   
                  for (i=0;i<6;i++)
                   printf ("%d", posicao[i]);

             







        
        return 0;
    }
    
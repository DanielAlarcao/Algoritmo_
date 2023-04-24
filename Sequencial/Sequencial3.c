#include <stdio.h>
 int main(){

    int numeroInteiro; 
    int numeroReal;
    float numeroV;
    double numeroD;
    char umaLetra;
    char umTexto {100};
    
     scanf("%d", &numeroInteiro);
     scanf("%f", &numeroV);
     scanf ("%lf", &numeroD);
     scanf("%c", &umaLetra);
     scanf("%s", &umTexto);

    gets (umTexto);


    fgets (umTexto, 100, stdin);

     

     printf(" int: %3d\n" , numeroInteiro); 
     printf("float: %.3f\n" , numeroReal); 
     printf("double: %.1lf\n" , numeroV); 
     printf("char: %c\n" , numeroD); 
     printf("string: %s\n" , umTexto); 
     printf ("Endereco do Inteiro %x", &numeroInteiro);

     




    
    
    return 0;
 }
 
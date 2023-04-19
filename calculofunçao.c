#include <stdio.h>

//calcularforma C = K − F + 273.15
    float calcularForma (float K, float F){
            float C;
                C = K - F + 273.15;
                    return C;

}

int main(){

    float F, C, K;
        scanf ("%f", &K);
            scanf ("%f", &F);
                C = calcularForma (K,F);
                    printf ("%f", C);










    
    return 0;
}

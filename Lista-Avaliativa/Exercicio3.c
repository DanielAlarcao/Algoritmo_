#include <stdio.h>
#include <math.h>
int main(){

    int R;
    const float pi = 3.14159;

    printf("Insira o raio da esfera:");
    scanf("%d", &R);

    float volume = (4/3) * pi * pow(R, 3);
    float area = 4.0 * pi * pow(R, 3);

    printf("AREA:%.2f\nVOLUME:%.2f", area, volume); 


    return 0; 
}
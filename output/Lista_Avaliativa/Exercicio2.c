#include<stdio.h>
#include<math.h>
int main(){

    int x1;
     int x2;
      int y1;
       int y2;
        float Distancia;

         printf("Digite 4 valores que correspondem aos eixos, X1, X2, Y1, Y2: ");
          scanf("%d %d %d %d", &x1, &x2, &y1, &y2);

           Distancia = sqrt(pow(((float)x2-(float)x1),2)+pow(((float)y2-(float)y1),2)); 

             printf("A distancia sao de = %.4f", Distancia);


    return 0;
}

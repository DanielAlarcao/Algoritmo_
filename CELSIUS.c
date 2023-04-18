// De graus Celsius(C) para graus Fahrenheit(F):F = (9 ∗ C/5) + 32)
#include <stdio.h> 

    float celsusFahrenheit (float C){
        float F;
            F = (9 * C/5) + 32;
                return F;

    }
//De graus Fahrenheit (F) para graus Celsius (C): C = (F − 32) ∗ 5/9

    double FahrenheitCelsius (float F){
        double C;
            C = (F - 32) * 5/9;
                return C;
}
//De graus Celsius (C) para graus Kelvin (K): K = C + 273.15

    double celsiusKrlvin (float C){
        double K;
            K = C + 273.15;
                return K;

    }
    
        int main()
    {   
        
        float F, C, K;
            scanf ("%F", &C);
                F = celsusFahrenheit (C);
                    K = celsiusKrlvin (C);
                        scanf ("%f", &F); 
                            C = FahrenheitCelsius (F);

                

                    
                   














        return 0;
    }
    
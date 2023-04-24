int main(){

    int n1 = 0;
    int memoria = 0;

    printf("Digite os numeros:");
    scanf("%d",&n1);

    memoria = n1;

    while(n1 > 0){

        if(n1>memoria){

            memoria = n1;

        }

        scanf("%d", &n1);

    }

    printf("%d", memoria);

    return 0;
}
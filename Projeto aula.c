#include <stdio.h>   // para entrada e saida
#include <stdlib.h>   // funcoes relacionadas a alocacao de memoria 
#include <string.h>   // ultilizada para manipulacao de strings 
#include <time.h>      // usada para gerar valores aleatorios baseados no tempo 

#define MAX_USUARIOS 1000
#define TAM_EMAIL 50
#define TAM_NOME 100
#define TAM_ENDERECO 200


////////// Vetores para armazenar os dados//////////

int ids[MAX_USUARIOS];  // int números inteiros positivos e negativos
char nomeCompleto[MAX_USUARIOS][TAM_NOME]; // char armazenar caracteres
char email[MAX_USUARIOS][TAM_EMAIL];
char sexo[MAX_USUARIOS][TAM_NOME];
char endereco[MAX_USUARIOS][TAM_ENDERECO];
double  altura [MAX_USUARIOS];     //double precisão para armazenar grandes números com pontos
int vacina [MAX_USUARIOS];
int numUsuarios = 0; 

////////// Função para gerar um ID aleatório para cada usuário//////////////

int gerarIdAleatorio() {      // gera um ID para cada usuario. ela usa a funcao "rand" da srdlib.b
    return rand() % 10000 + 1;   // o operador % usado p limitar o valor entre 0 e 9999 e no final incrementado 1 p evitar IDS iguas a zero
}

//////////////// Função para cadastrar um novo usuário//////////////////

void cadastrarUsuario() {  // responsavel p solicitar e armazenar as info de unm novo usuario. primeiro é verificado se o limete maximo de usuario foi alcancado
    if (numUsuarios == MAX_USUARIOS) {
        printf("Limite de usuários alcançado!!\n");
        return;
    }

    int novoId = gerarIdAleatorio();  

    printf("Nome completo: ");
    scanf(" %[^\n]", nomeCompleto[numUsuarios]);

    printf("Email: ");
    scanf("%s", email[numUsuarios]);

    if (strchr(email[numUsuarios], '@') == NULL) { //// Verifica se o email contém o caractere '@'
        printf("Email inválido!! Certifique-se de incluir o caractere '@'.\n");
        return; // Encerra a função, pois o email é inválido
    }

    printf("Sexo (Feminino, Masculino ou Indiferente): ");
    scanf("%s", sexo[numUsuarios]);

    if (strcmp(sexo[numUsuarios], "Feminino") != 0 && strcmp(sexo[numUsuarios], "Masculino") != 0 &&   // Verifica se o sexo é válido
        strcmp(sexo[numUsuarios], "Indiferente") != 0) {
        printf("Sexo inválido!! Insere novamente Feminino, Masculino ou Indiferente.\n");
        return; // Encerra a função, pois o sexo é inválido
    }

    printf("Endereço: ");
    scanf(" %[^\n]", endereco[numUsuarios]);

    printf("Altura (em metros): ");
    scanf("%lf", & altura[numUsuarios]);

    if ( altura[numUsuarios] < 1.0 ||  altura[numUsuarios] > 2.0) {  // Verifica se a altura é válida
        printf("Altura inválida!! Digite um valor entre 1 e 2\n");
        return; // Encerra a função, pois a altura é inválida
    }

    printf("Vacina (1 para Sim, 0 para Não): ");
    scanf("%d", &vacina[numUsuarios]);

     ids[numUsuarios] = novoId; // Armazena o novo ID na lista de IDs
    numUsuarios++;   // Incrementa o número total de usuários

    printf("Usuário cadastrado com sucesso!!\n");
}

////////////////// Função para editar os dados de um usuário///////////////////

void editarUsuario() {   // inserir o email do user q desaja editar. em seguida é feita um buscar pelos user cadastrados, caso sao solicitadas novas info
    char email[TAM_EMAIL];  // sao realizadas novas validacoes p garantir q as novas info sejam validas 
    int i; // Declaração de uma variável de controle para o loop

    printf("Insere o email do usuário que deseja editar: ");
    scanf("%s", email);

    for (i = 0; i < numUsuarios; i++) {  // Loop para percorrer todos os usuários existentes
        if (strcmp(email[i], email) == 0) { // Compara o email fornecido pelo usuário com o email do usuário atual
            // Se os emails forem iguais, significa que o usuário foi encontrado
            
            printf("Insere o novo nome completo: ");
            scanf(" %[^\n]", nomeCompleto[i]);

            printf("Insere o novo email: ");
            scanf("%s", email[i]);

            if (strchr(email[i], '@') == NULL) {
                printf("Email inválido!! Certifique-se de incluir o caractere '@'.\n");
                return;
            }

            printf("Novo sexo (Feminino, Masculino ou Indiferente): ");
            scanf("%s", sexo[i]);

            if (strcmp(sexo[i], "Feminino") != 0 && strcmp(sexo[i], "Masculino") != 0 &&
                strcmp(sexo[i], "Indiferente") != 0) {
                printf("Sexo inválido! Insere novamente Feminino, Masculino ou Indiferente.\n");
                return;
            }

            printf("Novo endereço: ");
            scanf(" %[^\n]", endereco[i]);

            printf("Nova altura: ");
            scanf("%lf", &altura[i]);

            if (altura[i] < 1.0 || altura[i] > 2.0) {
                printf("Altura inválida!! Digite um valor entre 1 e 2 metros\n");
                return;
            }

            printf("Vacina (1 para Sim, 0 para Não): ");
            scanf("%d", &vacina[i]);

            printf("Usuário editado com sucesso!!\n");
            return;
        }
    }

    printf("Usuário não encontrado!!\n");
}

//////////////////////// Função para excluir um usuário//////////////////////////

void excluirUsuario() {  //  inserir o email do user q desaja excluir. em seguida é feita um buscar pelos user cadastrados
    char email[TAM_EMAIL]; // caso o user seja encontrado, todos os dados dos user seguintes sao movidos uma posicao p tras p preencher o espaco vazio do user excluido
    int i, j;

    printf("Insere o email do usuário que deseja excluir: ");
    scanf("%s", email);
 
    for (i = 0; i < numUsuarios; i++) { // Loop para percorrer todos os usuários existentes
        if (strcmp(email[i], email) == 0) { // Compara o email fornecido pelo usuário com o email do usuário atual
            // Se os emails forem iguais, significa que o usuário foi encontrado
            for (j = i; j < numUsuarios - 1; j++) {  // Deslocamento dos elementos subsequentes para preencher o espaço do usuário excluído
                 ids[j] =  ids[j + 1]; //Desloca o id do usuário
                strcpy(nomeCompleto[j], nomeCompleto[j + 1]); // desloca o nome completo
                strcpy(email[j], email[j + 1]); // desloca o email
                strcpy(sexo[j], sexo[j + 1]); // desloca o sexo
                strcpy(endereco[j], endereco[j + 1]); // desloca o entereco 
                altura[j] =  altura[j + 1]; // Desloca a altura do usuário
                vacina[j] = vacina[j + 1]; // Desloca a informação sobre a vacinação do usuário
            }
            numUsuarios--;  // Decrementa o número total de usuários, pois um usuário foi excluído
            printf("Usuário excluído com sucesso!!\n"); 
            return;
        }
    }

    printf("Usuário não encontrado!!\n");
}

////////////////////////// Função para buscar um usuário pelo email///////////////////////////

void buscarUsuarioPorEmail() { //inserir o email do user q desaja ser buscado. em seguida é feita um buscar pelos user cadastrados
    int i; // Declaração de variáveis de controle para os loops

    printf("Insere o email do usuário que deseja buscar: ");
    scanf("%s", email);

    for (i = 0; i < numUsuarios; i++) { // Loop para percorrer todos os usuários existentes
        if (strcmp(email[i], email) == 0) { // Compara o email fornecido pelo usuário com o email do usuário atual
            // Se os emails forem iguais, significa que o usuário foi encontrado
            printf("Usuário encontrado:\n");
            printf("ID: %d\n",  ids[i]);
            printf("Nome: %s\n", nomeCompleto[i]);
            printf("Email: %s\n", email[i]);
            printf("Sexo: %s\n", sexo[i]);
            printf("Endereço: %s\n", endereco[i]);
            printf("Altura: %.2lf\n",  altura[i]);
            printf("Vacina: %s\n", vacina[i] ? "Sim" : "Não");
            return;
        }
    }

    printf("Usuário não encontrado!\n");
}

// ///////////////////////Função para imprimir todos os usuários cadastrados////////////////////////

void imprimirUsuarios() {  // responsavel por exibir todos os user cadastrado. primeiro é verificado se n ha nenhum user cadastrado 
    int i;

    printf("Lista de Usuários:\n");

    for (i = 0; i < numUsuarios; i++) {  // Loop para percorrer todos os usuários existentes
        printf("ID: %d\n",  ids[i]);
        printf("Nome: %s\n", nomeCompleto[i]);
        printf("Email: %s\n", email[i]);
        printf("Sexo: %s\n", sexo[i]);
        printf("Endereço: %s\n", endereco[i]);
        printf("Altura: %.2lf\n",  altura[i]);
        printf("Vacina: %s\n\n", vacina[i] ? "Sim" : "Não");
    }
}

/////////////// backup ///////////

/* void fazerBackup() /*  // falta fazer 
    
///////////////// restauração dos dados a partir do backup////////////////////////

 /* void realizarRestauracao()  */  // falta fazer 
   

int main() { // Ela começa declarando uma variável de caractere opcao que será usada para armazenar a opção selecionada pelo usuário
    char opcao;

    srand(time(NULL));  // é chamada para inicializar a semente do gerador de números aleatórios.

    do {
        printf("Selecione uma opção:\n");
        printf("1. Criar usuário\n");
        printf("2. Atualizar dados de um usuário\n");
        printf("3. Deletar um usuário\n");
        printf("4. Buscar usuário por email\n");
        printf("5. Mostrar todos os usuários cadastrados\n");
        printf("6. Fazer backup \n");
        printf("7.  Fazer Restauração dos dados\n");
        printf("8. Sair\n");

        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                excluirUsuario();
                break;
            case '4':
                buscarUsuarioPorEmail();
                break;
            case '5':
                imprimirUsuarios();
                break;
            case '6':
                fazerBackup();
                break;
            case '7':
                realizarRestauracao();
                break;
            case '8':
                printf("Dados restaurados com sucesso\n");
                break;
            default:
                printf("Opção inválida! Digite uma opção válida.\n");
        }

        printf("\n");
    } while (opcao != '8');    //O loop continua até que o usuário selecione a opção 8 para sair do programa
                                
    return 0;   ////No final da função, é retornado o valor 0 para indicar que o programa foi executado com sucesso.
}
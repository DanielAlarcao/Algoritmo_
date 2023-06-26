 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USUARIOS 1000
#define TAM_EMAIL 50
#define TAM_NOME 100
#define TAM_ENDERECO 200


// Vetores para armazenar os dados

int ids[MAX_USUARIOS];
char nomeCompleto[MAX_USUARIOS][TAM_NOME];
char email[MAX_USUARIOS][TAM_EMAIL];
char sexo[MAX_USUARIOS][TAM_NOME];
char endereco[MAX_USUARIOS][TAM_ENDERECO];
double  altura [MAX_USUARIOS];
int vacina [MAX_USUARIOS];
int numUsuarios = 0;

// Função para gerar um ID aleatório para cada usuário

int gerarIdAleatorio() {
    return rand() % 10000 + 1;
}

// Função para cadastrar um novo usuário

void cadastrarUsuario() {
    if (numUsuarios == MAX_USUARIOS) {
        printf("Limite de usuários alcançado!!\n");
        return;
    }

    int novoId = gerarIdAleatorio();

    printf("Nome completo: ");
    scanf(" %[^\n]", nomeCompleto[numUsuarios]);

    printf("Email: ");
    scanf("%s", email[numUsuarios]);

    if (strchr(email[numUsuarios], '@') == NULL) {
        printf("Email inválido!! Certifique-se de incluir o caractere '@'.\n");
        return;
    }

    printf("Sexo (Feminino, Masculino ou Indiferente): ");
    scanf("%s", sexo[numUsuarios]);

    if (strcmp(sexo[numUsuarios], "Feminino") != 0 && strcmp(sexo[numUsuarios], "Masculino") != 0 &&
        strcmp(sexo[numUsuarios], "Indiferente") != 0) {
        printf("Sexo inválido!! Insere novamente Feminino, Masculino ou Indiferente.\n");
        return;
    }

    printf("Endereço: ");
    scanf(" %[^\n]", endereco[numUsuarios]);

    printf("Altura (em metros): ");
    scanf("%lf", & altura[numUsuarios]);

    if ( altura[numUsuarios] < 1.0 ||  altura[numUsuarios] > 2.0) {
        printf("Altura inválida!! Digite um valor entre 1 e 2\n");
        return;
    }

    printf("Vacina (1 para Sim, 0 para Não): ");
    scanf("%d", &vacina[numUsuarios]);

     ids[numUsuarios] = novoId;
    numUsuarios++;

    printf("Usuário cadastrado com sucesso!!\n");
}

// Função para editar os dados de um usuário

void editarUsuario() {
    char email[TAM_EMAIL];
    int i;

    printf("Insere o email do usuário que deseja editar: ");
    scanf("%s", email);

    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(email[i], email) == 0) {
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

// Função para excluir um usuário

void excluirUsuario() {
    char email[TAM_EMAIL];
    int i, j;

    printf("Insere o email do usuário que deseja excluir: ");
    scanf("%s", email);

    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(email[i], email) == 0) {
            for (j = i; j < numUsuarios - 1; j++) {
                 ids[j] =  ids[j + 1];
                strcpy(nomeCompleto[j], nomeCompleto[j + 1]);
                strcpy(email[j], email[j + 1]);
                strcpy(sexo[j], sexo[j + 1]);
                strcpy(endereco[j], endereco[j + 1]);
                altura[j] =  altura[j + 1];
                vacina[j] = vacina[j + 1];
            }
            numUsuarios--;
            printf("Usuário excluído com sucesso!!\n");
            return;
        }
    }

    printf("Usuário não encontrado!!\n");
}

// Função para buscar um usuário pelo email

void buscarUsuarioPorEmail() {
    char email[TAM_EMAIL];
    int i;

    printf("Insere o email do usuário que deseja buscar: ");
    scanf("%s", email);

    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(email[i], email) == 0) {
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

// Função para imprimir todos os usuários cadastrados

void imprimirUsuarios() {
    int i;

    printf("Lista de Usuários:\n");

    for (i = 0; i < numUsuarios; i++) {
        printf("ID: %d\n",  ids[i]);
        printf("Nome: %s\n", nomeCompleto[i]);
        printf("Email: %s\n", email[i]);
        printf("Sexo: %s\n", sexo[i]);
        printf("Endereço: %s\n", endereco[i]);
        printf("Altura: %.2lf\n",  altura[i]);
        printf("Vacina: %s\n\n", vacina[i] ? "Sim" : "Não");
    }
}

// Função para fazer backup dos usuários cadastrados

void fazerBackup() {
    FILE *arquivo;
    int i;

    arquivo = fopen("backup.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de backup!\n");
        return;
    }

    for (i = 0; i < numUsuarios; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%s;%.2lf;%d\n",  ids[i], nomeCompleto[i], email[i],
                sexo[i], endereco[i],  altura[i], vacina[i]);
    }

    fclose(arquivo);

    printf("Backup realizado com sucesso!\n");
}

// Função para realizar a restauração dos dados a partir do backup

void realizarRestauracao() {
    FILE *arquivo;
    char linha[500];
    int i = 0;

    arquivo = fopen("backup.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de backup!\n");
        return;
    }

    numUsuarios = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%d;%[^;];%[^;];%[^;];%[^;];%lf;%d", & ids[i], nomeCompleto[i], email[i],
               sexo[i], endereco[i], &altura[i], &vacina[i]);
        i++;
        numUsuarios++;
    }

    fclose(arquivo);

    printf("Restauração concluída com sucesso! Foram recuperados %d usuários.\n", numUsuarios);
}

int main() {
    char opcao;

    srand(time(NULL));

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
    } while (opcao != '8');

    return 0;
}
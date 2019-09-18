#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CONSTANTES
#define MAX 500
#define MAX1 1000

//ESTRUTURAS
struct agend
{
    int id[MAX];
    char nome[MAX][MAX1];
    char numero[MAX][MAX1];

} Agenda;

//FUNCOES
int deletar();
int lista();
int inserir();
int sair();


//CODIGO PRINCIPAL
int main()
{

    int op;

    while(1) //Estrutura de Repeticao para escolha de Operacao
	{
        printf("\n-------AGENDA-------\n");
        printf("ESCOLHA UMA OPCAO\n\n");
        printf("[1] Inserir\n");
        printf("[2] Listar\n");
        printf("[3] Deletar\n");
        printf("[4] Sair\n");

        printf("\n[*] ESCOLHA UMA OPCAO... ");
        scanf("%d", &op);
        printf("\n");

        switch(op) //Estrutura de escolha de Operacao
		{

            case 1:
                inserir();
                break;

            case 2 :
                lista();
                break;

            case 3:
                deletar();
                break;

            case 4:
                sair();

            default :
            printf("[!] TEMOS UM PROBLEMA\n");
            exit(1);

        }
    }

    return 0;
}

//FUNCOES
int deletar()
{
	lista();
    int tmpid; //identificacao temporaria de contatos

    printf("\n\n[*] Deletar ID: ");
    scanf("\n%d", &tmpid);

    for(int i=0;i < MAX;i++)
	{

        if(Agenda.id[i] == tmpid)
		{

            printf("\n[!] Deletando...\n");
            Agenda.id[i] = '\0'; //Transformando id da estrutura em NULL
            strcpy(Agenda.nome[i], ""); //Faz a copia da String NULL para o os elementos da estrutura
            strcpy(Agenda.numero[i], ""); //Faz a copia da String NULL para o os elementos da estrutura
            break;

        }

    }
    lista(); //Chama a lista novamente para deixar o terminal mais visivelmente agradavel
    return 0;

}


int lista()
{
	system("cls");
    printf("\n\n[*] Listando Resultados...\n\n");
    for(int i=0;i < MAX;i++)
	{
        //So ira listar se a comparaçao entre nome e NULL forem diferentes de 0 para evitar loop
        if(strcmp(Agenda.nome[i], "") !=0)
		{
        	printf("----------------------------------");
            printf("\n| ID : %d\n", Agenda.id[i]);
            printf("| NOME : %s\n", Agenda.nome[i]);
            printf("| TELEFONE: %s\n", Agenda.numero[i]);

        }

    }

    return 0;
}


int inserir()
{

    char nome_inserir[MAX];
    char numero_inserir[MAX];

    printf("NOME: ");
    scanf("\n%499[^\n]s", nome_inserir); //Essa configuracao do scanf permite que o usuario digite espaços
    printf("TELEFONE: ");                        //em branco como string, onde [^/n] para a captura quando se tecla enter
    scanf("\n%499[^\n]s", numero_inserir);

    for(int i=0; i < MAX;i++)
	{

        if(strcmp(Agenda.nome[i], "") ==0)
		{
            Agenda.id[i] = i;
            strcpy(Agenda.nome[i], nome_inserir); //Faz a copia da String NULL para o os elementos da estrutura
            strcpy(Agenda.numero[i], numero_inserir); //Faz a copia da String NULL para o os elementos da estrutura
            break;
        }

    }


    return 0;
}

int sair()
{

    system("cls");
    printf("\n\n");
    printf("\n\n                   ((...))\n                   ( O O )\n                    \\   /\n                    (`_`)\n\n"); //ASCII ART COW
    printf("\n\nDEVELOPED BY: Pedro Cunha\n");
    printf("Bloco II Ciencia da Computacao\n");
    printf("UESPI: Campus Piripiri\n\n\n\n");
    exit(1);

}

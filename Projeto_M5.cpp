#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); // respons�vel por copiar os valores
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // w = escrever 
	fprintf(file, cpf); // salva o valor da variav�l
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a");// a = atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system ("pause");
	
	
}

int consulta ()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r = ler o arquivo
	
	if(file == NULL) // valida��o caso o arquivo n�o seja encontrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!./n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
    char cpf[40];// char funciona melhor para gerenciamento de strings
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;// Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	
	 setlocale(LC_ALL,"Portuguese");//Definindo linguagens
	 system("cls");
	 printf("****Cart�rio da EBAC****\n\n");//inicio menu
	 printf("Esse software � de livre uso dos alunos\n");
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1-Registrar nomes\n\n");
	 printf("\t2-Consultar nomes\n\n");
	 printf("\t3-Deletar nomes\n\n");
	 printf("Op��o:");
	
	
	 scanf("%d",&opcao);//armazenando as escolhas do usu�rio
		
	 system("cls"); //cls - comando de limpar a tela
	
	 switch(opcao)//inicio da sele��o
	 {
	 	case 1:
	 	registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel\n");
		system("pause");
	 
       }
     }
	

}

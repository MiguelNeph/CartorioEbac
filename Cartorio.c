#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int registro(){
	setlocale(LC_ALL, "Portuguese");
	char archivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser catastrado: \n");
	scanf ("%s", cpf);
	
	strcpy(archivo, cpf);
	
	FILE *file;
	file=fopen(archivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file=fopen(archivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o novo nome: \n");
	scanf("%s", nome);
	
	file=fopen(archivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(archivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: \n");
	scanf("%s", sobrenome);
	
	file=fopen(archivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(archivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: \n");
	scanf("%s", cargo);
	
	file=fopen(archivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta(){
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[40];
	printf("Digite o CPF a consultar: \n");
	scanf("%s", cpf);
	
	FILE*file;
	file=fopen(cpf, "r");
	
	if(file==NULL){
		printf("Nao foi possivel abrir o archivo. \n");
	} 
	while(fgets(conteudo, 200, file)!=NULL){
		printf("Essas sao as informaçoes do usuario: \n");
		printf("%s", conteudo);
		printf("\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite a CPF a deletar: \n");
	scanf("%s", cpf);

	FILE*file;
	file=fopen(cpf, "r");
	if(file!=NULL){     //Para mim fica mais intuitivo com o sistema if/else
		fclose(file);  //Igual que os outros alunos, encontrei que é necessario fechar o archivo antes de deletar
		remove(cpf);
		printf("O usuario foi deletado com suceso! \n");  //Acho interessante para o user ter uma confirmaçao da deleçao
	}
	else{
		printf("O usuario nao foi encontrado no sistema. \n");
		fclose(file);
	}
	
	system("pause");
}
int main (){
	
	
	
	setlocale(LC_ALL, "Portuguese");
	int Opcao=0;
	int laco=1;
	
	for(laco=1; laco=1;){
		system("cls");
		printf("###  CARTÓRIO DA EBAC  ### \n\n");
		printf("\t Escolha a opçao desejada do menu: \n\n");
		printf("\t 1 - Registrar nomes. \n");
		printf("\t 2 - Consultar nomes. \n");
		printf("\t 3 - Deletar nomes. \n");
		printf("\t 4 - Sair do sistema. \n\n");
		printf("\t Opçao: ");
		scanf("%d", &Opcao);
		system("cls");
		
		switch(Opcao){
			case 1:
			printf("Escolheu registrar nomes. \n");
			registro();
			break;
			case 2:
			printf("Escoclheu consultar nomes. \n");
			consulta();
			break;
			case 3:
			printf("Escoclheu deletar nomes. \n");
			deletar();
			break;
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
			default:
			printf("Opçao nao disponivel. \n");
			system("pause");
			break;
			}
		
	}
} 

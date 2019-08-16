#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct agenda{
	char nome[40],email[40];
	int idade, telefone;	
}c[1000];

int cont=0,i=0,j=0,r=0,k=0;

void inserir(){
	system("cls");
	char resp;
	
	do{
		printf("\nInsira o nome do contato:\n");
		fflush(stdin);
		gets (c[cont].nome); 
		printf("\nInsira a idade do contato:\n");
		scanf("%d",&c[cont].idade);
		printf("\nInsira o email do contato:\n");
		scanf("%s",&c[cont].email);
		printf("\nInsira o telefone do contato:\n");
		scanf("%d",&c[cont].telefone);
	
		printf("\nDeseja continuar: (S ou s) ou (N ou n)\n\n");
		resp= getche();
	cont++;
	} while(resp =='S'or resp =='s');
}
void imprimir(){
	system("cls");
	printf("\t\tLista de Cadastrados:\n\n");
	for(i=0;i<cont;i++){
		printf("\nNome: %s\n",c[i].nome);
		printf("Idade: %d\n",c[i].idade);
		printf("Email: %s\n",c[i].email);
		printf("Telefone: %d\n",c[i].telefone);
		printf("\n");
	}
	system("pause");
}
void consulta(){

	system("cls");
	char nomea[40];
	
	printf("\nInforme a nome da pessoa que deseja consultar\n");
	fflush(stdin);
	gets(nomea);	
		for(j=0;j<cont;j++){
			if(strcmp(nomea,c[j].nome) == 0){
				printf("\nNome: %s\n",c[j].nome);
				printf("Idade: %d\n",c[j].idade);
				printf("Email: %s\n",c[j].email);
				printf("Telefone: %d\n",c[j].telefone);
				printf("\n");
			}
		}
	system("pause");
}
void excluir(){
	system("cls");

	char exclui[40];
	
	printf("\nInforme o nome do contato que deseja remover: ");
	fflush(stdin);
	gets(exclui);
	
	for(r=0;r<i;r++){
		
		if(strcmp(exclui,c[cont].nome)){
			
			strcpy(c[r].nome,c[r+1].nome);
			c[r].idade= c[r+1].idade;
			strcpy(c[r].email,c[r+1].email);
			c[r].telefone= c[r+1].telefone;	
			cont--;
		}
	}
}
void editar(){

	system("cls");
	char n[40],n_edite[40],e_edite[40];
	int i_edite,t_edite,e;
	
	printf("\nInforme o nome do contato que deseja editar: \n");
	fflush(stdin);
	gets(n);
	
	printf("\n\t\tEdicao\n");
	while(k<cont){
		if(strcmp(n,c[k].nome) == 0){
			printf("\nOque deseja alterar :\n1-Nome\n2-Idade\n3-Email\n4-Telefone\n");
			scanf("%d",&e);
			switch(e)
			{
				case 1:
					printf("\nInforme o nome que deseja alterar: ");
					fflush(stdin);
					gets(n_edite);
					strcpy(c[k].nome,n_edite);
					break;
				case 2:
					printf("\nInforme a idade que deseja alterar: ");
					scanf("%d",&i_edite);
					c[k].idade= i_edite;
					break;
				case 3:
					printf("\nInforme o email a alterar: ");
					fflush(stdin);
					gets(e_edite);
					strcpy(c[k].email,e_edite);
					break;
				case 4:
					printf("\nInforme o telefone a alterar: ");
					scanf("%d",&t_edite);
					c[k].telefone= t_edite;
					break;
				default :
					printf("\nNao exite!");
					break;				
			}
			
		}
		k++;
	}
	
}
void menu(){
	system("cls");
	int e,a;
	printf("\tBEM VINDO AO MENU\n\n");
	printf("\nNumero de cadastrados: %d\n",cont);
	printf("\nEscolha o que deseja fazer : \n1- Inserir\n2- Imprimir\n3- Consultar\n4- Excluir\n5- Editar\n6- Sair\n");
	scanf("%d",&e);

	switch(e)
		{
			case 1:
				inserir();
				break;
			case 2:
				imprimir();
				break;
			case 3:
				consulta();
				break;
			case 4:
				excluir();
				break;
			case 5:
				editar();
				break;			
			case 6:
				system("cls");
				printf("\n\n\t\tADEUS, Pressione qualquer tecla para sair.\n\n");
				exit(0);
				break;	
			default:
				printf("\nfuncao impossivel\n");		
				break;			
	}
	}

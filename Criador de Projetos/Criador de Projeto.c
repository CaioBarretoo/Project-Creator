#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max 200


typedef struct dados{
	int cod;
	char gerente[50];
	char titulo[30];
	char descr[50];
	char dat[12];
	char cliente[50];
	char endereco[50];
	char datp[12];
	
	int status;
}base_projetos;


void Cadastrar_Projeto(base_projetos cadastro[max]);
void Buscar_Projeto(base_projetos cadastro[max]);
void Listar_Projeto(base_projetos cadastro[max]);
void Listar_Todos(base_projetos cadastro[max]);
int pos = 0;

int main(){
	setlocale(LC_ALL, "");
	base_projetos cadastro [max];
	
	int opc;
	
	system("cls");
	do{
		system("cls");
		printf("+-----------------------------------------------------------+\n");
		printf("|                                                           |\n");
		printf("|                   CRIADOR DE PROJETOS                     |\n");
		printf("|                                                        .v1|");
		printf("\n+-----------------------------------------------------------+\n\n");
		printf("+---------------------+");
		printf("\n|1)-CADASTRAR PROJETO |\n");
		printf("+---------------------+");
		printf("\n|2)-LISTAR POR CÓDIGO |\n");
		printf("+---------------------+");
		printf("\n|3)-LISTAR POR STATUS |\n");
		printf("+---------------------+");
		printf("\n|4)-LISTAR TODOS      |\n");
		printf("+---------------------+");
		printf("\n|5)-SAIR              |\n");
		printf(" ---------------------+\n");
		printf("\n+-----------------------------+");
		printf("\n|  ESCOLHA UMA OPÇÃO DO MENU  |");
		printf("\n+-----------------------------+\n");
		printf("R:");
		scanf("%d", &opc);
		fflush(stdin);
		
		switch(opc){
			case 1:
				system("cls");
				Cadastrar_Projeto(cadastro);
				break;
			case 2:
				system("cls");
				if(pos == 0){
					printf("\nNENHUM PROJETO CADASTRADO AINDA\n");
					system("Pause");
				}else
				Buscar_Projeto(cadastro);
				break;
			case 3:
				system("cls");
				if(pos == 0){
					printf("\nNENHUM PROJETO CADASTRADO AINDA\n");
					system("Pause");
				}else
				Listar_Projeto(cadastro);
				break;
			case 4:
				system("cls");
				if(pos == 0){
					printf("\nNENHUM PROJETO CADASTRADO AINDA\n");
					system("Pause");
				}else
					Listar_Todos(cadastro);
				break;
			case 5:
				system("cls");
				printf("             SAINDO DO APLICATIVO....\n");
				printf("\n\n\+--------------------------------------------+");
				printf("\n| MUITO OBRIGADO POR UTILIZAR, VOLTE SEMPRE! |\n");
				printf("|                                            |\n");
				printf("|             by:CAIO BARRETO                |\n");
				printf("+--------------------------------------------+\n\n");
				system("pause");
				break;
			default:
				printf("\nESCOLHA ERRADA!!!\n");
				system("pause");
				
		}
	}while(opc != 5);
	return 0;
}

void Cadastrar_Projeto(base_projetos cadastro[max]){
	setlocale(LC_ALL, "");
	printf("+-----------------------------------+\n");
	printf("| BEM VINDO AO CADASTRO DE PROJETOS |");
	printf("\n+-----------------------------------+\n");
	char resp = 's';
	int x, resps = 0;
	
	while((resp == 's' || resp == 'S') && pos <= max){
		printf("\n+------------+\n");
		printf("|  CÓDIGO:%d  |", pos);
		cadastro[pos].cod = pos;
		printf("\n+------------+\n");
		printf("\n\nINFORME O GERENTE DE PROJETOS RESPONSÁVEL PELO PROJETO:\n");
		fflush(stdin);
		gets(cadastro[pos].gerente);
		printf("\nINFORME O TÍTULO DO PROJETO:\n");
		fflush(stdin);
		gets(cadastro[pos].titulo);
		printf("\nINFORME A DESCRIÇÃO DO PROJETO:\n");
		fflush(stdin);
		gets(cadastro[pos].descr);
		printf("\nINFORME A DATA DE INICIALIZAÇÃO XX/XX/XXXX:\n");
		fflush(stdin);
		scanf("%s",cadastro[pos].dat);
		printf("\nINFORME O NOME DO CLIENTE:\n");
		fflush(stdin);
		gets(cadastro[pos].cliente);
		printf("\nINFORME O ENDEREÇO DO CLIENTE:\n");
		gets(cadastro[pos].endereco);
		printf("\nINFORME A DATA PREVISTA PARA TÉRMINO XX/XX/XXXX:\n");
		fflush(stdin);
		scanf("%s",cadastro[pos].datp);
		do{
			if (resps == -1)
				printf("\nOPÇAO INVÁLIDA:\n");
			printf("\nINFORME O STATUS DO PROJETO:\n");
			printf("[1] - A FAZER FAZENDO [2] - FAZENDO [3] CONCLUÍDO:\nR: ");
			x = scanf(" %d", &resps); getchar();
			fflush(stdin);
			if(x == 0)
				resps = -1;
			else if(resps != 1 && resps != 2 && resps != 3)
				resps = -1;
			else
				cadastro[pos].status = resps;
		}while(resps != 1 && resps != 2 && resps != 3);
			
	pos++;
	if(pos < max){
		printf("\n\nDESEJA CADASTRAR NOVO PROJETO? [s] SIM [n] NÃO\n");
		printf("R:");
		fflush(stdin);
		scanf("%c", &resp);
		fflush(stdin);
		system("cls");
	}else{
		printf("\nSUA BASE DE DADOS JÁ CHEGOU AO LIMITE!!!\n");
		resp = 'n';
	}
}
}


void Buscar_Projeto(base_projetos cadastro[max]){
	setlocale(LC_ALL, "");
	int cod, achou;
	printf("+--------------------------------------+");
	printf("\n|            BUSCAR PROJETO            |");
	printf("\n+--------------------------------------+");
	printf("\n\nDIGÍTE O CÓDIGO DO PROJETO:\n");
	scanf("%d", &cod);
	fflush(stdin);
	achou = 0;
	int j = 0;
	while((achou == 0) && (j <= pos)){
		if(cod == cadastro[j].cod){
			printf("\n+------------+\n");
			printf("|  CÓDIGO:%d  |",cadastro[j].cod);
			printf("\n+------------+\n");
			printf("\nGERENTE DE PROJETOS RESPONSÁVEL PELO PROJETO: %s \n",cadastro[j].gerente);
			printf("\nTÍTULO: %s \n",cadastro[j].titulo);
			printf("\nDESCRIÇÃO DO PROJETO: %s \n",cadastro[j].descr);
			printf("\nDATA DE INICIALIZAÇÃO: %s \n",cadastro[j].dat);
			printf("\nNOME DO CLIENTE: %s \n",cadastro[j].cliente);
			printf("\nENDEREÇO DO CLIENTE: %s \n",cadastro[j].endereco);
			printf("\nDATA PREVISTA PARA TÉRMINO XX/XX/XXXX: %s\n", cadastro[j].datp);
			printf("\nSTATUS: ");
			
			if(cadastro[j].status == 1){
			printf("A FAZER FAZENDO\n\n\n");	
		}
			
			if(cadastro[j].status == 2){
			printf("FAZENDO\n\n\n");	
			}
			
			if(cadastro[j].status == 3){
			printf("CONCLUÍDO\n\n\n");	
			}
			
		
		
			achou = 1;
			system("pause");
		}
		j++;
	}
		if(achou == 0){
			printf("\nREGISTRO NÃO ESCONTRADO COM O CÓDIGO %d \n", cod);
			system("pause");
		}
}

void Listar_Projeto(base_projetos cadastro[max]){
	setlocale(LC_ALL, "");
	int BuscaStatus,achou,i;	
	printf("+----------------------------------------+");
	printf("\n|            LISTAR PROJETOS             |");
	printf("\n+----------------------------------------+\n\n");
	printf("QUAL DESEJA LISTAR?");
	printf("\n[1] A FAZER FAZENDO [2] FAZENDO [3] CONCLUÍDO\n");
	scanf("%d", &BuscaStatus);
	fflush(stdin);
	achou = 0;
	i = 0;
	while((achou == 0) && (i <= pos)){
		if(BuscaStatus == cadastro[i].status){
			printf("\n+------------+\n");
			printf("|  CÓDIGO:%d  |",cadastro[i].cod);
			printf("\n+------------+\n");
			printf("GERENTE DE PROJETOS RESPONSÁVEL PELO PROJETO: %s \nTÍTULO: %s \nDESCRIÇÃO: %s \nDATA: %s \nNOME DO CLIENTE: %s \nENDEREÇO DO CLIENTE: %s \nDATA PREVISTA PARA TÉRMINO: %s \n",cadastro[i].gerente,cadastro[i].titulo,cadastro[i].descr,cadastro[i].dat,cadastro[i].cliente,cadastro[i].endereco,cadastro[i].datp);
			achou = 0;
			switch(BuscaStatus){
				case 1:
					printf("STATUS: (A FAZER FAZENDO)\n\n");
				break;
				case 2:
					printf("STATUS: (FAZENDO)\n\n");
				break;
				case 3:
					printf("STATUS: (CONCLUÍDO)\n\n");
				break;
			}
		
		}
		i++;	
	}
		if(achou == 0 ){
			printf("\n\nNÃO EXISTE MAIS REGISTROS COM STATUS %d \n\n", BuscaStatus);
			system("Pause");
		}
		

}

void Listar_Todos(base_projetos cadastro[max]){
	setlocale(LC_ALL, "");
	int k,achou;
	printf("+----------------------------------------------+");
	printf("\n|            LISTAR TODOS PROJETOS             |");
	printf("\n+----------------------------------------------+\n\n");
	achou = 0;
	k = NULL;
	while((achou == 0) && (k < pos)){	
			printf("\n+------------+\n");
			printf("|  CÓDIGO:%d  |",cadastro[k].cod);
			printf("\n+------------+\n");
			printf("GERENTE DE PROJETOS RESPONSÁVEL PELO PROJETO: %s \nTÍTULO: %s \nDESCRIÇÃO: %s \nDATA: %s \nNOME DO CLIENTE: %s \nENDEREÇO DO CLIENTE: %s \nDATA PREVISTA PARA TERMINO: %s \n",cadastro[k].gerente,cadastro[k].titulo,cadastro[k].descr,cadastro[k].dat,cadastro[k].cliente,cadastro[k].endereco,cadastro[k].datp);
			switch(cadastro[k].status){
				case 1:
					printf("STATUS: (A FAZER FAZENDO)\n\n");
				break;
				case 2:
					printf("STATUS: (FAZENDO)\n\n");
				break;
				case 3:
					printf("STATUS: (CONCLUÍDO)\n\n");
				break;
			}
k = k + 1;
	}
		if(achou == 0 ){
			printf("\n\nNÃO EXISTE MAIS REGISTROS\n\n");
			system("Pause");
}
}


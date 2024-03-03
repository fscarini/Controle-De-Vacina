#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void clear(){
    system("@cls||clear");
    fflush(stdin);
}

struct dados{
	int codigo;
	char nome[100];
	char cpf[16];
	char vacina[22];
	char data[16];
	char numlote[100];
};

void CadastrarVac(char a[100], char b[16], char c[22], char x[16], char y[100]){
	printf("Digite o nome do paciente: \n");
	gets(a);
	printf("\n");
	fflush(stdin);
	printf("Digite o CPF do paciente: \n");
	gets(b);
	printf("\n");
	fflush(stdin);
	printf("Digite a data em que a vacina foi aplicada: \n");
	gets(c);
	printf("\n");
	fflush(stdin);
	printf("Digite o tipo de vacina: \n");
	gets(x);
	printf("\n");
	fflush(stdin);
	printf("Digite número de lote da vacina: \n");
	gets(y);
	printf("\n");
	fflush(stdin);	
}

void Listagem(int cod, char a[100], char b[16], char c[22], char x[16], char y[100]){
	printf("\n");
	printf("Código do paciente: %d \n", cod);
	printf("Nome do paciente: %s \n", a);
	printf("CPF: %s \n", b);
	printf("Data: %s \n", c);
	printf("Vacina: %s \n", x);
	printf("N�mero do lote: %s \n", y);
	printf("\n");

}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int i;
	int p;
	int valor;
	char cpfDig[16];
	struct dados dNum[99];
	
	printf("Olá, seja bem vindo ao sistema de dados de vacinas de São Paulo, como posso ajudar?\n");
	while(valor != 4){
		printf("\n");
		printf("1 - Cadastrar Vacina \n2 - Listar Aplicações \n3 - Consultar por CPF \n4 - Sair\n");
		scanf("%d", &valor);
		fflush(stdin);
		if(valor > 4){
			printf("Digite um número válido e tente novamente. \n");
		}
		
		switch(valor){
			case 1:
				printf("Quantos pacientes você deseja cadastrar?\n");
				scanf("%d", &p);
				for(i = 0; i < p; i++){
					clear();
					dNum[i].codigo = (i+1);
					fflush(stdin);
					CadastrarVac(dNum[i].nome, dNum[i].cpf, dNum[i].data, dNum[i].vacina, dNum[i].numlote);
					clear();
					fflush(stdin);
				}
				clear();
				printf("Listagem Finalizada! \n");
			break;
			
			case 2:
				clear();
				printf("Listagem de todos os pacientes \n");
				for(i = 0; i < p; i++){
				Listagem(dNum[i].codigo, dNum[i].nome, dNum[i].cpf, dNum[i].data, dNum[i].vacina, dNum[i].numlote);
				};
			break;
			
			case 3:
				clear();
   				fflush(stdin);
   				printf("Consulta por CPF \n");
   				printf("Digite o CPF do paciente. \n");
   				gets(cpfDig);
   				fflush(stdin);
   				for(i = 0; i < p; i++){
					if(strcmp(dNum[i].cpf, cpfDig) == 0){
	   					printf("\n");
	   					printf("CPF Encontrado \n");
	   					printf("Código: %d \n",i+1);
	   					printf("Nome: %s \n",dNum[i].nome);
	   					printf("Cpf: %s \n",dNum[i].cpf);
	   					printf("Vacina: %s \n",dNum[i].vacina);
	   					printf("Data :%s \n",dNum[i].data);
	   					printf("Lote: %s \n",dNum[i].numlote);
	   					fflush(stdin);
						break;
						}
					
				}		if(strcmp(dNum[i].cpf, cpfDig) != 0){
	   						printf("\n");
	   						printf("CPF não encontrado, tente novamente. \n");
						}	
   			break;
				
			default:
			;
		}
	
	

		}
		return 0;
	}
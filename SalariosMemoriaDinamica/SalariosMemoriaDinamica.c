/* Desenvolva um código em C de um programa que apresente o seguinte menu:
1. Adicionar salário.
2. Imprimir salários.
3. Imprimir soma dos salários.
4. Sair.
Caso a opção (1) seja escolhida, o usuário irá informar um salário que será armazenado
pelo programa. Caso a opção (2) seja escolhida, todos os salários já informados deverão
ser impressos, 1 por 1. Caso a opção (3) seja escolhida, a somatória de todos os salários
informados deverá ser impressa na tela */

#include <stdio.h>
#include <stdlib.h>

int menu(){
	
	int opcao;
	
	printf("\n1 - Adicionar salario.");
	printf("\n2 - Imprimir salarios.");
	printf("\n3 - Imprimir soma dos salarios.");
	printf("\n4 - Sair.");
	
	printf("\n\nEscolha uma opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}

int main(){
	
	int opcao, n = 0;
	float* s;
	float soma;
	
	do{
		
		opcao = menu();
		
		switch(opcao){
			
			case 1:
				
				n++;
				
				if(n == 1)
					s = (float*) malloc(n * sizeof(float));
				else
					s = realloc(s, n * sizeof(float));

				printf("\nDigite o salario %d: ", n);
				
				scanf("%f", &s[n-1]);
				
				break;
			
			case 2:
				
				printf("\n");
				
				for(int i = 0; i < n; i++)
					printf("\nSalario %d = %.2f\n", i+1, s[i]);
				
				break;
			
			case 3:
				
				soma = 0;
				
				for(int i = 0; i < n; i++)
					soma += s[i];
				
				printf("\nA soma dos salarios e %.2f\n", soma);
				
				break;
		}
		
	}while(opcao != 4);
	
	free(s);
	
	return 0;
}
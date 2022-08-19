/* Desenvolva um programa em C que apresenta um menu na tela com 4 opções: (1)
Informe o vetor; (2) Somatoria dos primos; (3) Somatoria dos pares; (4) Sair. A partir
daí o usuário irá escolher a opção desejada. Caso a opção (1) seja escolhida, o usuário
deverá informar 10 números que irão compor o vetor. Caso a opção (2) seja escolhida,
inicialmente o programa deve verificar se os valores no vetor já foram informados e
caso já tenham sido, imprimir a somatória de todos os números primos que compõem
o vetor. Caso contrário, o programa irá informar ao usuário que o vetor ainda não foi
definido. Depois disso, o programa deve retornar ao menu. Caso a opção (3) seja
escolhida, de maneira similar, o programa deverá imprimir na tela a somatória dos
números pares do vetor ou informar que o vetor ainda não foi definido e então retornar
ao menu. Finalmente, caso a opção (4) seja escolhida, o programa deve encerrar.
Utilize funções e procedimentos para decompor e simplificar o seu programa ao
máximo. */ 

#include <stdio.h>
#include <stdbool.h>

#define TAMV 10 // Define o tamanho do vetor

/**
 * @brief Função que exibe o menu e retorna a opção
 */
int menu(){
	
	int opcao;
	
	printf("\n1 - Informe o vetor\n");
	printf("2 - Somatoria dos primos\n");
	printf("3 - Somatoria dos pares\n");
	printf("4 - Sair\n\n");
		
	printf("Escolha uma opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}

/**
 * @brief Função que recebe o vetor e inicializa ele com os valores inseridos pelo usuário
 **/
void RecebeVetor(int v[TAMV]){
	
	printf("\n");
	
	for(int i = 0; i < TAMV; i++){
		printf("Digite o %d elemento de V: ", i);
		scanf("%d", &v[i]);
	}
}

/**
 * @brief Função que soma os primos do vetor
 */
int SomaPrimo(int v[TAMV]){
	
	int soma = 0, primo;
	
	for(int i = 0; i < TAMV; i++){
		
		primo = 0;
		
		for(int j = 1; j <= v[i]; j++){
			if(v[i] % j == 0)
				primo++;
		}
		
		if(primo == 2)
				soma += v[i];
	}
	
	return soma;
}

/**
 * @brief Função que soma os pares do vetor
 */
int SomaPar(int v[TAMV]){
	
	int soma = 0;
	
	for(int i = 0; i < TAMV; i++)
		if(v[i] % 2 == 0)
			soma += v[i];
	
	return soma;
}

int main(){
	
	int v[TAMV];
	int opcao;
	bool vetor = false;
	
	do{
		opcao = menu();
		
		if(opcao == 1){
			RecebeVetor(v);
			
			vetor = true;
		}
		
		if(opcao == 2 && vetor)
			printf("\nA soma dos numeros primos do vetor e %d\n", SomaPrimo(v));
		
		if(opcao == 3 && vetor)
			printf("\nA soma dos numeros pares do vetor e %d\n", SomaPar(v));
		
		if( (opcao == 2 || opcao == 3) && !vetor)
			printf("\nDigite os elementos do vetor\n");
		
		if( (opcao < 1) || (opcao > 4) )
			printf("\nOpcao invalida. Por favor escolha uma opcao entre 1 e 4\n");
		
	}while(opcao != 4);
	
	return 0;
}
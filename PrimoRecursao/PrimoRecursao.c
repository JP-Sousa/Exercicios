/* Desenvolva o código em C de uma função recursiva que recebe um vetor 𝑣 de tamanho
 𝑛 e retorna a quantidade de números primos em 𝑣. */ 

#include <stdio.h>

int primo2(int* v, int i, int j, int contador){
	
	if(j <= v[i]){		
	
		if(v[i] % j == 0)
			contador++;
		
		j++;
		
		contador = primo2(v, i, j, contador);
	}
	0
	return contador;
}

int primo(int n, int v[n], int i){
	
	int qntdprimos = 0, contador;
	
	if(i < n){
		
		contador = primo2(v, i, 1, 0);
		
		if(contador == 2)
			qntdprimos++; 
		
		i++;
		
		qntdprimos += primo(n, v, i);
	}
	
	return qntdprimos;
}

void RecebeVetor(int n, int v[n], int i){
	if(i < n){
		
		printf("Digite o elemento do vetor %d: ", i);
		scanf("%d", &v[i]);
		
		i++;
	
		RecebeVetor(n, v, i);
	}
}

int main(){
	
	int n;
	
	printf("\ndefine o valor do vetor: ");
	scanf("%d", &n);
	
	int v[n];
	
	RecebeVetor(n, v, 0);
	
	printf("\nA quantidade de primos no vetor e: %d\n", primo(n, v, 0));
	
	return 0;
}
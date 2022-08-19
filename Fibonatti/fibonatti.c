/* Desenvolva o código C de uma função recursiva que recebe um inteiro 𝑛 e retorna o
valor da sequência de Fibonacci de 𝑛. */

#include <stdio.h>

int fibonatti(int x){
	
	if(x == 1)
		return 1;
	else if(x == 2)
		return 1;
	
	return (fibonatti(x - 1) + fibonatti(x - 2));
}

int main(){
	
	int x; 
	
	printf("\nDigite um numero: ");
	
	scanf("%d", &x);
	
	int total = fibonatti(x);
	
	printf("\n%d = %d\n", x, total);
	
	return 0;
}
/* desenvolva o código em c de uma função que recebe duas palavras por parâmetro e 
devolve verdadeiro caso a segunda palavra seja sub-palavra da primeira ou falso caso contrario */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool subPalavra(char* s1, char* s2){

	int tamStr1 = strlen(s1), tamStr2 = strlen(s2);

	int i = 0, j = 0;

	while(i <= tamStr1 && tamStr1 >= tamStr2){ 

		if(s2[0] == s1[i]){ //Procura o primeiro caracter da string 2 na string 1

			j = 0;

			while(s2[j] == s1[i + j] && s2[j] != '\0') //Verifica se o restante da String 2 bate com a String 1
				j++;
		}

		if(j == tamStr2 && j > 0)
			return true;

		i++;
	}
	
	return false;
}

int main(){
	
	char s1[30];
	char s2[30];
	
	printf("\nDigite uma palavra: ");
	gets(s1);

	printf("\nDigite outra palavra: ");
	gets(s2);

	if(subPalavra(s1, s2))
		printf("\n%s e sub-palavra de %s\n", s2, s1);
	else
		printf("\n%s nao e sub-palavra de %s\n", s2, s1);

	return 0;
}
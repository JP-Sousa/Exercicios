/* Desenvolva um programa que consiga lidar com datas no formato DD/MM/AAAA.
Desenvolva duas funções para este programa. A primeira recebe uma data e adiciona
n dias a data, onde n é passado por parâmetro. A segunda que recebe uma data retorna
verdadeiro caso o ano seja bissexto ou falso caso contrário */

#include <stdio.h>
#include <stdbool.h>

typedef struct s_data
{
    int dia;
    int mes;
    int ano;
} Data;
 
/**
 * @brief Função que recebe uma data e retorna se o ano é bissexto ou não.
 */
bool bissexto(Data* data){

    if(data->ano % 4 == 0){

        if(data->ano % 100 == 0)
            return data->ano % 400 == 0 ? true: false;
        
        return true;
    }

   return false;
}

/**
 * @brief Função que recebe uma data e retorna a quantidade de dias no mês.
 */
int qntdiasnumes(Data* data){

    if(data->mes == 2)
        return bissexto(data) ? 29: 28;

    if(data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
        return 30;

    return 31;
}

/**
 * @brief Função que recebe uma data e a quantidade de dias a adicionar.
 */
void adicionar(Data* data, int dias){

    data->dia += dias;

    while(data->dia > qntdiasnumes(data)){

        if(data->dia > qntdiasnumes(data)){

            data->dia -= qntdiasnumes(data);

            data->mes++;
        }

        if(data->mes > 12){

            data->ano++;

            data->mes = 1;
        }
    }
}

/**
 * @brief Função que recebe uma data e verifica a integridade da data.
 */
bool verificacao(Data* data){

    if(!(data->mes > 0 && data->mes <= 12)){

        printf("\nMes incorreto, por favor digite a data novamente\n");

        return true;
    }
    else if(!(data->dia > 0 && data->dia <= qntdiasnumes(data))){

        printf("\nDia incorreto, por favor digite a data novamente\n");

        return true;
    }
    else if(!(data->ano > 0)){

        printf("\nAno incorreto, por favor digite a data novamente\n");

        return true;
    }

    return false;
}

int main(){

    Data data;
    int n;
    bool erro;

    do{
        printf("\nDigite uma data e a quantidade de dias a adicionar (Formato: 01/01/0001): ");
        scanf("%d/%d/%d%d", &data.dia, &data.mes, &data.ano, &n);

        erro = verificacao(&data);

    }while(erro);

    adicionar(&data, n);

    printf("\nData: %d/%d/%d\nBissexto: %s\n", data.dia, data.mes, data.ano, bissexto(&data) ? "Sim": "Nao");

    return 0;
}
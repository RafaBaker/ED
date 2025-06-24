//
//  ComidaNaoVegana.c
//  HawaiEd
//
//  Created by Patricia Dockhorn Costa on 22/06/22.
//

#include "ComidaNaoVegana.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vegana{
    char* nome;
    int calorias;
    float valor;
};

ComidaNaoVegana* inicComidaNaoVegana(char* nome, int calorias, float valor){
    ComidaNaoVegana* food = (ComidaNaoVegana*)malloc(sizeof(ComidaNaoVegana));
    food->calorias = calorias;
    food->nome = strdup(nome);
    food->valor = valor;
    
    return food;
}

void imprimeComidaNaoVegana (ComidaNaoVegana* food){
    printf("\nNome comida nao vegana: %s, valor: %.2f, calorias: %d\n", food->nome, food->valor, food->calorias);
}

char* retornaNomeComidaNaoVegana (ComidaNaoVegana* food){
    return food->nome;
}

void alteraCaloriasComidaNaoVegana (ComidaNaoVegana* food, int calorias){
    food->calorias = calorias;
}

int retornaCaloriasComidaNaoVegana (ComidaNaoVegana* food){
    return food->calorias;
}
                                 
float retornaValorComidaNaoVegana (ComidaNaoVegana* food){
    return food->valor;
}

void liberaComidaNaoVegana (ComidaNaoVegana* food){
    free(food->nome);
    free(food);
}

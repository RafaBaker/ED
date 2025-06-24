
#include <stdio.h>
#include "ComidaNaoVegana.h"
#include "ComidaVegana.h"

#include "Lista.h"
#include "Pedido.h"

//2 listas
//1 lista comidas > 500 calorias (calóricos)
//1 lista comidas <=500 calorias (magros)
/*Tipo que define um pedido (tipo opaco)
 *Um pedido deve ter os seguintes atributos:
 * * Numero do pedido
 * * Uma lista de comidas (veganas e nao veganas) com calorias > 500 (alimentos calóricos)
 * * Uma lista de comidas (veganas e nao veganas) com calorias <=500 (alimentos magros)
 * */
struct pedido
{
    int numero;
    Lista* magros;
    Lista* caloricos;
};

/* Cria um pedido, ainda vazio, com duas listas de alimentos, vazias
* inputs: numero do pedido.
* output: pedido alocado e vazia, com listas de alimentos ainda vazias
* pre-condicao: nao tem
* pos-condicao: pedido alocado e vazio, com listas de alimentos criadas e vazias
 */
Pedido* inicPedido (int numero)
{
    Pedido* p = malloc(sizeof(Pedido));

    p->numero = numero;
    p->magros = inicializaLista();
    p->caloricos = inicializaLista();

    return p;
}

/* Insere uma comida vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaVegana (Pedido* pedido, ComidaVegana* food)
{
    if (retornaCaloriasComidaVegana(food) > 500)
    {
        insereLista(pedido->caloricos, food, VEGANO);
    }
    else
    {
        insereLista(pedido->magros, food, VEGANO);
    }
}


/* Insere uma comida não vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaNaoVegana (Pedido* pedido, ComidaNaoVegana* food)
{
    if (retornaCaloriasComidaVegana(food) > 500)
    {
        insereLista(pedido->caloricos, food, NAOVEGANO);
    }
    else
    {
        insereLista(pedido->magros, food, NAOVEGANO);
    }
}

//retorna o numero do pedido
int retornaNumeroPedido(Pedido* pedido)
{
    return pedido->numero;
}

/* Essa função atualiza a situação de uma comida nao vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaNaoVegana(Pedido* pedido, ComidaNaoVegana* food)
{
    int calorias = retornaCaloriasComidaNaoVegana(food);
    if (calorias > 500)
    {
        // verificando se está na de magros
        if (buscaLista(pedido->magros, retornaNomeComidaNaoVegana(food)))
        {
            removeLista(pedido->magros, retornaNomeComidaNaoVegana(food));
            insereLista(pedido->caloricos, food, NAOVEGANO);
        }
    }
    else
    {
        if (buscaLista(pedido->caloricos, retornaNomeComidaNaoVegana(food)))
        {
            removeLista(pedido->magros, retornaNomeComidaNaoVegana(food));
            insereLista(pedido->magros, food, NAOVEGANO);
        }
    }
}

/* Essa função atualiza a situação de uma comida vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaVegana(Pedido* pedido, ComidaVegana* food)
{
    int calorias = retornaCaloriasComidaVegana(food);
    if (calorias > 500)
    {
        // verificando se está na de magros
        if (buscaLista(pedido->magros, retornaNomeComidaVegana(food)))
        {
            removeLista(pedido->magros, retornaNomeComidaVegana(food));
            insereLista(pedido->caloricos, food, VEGANO);
        }
    }
    else
    {
        //verificando se está nos calóricos
        if (buscaLista(pedido->caloricos, retornaNomeComidaVegana(food)))
        {
            removeLista(pedido->magros, retornaNomeComidaVegana(food));
            insereLista(pedido->magros, food, VEGANO);
        }
    }
}


//Imprime os dados do pedido, seguindo o formato a seguir
/*Imprimindo Detalhes do Pedido número: 123
  Valor total do Pedido: 135.90

 Lista de Itens de Baixa Caloria: 1
 Nome comida nao vegana: Picanha, valor: 90.50, calorias: 300

 Lista de Itens de Alta Caloria: 2
 Nome comida vegana: Empadao, calorias: 600
 Nome comida nao vegana: Sorvete de Creme, valor: 15.40, calorias: 600
*/
void imprimePedido (Pedido* pedido)
{
    printf("Imprimindo Detalhes do Pedido número: %d\n", pedido->numero);
    float total = 0;
    total = calculaValorPedido(pedido);
    printf("Valor total do pedido: %.2f\n\n", total);

    int qtdB = quantidadeLista(pedido->magros);
    printf("Lista de Itens de Baixa Caloria: %d", qtdB);
    imprimeLista(pedido->magros);
    

    int qtdA = quantidadeLista(pedido->caloricos);
    printf("Lista de Itens de Alta Caloria: %d", qtdA);
    imprimeLista(pedido->caloricos);



}

//comida vegana tem o valor fixo de 30 reais
float calculaValorPedido (Pedido* pedido)
{
    float total = 0;
    float baixaCaloria = 0;
    float altaCaloria = 0;

    if (pedido->magros)
    {
        baixaCaloria = retornaValorLista(pedido->magros);
    }
    if (pedido->caloricos)
    {
        altaCaloria = retornaValorLista(pedido->caloricos);
    }

    total = baixaCaloria + altaCaloria;
    return total;
}

/* Libera toda a memória alocada
* inputs: referencia para o pedido
* output: não tem
* pre-condicao: pedido alocado
* pos-condicao: Toda a memória liberada, a não ser alimentos, que são responsabilidade do cliente. */
void liberaPedido (Pedido* pedido)
{
    if (pedido)
    {
        desalocaLista(pedido->caloricos);
        desalocaLista(pedido->magros);
        free(pedido);
    }
    pedido = NULL;
}
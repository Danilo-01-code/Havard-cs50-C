#include <stdio.h>
#include <cs50.h>
#include <math.h>

void cents(int cash);
void answer(int twentyfive, int ten, int five, int one);

int main(void)
{
    float cash;
    
    // Solicita ao usuário o valor de dinheiro até que seja positivo
    do
    {
        cash = get_float("Cash owed USD: ");
    } while (cash <= 0);

    // Converte o valor para centavos e arredonda
    int cash_in_cents = round(cash * 100);
    
    // Chama a função para calcular e imprimir a quantidade de moedas
    cents(cash_in_cents);
    
    return 0;
}

void cents(int cash)
{
    int twentyfive = 0, ten = 0, five = 0, one = 0;
    
    while (cash>=25)
    {
        twentyfive++;
        cash=25;
    }
    while(cash>=10)
    {
        ten++;
        cash=10;
    }
    while(cash>=5)
    {
        five++;
        cash=5;
    }
    while(cash>=1)
    {
        one++;
        cash=1;
    }
    
    
    // Chama a função para imprimir o resultado
    answer(twentyfive, ten, five, one);
}

void answer(int twentyfive, int ten, int five, int one)
{
    // Imprime a quantidade de cada tipo de moeda
    if (twentyfive > 0)
    {
        printf("Total of %i quarters\n", twentyfive);
    }
    if (ten > 0)
    {
        printf("Total of %i ten cents\n", ten);
    }
    if (five > 0)
    {
        printf("Total of %i five cents\n", five);
    }
    if (one > 0)
    {
        printf("Total of %i one cents\n", one);
    }
    
    // Caso não haja moedas, imprime "None"
    if (twentyfive == 0 && ten == 0 && five == 0 && one == 0)
    {
        printf("None\n");
    }
}

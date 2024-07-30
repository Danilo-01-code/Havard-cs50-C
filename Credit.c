#include <stdio.h>
#include <cs50.h>
#include <string.h>

void cardVerification(string card);

int main(void)
{
    string card;
    do
    {
        card = get_string("Credit Card: ");
    } while (strlen(card) < 13);

    cardVerification(card);

    return 0;
}

void cardVerification(string card)
{
    if (strlen(card) == 15 && card[0] == '3' && (card[1] == '4' || card[1] == '7'))
    {
        printf("American Express Card\n");
    }
    else if (strlen(card) == 16 && card[0] == '5' && card[1] == '1' )
    {
        printf("MasterCard\n");
    }
    else if ((strlen(card) == 13 || strlen(card) == 16) && card[0] == '4')
    {
        printf("Visa Card\n");
    }
    else
    {
        printf("Cartao desconhecido\n");
    }
}

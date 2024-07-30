#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Function prototyping
string player();
int scrabble(string word);

int main(void)
{
    string word = player();
    int pontuacao = scrabble(word);
    printf("Sua pontuacao foi de %i\n", pontuacao);
    return 0;
}

string player()
{
    string word;
    bool valid;
    
    do
    {
        word = get_string("Word: ");
        valid = true;
        for (int i = 0, n = strlen(word); i < n; i++)
        {
            if (!isalpha(word[i]))
            {
                valid = false;
                break;
            }
        }
    } while (!valid);
    
    // converting to lowercase
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = tolower(word[i]);
    }

    return word;
}

int scrabble(string word)
{
    int pontuacao = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = word[i];
        if (strchr("aeioutsrnl", c))
        {
            pontuacao += 1;
        }
        else if (strchr("dg", c))
        {
            pontuacao += 2;
        }
        else if (strchr("bcmp", c))
        {
            pontuacao += 3;
        }
        else if (strchr("vwyfh", c))
        {
            pontuacao += 4;
        }
        else if (strchr("jx", c))
        {
            pontuacao += 8;
        }
        else if (strchr("zq", c))
        {
            pontuacao += 10;
        }
        else
        {
            pontuacao += 5; 
        }
    }
    return pontuacao;
}

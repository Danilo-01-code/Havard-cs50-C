#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) 
{
    char *s = get_string("i: ");
    char *t = get_string("j: ");

    if(strcmp(s,t) == 0)
    {
        printf("Same\n");
    }
    else{
        printf("diferent\n");
    }
}
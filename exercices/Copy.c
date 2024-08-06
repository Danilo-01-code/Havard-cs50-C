#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main (void)
{
    char *s = get_string("s: ");

    //maloc() = memory alocation
    char *t = malloc(strlen(s) + 1);
    //iterate string s,to copy to string t
    if(t == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
        //*(t+i) = (*s+i); is equivalent
        //strcpy(t, s); is equivalent
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    
    //print result
    printf("s: %s\n", s);
    printf("t: %c\n", t);

    //to save memory
    free(t);
}
#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    //The address of x is passed so that scanf can go to that address

    //Scanf does not have error checking in c
    scanf("%i", &x);
    printf("x: %i\n", x);
}
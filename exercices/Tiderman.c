#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define MAX_CANDIDATES 9 //Limits de max of candidates

//Store the preferences and connections betwen candidates
int preferences[MAX_CANDIDATES][MAX_CANDIDATES];
int conections[MAX_CANDIDATES][MAX_CANDIDATES];
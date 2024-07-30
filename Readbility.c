#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

 int main(void)
 {
   string text = get_str("Text:");

   int letters = 0;
   int words = 1;
   int sentences = 0;

   for (int i = 0; i < strlen(text); i++)
   {
      if (isalpha(text[i]))
      {
         letters++;
      }

      else if (text[i] == " ")
      {
         words++;
      }

      else if(text[i] == '!' || text[i] == '.' || text[i] == '?')
      {
         sentences++;
      }
   
   }
   float L = (float)letters/ (float) words * 100;
   float S = (float) sentences / (float) words * 100;
   int index = round(0.0588 * L - 0.296 * S - 15.8);
   printf("Grade: %d\n", index);;

 }
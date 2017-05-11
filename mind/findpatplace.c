#include <stdio.h>
#include "reg.h"
#include <string.h>
#include <stdlib.h>

int findpatplace(char *pattern, char *patternb, char *all, int *list, int *listb)
{
  int sig = 0, sigb = 0, l = 0, i = 0, k = 0;
  char buf[strlen(pattern)], bufb[strlen(patternb)];
  for (i = 0; i <= (int)strlen(all) - (int)strlen(pattern); i++)
  {
    
      memset(buf, 0, strlen(buf));
      memset(bufb, 0, strlen(bufb));
      for (k = i; k <= i + (int)strlen(pattern) - 1; k++)
      {

        buf[k - i] = all[k];
      }
      if (strcmp(buf, pattern) == 0)
      {

        list[sig] = i + (int)strlen(pattern);
        sig++;
        l = i + (int)strlen(pattern);

      redo:
        if (all[l] == patternb[0])
        {
          for (k = l; k <= l + (int)strlen(patternb) - 1; k++)
          {

            bufb[k - l] = all[k];
          }
          if (strcmp(bufb, patternb) == 0)
          {
            listb[sigb] = l - 1;
            sigb++;
          }
          else
          {
            ++l;
            goto redo;
          }
        }
        else
        {
          ++l;
          goto redo;
        }
      }
    }
  
  return sig;
}

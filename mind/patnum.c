#include <stdio.h>
#include "reg.h"
#include <string.h>
#include <stdlib.h>

int patnum(char *pattern, char *patternb, char *all)
{
    int sig = 0, i = 0, k = 0;
    char buf[strlen(pattern)];
    for (i = 0; i <= (int)strlen(all) - (int)strlen(pattern); i++)
    {

        memset(buf, 0, strlen(buf));
        if (all[i] == pattern[0])
        {
            for (k = i; k <= i + (int)strlen(pattern) - 1; k++)
            {

                buf[k - i] = all[k];
            }
            if (strcmp(buf, pattern) == 0)
            {

                sig++;
            }
        }
    }
    if (sig == 0)
    {
        printf("Failed to find anything.\n");
        exit(0);
    }
    return sig;
}

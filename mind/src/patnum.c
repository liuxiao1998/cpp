#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mcmp(char *all, int i, char *pat)
{
  int sig=0,k;
  for(k=i;k<i+strlen(pat);++k)
  {
    if(all[k]!=pat[k-i])
    {
      return -1;
    }
  }
  return 0;
}
int patnum(char *pattern, char *patternb, char *all)
{
    long content_length=strlen(all);
    int pa_length=strlen(pattern);
    int pb_length=strlen(patternb);
    char buf[pa_length];
    char bufb[pb_length];
    memset(buf,0,strlen(pattern));
    memset(bufb,0,strlen(patternb));
    int sig = 0, i = 0, k = 0;
    for(i=0;i<=content_length-pa_length;++i)
    {
       if(mcmp(all,i,pattern)==0)
       {
         for(k=i+pa_length;k<=content_length-pb_length;++k)
         {
           if(mcmp(all,k,patternb)==0)
           {
             ++sig;
             break;
           }
         }
       }
    }
    if (sig == 0)
    {
        printf("Failed to find anything.\n");
    }
    return sig;
}

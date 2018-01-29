#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct result{
int num;
int *list;
};
int mcmp(char *all, int i, char *pat);
int patnum(char *pattern, char *patternb, char *all);
struct result * findpatplace(char *pattern, char *patternb, char *all)
{
  struct result *res=new struct result();
  long content_length=strlen(all);
  int pa_length=strlen(pattern);
  int pb_length=strlen(patternb);
  char buf[pa_length];
  char bufb[pb_length];
  memset(buf,0,strlen(pattern));
  memset(bufb,0,strlen(patternb));

  int *list=new int[2*patnum(pattern,patternb,all)];

  int sig = 0, i = 0, k = 0;
  for(i=0;i<=content_length-pa_length;++i)
  {
     if(mcmp(all,i,pattern)==0)
     {
       for(k=i+pa_length;k<=content_length-pb_length;++k)
       {
         if(mcmp(all,k,patternb)==0)
         {
           list[sig*2]=i+pa_length;
           list[sig*2+1]=k-1;
           ++sig;
           break;
         }
       }
     }
  }
  res->num=sig;
  res->list=list;
  return res;
}

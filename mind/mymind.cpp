/*************************************************************************
	> File Name: mymind.cpp
	> Author: liuxiao
	> Mail: liuxiao1998@sjtu.edu.cn
	> Created Time: Thu 11 May 2017 08:11:43 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "./include/reg.h"
using namespace std;
int main(int argc,char **argv)
{
        if(argc!=2)
        {
        printf("help:\n");
        printf("This programme needs 1 argument!\n");
        printf("example:./main 回忆\n");
        exit(0);
        }
	char pa[]="class=\"xlistju\">";
	char pb[]="</a></div>";

	char cmd[256];
	int i,num,npatnum;
	for(i=1;i<=29;i++)
	{
	printf("%d\n",i);
	memset(cmd,0,256);
	sprintf(cmd,"wget -q -O \"./tmp\" www.juzimi.com/tags/%s?page=%d --user-agent=\"Mozilla/5.0\"",argv[1],i);
	system(cmd);
	FILE *fp;
	if(fp=fopen("./tmp","r"))
	{
		fseek(fp,0,SEEK_END);
		num=ftell(fp);
		char *cont=new char[num+1];
		memset(cont,0,strlen(cont));
		fseek(fp,SEEK_SET,0);
		fread(cont,num,1,fp);
		Res *res=findpatplace(pa,pb,cont);
		int i,k;
		FILE *ll=fopen("./heart","a+");
    if(res->num==0)
    {
      break;
    }
    for(i=0;i<res->num;++i)
    {for(k=res->list[2*i];k<=res->list[2*i+1];++k)
      {
        putchar(cont[k]);
      }
      printf("\n");
    }
    delete []res->list;
    delete []res;
		fclose(ll);
		ll=NULL;
	  delete []cont;
	}
	fclose(fp);
	fp=NULL;

	}
}

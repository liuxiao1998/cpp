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
#include "reg.h"
using namespace std;
int main()
{
	char pa[]="'text':'";
	char pb[]="'";
	char *cont;
	char cmd[256];
	int i,num,npatnum;
	for(i=1;i<=29;i++)
	{
	printf("%d\n",i);
	memset(cmd,0,256);
	sprintf(cmd,"wget -q -O \"./tmp\" www.juzimi.com/tags/暖心?page=%d --user-agent=\"Mozilla/5.0\"",i);
	system(cmd);
	FILE *fp;
	if(fp=fopen("./tmp","r"))
	{
		fseek(fp,0,SEEK_END);
		num=ftell(fp);
		cont=(char *)malloc(num+1);
		fseek(fp,SEEK_SET,0);
		fread(cont,num,1,fp);
		npatnum=patnum(pa,pb,cont);
		int *la=new int[npatnum+1];
		int *lb=new int[npatnum+1];
		findpatplace(pa,pb,cont,la,lb);
		int i,k;
		FILE *ll=fopen("./heart","a+");
		for(i=0;i<=npatnum-1;i++)
		{
			for(k=la[i];k<=lb[i];k++)
			{
				fputc(cont[k],ll);
			}
			fputc('\n',ll);
		}
		fclose(ll);
		ll=NULL;
	delete []la;
	delete []lb;
	}
	fclose(fp);
	fp=NULL;
	free(cont);
	cont=NULL;
	}
}

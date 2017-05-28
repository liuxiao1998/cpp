#include <stdio.h>
#include <stdlib.h>
int main()
{
int l,k,m;
bool sig;
int *s;
printf("num=");
scanf("%d",&l);
s=(int *)malloc(l*sizeof(int));
for(k=0;k<=l-1;++k)
{scanf("%d",&s[k]);
}
sig=false;
while(sig==false)
{
sig=true;
for(k=0;k<l-1;++k)
{if(s[k]>s[k+1])
{
sig=false;
m=s[k];
s[k]=s[k+1];
s[k+1]=m;
}
}}
for(k=0;k<=l-1;++k)
{printf("%d ",s[k]);
}
free(s);
s=NULL;
}

/*************************************************************************
	> File Name: reg.h
	> Author: liuxiao
	> Mail: liuxiao1998@sjtu.edu.cn
	> Created Time: Thu 11 May 2017 08:55:00 PM CST
 ************************************************************************/
#include "../src/patnum.c"
#include "../src/findpatplace.c"
int patnum(char *patterna,char *patternb,char *content);
void findpatplace(char *patterna,char *patternb,char *content,int *lista,int *listb);

/*************************************************************************
	> File Name: reg.h
	> Author: liuxiao
	> Mail: liuxiao1998@sjtu.edu.cn
	> Created Time: Thu 11 May 2017 08:55:00 PM CST
 ************************************************************************/
#include "../src/patnum.c"
#include "../src/findpatplace.c"
typedef struct result Res;
/*
struct result{
int num;
int *list;
}

*/
int patnum(char *patterna,char *patternb,char *content);
Res * findpatplace(char *patterna,char *patternb,char *content);

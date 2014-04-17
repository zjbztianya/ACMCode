// CF126B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 1000005
char T[MAXN],s[MAXN];
int f[MAXN];
void getfail(char *p,int len)
{
	int j;
	f[0]=j=-1;
	for(int i=1;i<len;i++)
	{
		while(j>=0&&p[j+1]!=p[i]) j=f[j];
		if(p[j+1]==p[i]) j++;
		f[i]=j;
	}
}
int find(char *s,int len)
{
	int x=strlen(T);
	int j=-1;
	for(int i=0;i<x;i++)
	{
		while(j>=0&&s[j+1]!=T[i]) j=f[j];
		if(s[j+1]==T[i]) j++;
		if(j+1==len) return len;
	}
	return -1;
}
int main()
{
	int pp=-1;
	scanf("%s",s);
	if(strlen(s)<=2) printf("Just a legend\n");
	else
	{
		getfail(s,strlen(s));
		strncpy(T,s+1,strlen(s)-2);
		T[strlen(s)-2]='\0';
		int j=strlen(s)-1;
		while(f[j]>=0)
		{
			if(f[j]+1>pp)
			{
			int t=find(s,f[j]+1);
			if(t>pp)pp=t;
			}
			j=f[j];
		}
		if(pp!=-1)
			for(int i=0;i<pp;i++) printf("%c",s[i]);
		else
			printf("Just a legend\n"); 
	}
	return 0;
}


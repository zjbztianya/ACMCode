// POJ2541.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 1000005
char p[MAXN],T[MAXN];
int f[MAXN];
void getfail(char *s)
{
	int j,len=strlen(s);
	f[0]=j=-1;
	for(int i=1;i<len;i++)
	{
		while(j>=0&&s[j+1]!=s[i]) j=f[j];
		if(s[j+1]==s[i]) j++;
		f[i]=j;
	}
}
int find(int len)
{
	int j=-1,n=strlen(T);
	for(int i=n-2;i>=0;i--)
	{
		while(j>=0&&p[j+1]!=T[i]) j=f[j];
		if(p[j+1]==T[i]) j++;
		if(j+1==len) return i;
	}
	return -1;
}
int main()
{
	int n,L;
	while(scanf("%d%d",&n,&L)!=EOF)
	{
		scanf("%s",T);
		while(L--)
		{
			int m=13;
			while(m>=n) m--;
			for(int i=n-1;i>=n-m;i--)p[n-1-i]=T[i];
			p[m]='\0';
			getfail(p);
			bool flag=false;
			for(int i=m;i>=1;i--)
			{
				int pos=find(i);
				if(pos!=-1)
				{
					printf("%c",T[pos+i]);
					T[n++]=T[pos+i];
					T[n]='\0';
					flag=true;
					break;
				}
			}
			if(!flag) 
			{
				printf("0");
				T[n++]='0';
				T[n]='\0';
			}
		}
	}
}

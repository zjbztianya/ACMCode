// UVa1328.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define  MAXN 1000005
int f[MAXN];
char p[MAXN];
int main()
{
	int n,j,cases=1;
	while(scanf("%d",&n)!=EOF&&n)
	{
		printf("Test case #%d\n",cases++);
		scanf("%s",p);
		int len=strlen(p);
		f[0]=j=-1;
		for(int i=1;i<len;i++)
		{
			while(j>=0&&p[j+1]!=p[i]) j=f[j];
			if(p[j+1]==p[i]) j++;
			f[i]=j;
		}
		for(int i=1;i<len;i++)
			if(f[i]>=0&&((i+1)%(i-f[i])==0))
				printf("%d %d\n",i+1,(i+1)/(i-f[i]));
		printf("\n");
	}
	return 0;
}


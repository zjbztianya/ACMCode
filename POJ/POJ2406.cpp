// POJ2406.cpp : 定义控制台应用程序的入口点。
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
	int n,j;
	while(scanf("%s",p)!=EOF&&p[0]!='.')
	{
		int len=strlen(p);
		f[0]=j=-1;
		for(int i=1;i<len;i++)
		{
			while(j>=0&&p[j+1]!=p[i]) j=f[j];
			if(p[j+1]==p[i]) j++;
			f[i]=j;
		}
	   if((f[len-1]>=0)&&len%(len-1-f[len-1])==0)printf("%d\n",len/(len-1-f[len-1]));
	   else
	   printf("1\n");
	}
	return 0;
}

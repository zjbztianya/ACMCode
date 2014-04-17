// POJ2752.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define  MAXN 400005
int f[MAXN];
char p[MAXN];
int main()
{
	int j;
	while(scanf("%s",p)!=EOF)
	{
		vector<int> ivec;
		int len=strlen(p);
		f[0]=j=-1;
		for(int i=1;i<len;i++)
		{
			while(j>=0&&p[j+1]!=p[i]) j=f[j];
			if(p[j+1]==p[i]) j++;
			f[i]=j;
		}
		j=len-1;
		ivec.push_back(len);
		while(f[j]>=0) 
		{
			ivec.push_back(f[j]+1);
			j=f[j];
		}
		for(int i=ivec.size()-1;i>=0;i--)
			printf("%d ",ivec[i]);
		printf("\n");
	}
	return 0;
}

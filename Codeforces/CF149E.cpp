// CF149E.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1005
char p[MAXN],T[MAXN*100];
int f[MAXN],pos[MAXN],ans;
void getfail()
{
	int j,len=strlen(p);
	f[0]=j=-1;
	for(int i=1;i<len;i++)
	{
		while(j>=0&&p[j+1]!=p[i]) j=f[j];
		if(p[j+1]==p[i]) j++;
		f[i]=j;
	}
}
void find(int d)
{
	int j=-1,lent=strlen(T),lenp=strlen(p);
	for(int i=0;i<lent;i++)
	{
		while(j>=0&&p[j+1]!=T[i]) j=f[j];
		if(p[j+1]==T[i]) 
		{
			j++;
			if(!d&&pos[j]==-1) pos[j]=i;
			if(d)
			{
				if(lenp-j-2>=0&&pos[lenp-j-2]!=-1)
				{
					if(pos[lenp-j-2]<lent-i-1)
					{
						ans++;
						break;
					}
				}
			}
		}
		if(!d&&j+1==lenp) break;
	}
}
int main()
{
	int n;
	scanf("%s",T);
	scanf("%d",&n);
	ans=0;
	for(int i=0;i<n;i++)
	{
		memset(pos,-1,sizeof(pos));
		scanf("%s",p);
		getfail(),find(0);
		reverse(p,p+strlen(p));
		reverse(T,T+strlen(T));
		getfail(),find(1);
		reverse(T,T+strlen(T));
	}
	printf("%d\n",ans);
	return 0;
}


// POJ2185.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char T[10005][80],p[10005],s[10005];
int f[10005];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
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
int main()
{
	int r,c;
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		for(int i=0;i<r;i++) scanf("%s",T[i]);
		int answ=1;
		for(int i=0;i<r;i++)
		{
			getfail(T[i]);
			int len=strlen(T[i]);
			answ=answ*(len-1-f[len-1])/gcd(answ,len-1-f[len-1]);
			if(answ>=c) 
			{
				answ=c;
				break;
			}
		}
		int ansh=1;
		for(int j=0;j<c;j++)
		{
			for(int i=0;i<r;i++)
				s[i]=T[i][j];
			s[r]='\0';
			getfail(s);
			int len=strlen(s);
			ansh=ansh*(len-1-f[len-1])/gcd(ansh,len-1-f[len-1]);
			if(ansh>=r) 
			{
				ansh=r;
				break;
			}
		}
		printf("%d\n",ansh*answ);
	}
	return 0;
}


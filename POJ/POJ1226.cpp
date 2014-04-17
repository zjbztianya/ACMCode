// POJ1226.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define  MAXN 105
#define INF 0x3f3f3f3f
char T[MAXN][MAXN];
int f[MAXN];
void getfail(char *p,int len)
{
	int j;
	f[0]=j=-1;
	for(int i=1;i<len;i++)
	{
		while(j>=0&&p[j+1]!=p[i]) j=f[j];
		if(p[j+1]==p[i])j++;
		f[i]=j;
	}
}
bool find(char *s,int len,int n)
{
	getfail(s,len);
	for(int i=0;i<n;i++)
	{
		int j=-1,lt=strlen(T[i]);
		bool flag1=false,flag2=false;
		for(int t=0;t<lt;t++)
		{
			while(j>=0&&s[j+1]!=T[i][t]) j=f[j];
			if(s[j+1]==T[i][t]) j++;
			if(j+1==len) 
			{
				flag1=true;
				break;
			}
		}
		char ss[MAXN];
		strcpy(ss,T[i]);
		reverse(ss,ss+lt);
		j=-1;
		for(int t=0;t<lt;t++)
		{
			while(j>=0&&s[j+1]!=ss[t]) j=f[j];
			if(s[j+1]==ss[t]) j++;
			if(j+1==len) 
			{
				flag2=true;
				break;
			}
		}
		if(!flag1&&!flag2) return false;
	}
	return true;

}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int n,maxlen=-INF,len=INF;
		char s[MAXN];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",T[i]);
			if(len>strlen(T[i]))
			{
				len=strlen(T[i]);
				strcpy(s,T[i]);
			}
		}
		for(int i=0;i<len;i++)
		{
			int l=i,r=len-1,lens=-INF;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				bool flag=find(s+i,mid-i+1,n);
				if(flag)
				{
					l=mid+1;
					lens=mid-i+1;
				}
				else
					r=mid-1;
				if(lens!=-INF&&lens>maxlen) maxlen=lens;
			}
		}
		if(maxlen!=-INF)
			printf("%d\n",maxlen);
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
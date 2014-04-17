// POJ3450.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define  MAXN 4005
char p[205],T[MAXN][205];
int f[205];
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
bool find(char *s,int len,int n)
{
	getfail(s,len);
	for(int t=0;t<n;t++)
	{ 
		int j=-1,lens=strlen(T[t]);
		bool flag=false;
		for(int i=0;i<lens;i++)
		{
			while(j>=0&&s[j+1]!=T[t][i]) j=f[j];
			if(s[j+1]==T[t][i]) j++;
			if(j+1==len)
			{
				flag=true;
				break;
			}
		}
		if(!flag) return false;
	}
	return true;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		char s[MAXN],temp[MAXN];
		temp[0]='\0';
		for(int i=0;i<n;i++) scanf("%s",T[i]);
		strcpy(s,T[0]);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			char ss[MAXN];
			ss[0]='\0';
			int l=i,r=len-1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				bool flag=find(s+i,mid-i+1,n);
				if(flag)
				{
					l=mid+1;
					strncpy(ss,s+i,mid-i+1);
					ss[mid-i+1]='\0';
				}
				else r=mid-1;
			}
			if(strlen(ss)>strlen(temp)||(strlen(ss)==strlen(temp)&&strcmp(ss,temp)==-1)) strcpy(temp,ss);
		}
		if(strlen(temp)>0)
			printf("%s\n",temp);
		else printf("IDENTITY LOST\n");
	}
	return 0;
}
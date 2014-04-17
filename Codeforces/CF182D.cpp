// CF182D.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
string T,s1,s2;
int f[100005];
void getfail(string s)
{
	int j,len=s.length();
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
	int a,b;
	cin>>s1>>s2;
	int n=s1.length(),m=s2.length();
	getfail(s1);
	if(n%(n-1-f[n-1])==0)a=n-1-f[n-1];
	else a=n;
	getfail(s2);
	if(m%(m-1-f[m-1])==0)b=m-1-f[m-1];
	else b=m;
	if(a==b)
	{
		for(int i=0;i<a;i++)  
			if(s1[n-i-1]!=s2[m-i-1]) 
			{
				printf("0\n");
				return 0;
			}
			int ans=0,t=a,ll=min(n,m);
			while(t<=ll)
			{
				if(n%t==0&&m%t==0) ans++;
				t+=a;
			}
			printf("%d\n",ans);
	}
	else
		printf("0\n");
	return 0;
}


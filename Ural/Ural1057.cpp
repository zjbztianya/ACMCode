// Ural1057.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 35
int f[MAXN][MAXN];
void init()
{
	f[0][0]=1;
	for(int i=1;i<32;i++)
	{
		f[i][0]=f[i-1][0];
		for(int j=1;j<=i;j++)
			f[i][j]=f[i-1][j]+f[i-1][j-1];
	}
}
int change(int x,int b)
{
	int p[MAXN];
	int ans=0;
	while(x)
	{
		p[ans++]=x%b;
		x/=b;
	}
	reverse(p,p+ans);
	for(int i=0;i<ans;i++)
		if(p[i]>1)
		{
			for(int j=i;j<ans;j++)
				p[j]=1;
			break;
		}
		for(int i=0;i<ans;i++)
			x=x|(p[ans-i-1]<<i);
		return x;
}
int cal(int x,int k)
{
	int tot=0,ans=0;
	for(int i=31;i>0;i--)
	{
		if(x&(1<<i))
		{
			tot++;
			if(tot>k) break;
			x=x^(1<<i);
		}
		if((1<<(i-1))<=x)
			ans+=f[i-1][k-tot];
	}
	if(tot+x==k) ans++;
	return ans;
}
int main()
{
	init();
	int x,y,k,b;
	while(cin>>x>>y>>k>>b)
	{
		int X=change(x,b);
		int Y=change(y,b);
		cout<<cal(Y,k)-cal(X-1,k)<<endl;
	}
	return 0;
}


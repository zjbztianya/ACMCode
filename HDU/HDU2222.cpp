// HDU2222.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxnode=500005;
const int sigma_size=26;
int ans;
struct AhoCorasickAutomata 
{
	int ch[maxnode][sigma_size],last[maxnode];
	int fail[maxnode],val[maxnode];
	int sz;
	void init()
	{
		memset(ch[0],0,sizeof(ch[0]));
		sz=1;
	}
   int idx(char c){return c-'a';}
	void insert(char *s)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]++;
	}
	void getfail()
	{
		queue<int>q;
		fail[0]=0;
		for(int c=0;c<sigma_size;c++)
		{
			int u=ch[0][c];
			if(u){ fail[u]=0;q.push(u);last[u]=0;}
		}
		while(!q.empty())
		{
			int r=q.front();q.pop();
			for(int c=0;c<sigma_size;c++)
			{
				int u=ch[r][c];
				if(!u){ch[r][c]=ch[fail[r]][c];continue;}
				q.push(u);
				fail[u]=ch[fail[r]][c];
				last[u] = val[fail[u]]?fail[u]:last[fail[u]];
			}
		}
	}
	void print(int j)
	{
		if(j)
		{
			ans+=val[j];
			val[j]=0;
			print(last[j]);
		}
	}
	void find(char *T)
	{
		int n=strlen(T);
		int j=0;
		for(int i=0;i<n;i++)
		{
			int c=idx(T[i]);
			j=ch[j][c];
			if(val[j]) print(j);
			else if(last[j]) print(last[j]);
		}
	}
};
AhoCorasickAutomata  ac;
char text[1000005],s[55];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		ac.init();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			ac.insert(s);
		}
		ac.getfail();
		scanf("%s",text);
		ans=0;
		ac.find(text);
		printf("%d\n",ans);
	}
	return 0;
}


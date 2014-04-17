// HDU3065.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int maxnode=50005;
const int sigma_size=26;
const int maxs=1005;
struct AhoCorasickAutomata 
{
	int ch[maxnode][sigma_size],last[maxnode];
	int fail[maxnode],end[maxnode],cnt[maxs];
	int sz;
	void init()
	{
		memset(ch[0],0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
		sz=1;
	}
	int idx(char c){return c-'A';}
	void insert(char *s,int v)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				end[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		end[u]=v;
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
				last[u] = end[fail[u]]?fail[u]:last[fail[u]];
			}
		}
	}
	void count(int j)
	{
		if(j)
		{
			cnt[end[j]]++;
			count(last[j]);
		}
	}
	void find(char *T)
	{
		int n=strlen(T);
		int j=0;
		for(int i=0;i<n;i++)
		{
			if(!isupper(T[i]))
				{
					j=0;
					continue;
			    }
			int c=idx(T[i]);
			j=ch[j][c];
			if(end[j]) count(j);
			else if(last[j]) count(last[j]);
		}
	}
};
AhoCorasickAutomata ac;
char text[2000000],P[1005][60];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		ac.init();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",P[i]);
			ac.insert(P[i],i);
		}
		ac.getfail();
		scanf("%s",text);
		ac.find(text);
		for(int i=1;i<=n;i++)
		   if(ac.cnt[i]) printf("%s: %d\n",P[i],ac.cnt[i]);
	}
	return 0;
}


// HDU286(AC自动机).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxnode=100005;
const int sigma_size=127;
const int maxlen=10005;
int ans;
struct AhoCorasickAutomata 
{
	int ch[maxnode][sigma_size];
	int end[maxnode];
	int fail[maxnode];
	int last[maxnode];
	int sz;
	bool visit[505];
	void init()
	{
		memset(ch[0],0,sizeof(ch[0]));
		sz=1;
	}
	void insert(char *s,int v)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if(!ch[u][s[i]])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				end[sz]=0;
				ch[u][s[i]]=sz++;
			}
			u=ch[u][s[i]];
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
			if(u){fail[u]=0;q.push(u);last[u]=0;}
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
	void print(int j)
	{
		if(j)
		{
			visit[end[j]]=true;
			print(last[j]);
		}
	}
	void find(char *T,int t,int v)
	{
		int n=strlen(T),j=0;
		bool first=true;
		memset(visit,false,sizeof(visit));
		for(int i=0;i<n;i++)
		{
			j=ch[j][T[i]];
			if(end[j])
			{
				if(first) 
				{
					printf("web %d:",v);
					first=false;
					ans++;
				}
				print(j);
			}
			else if(last[j])
				print(last[j]);
		}
		for(int i=1;i<=t;i++)
			if(visit[i]) printf(" %d",i);
		if(!first)printf("\n");
	}

};
AhoCorasickAutomata ac;
char s[205],T[maxlen];
int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		ac.init();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			ac.insert(s,i);
		}
		ac.getfail();
		scanf("%d",&m);
		ans=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%s",&T);
			ac.find(T,n,i);
		}
		printf("total: %d\n",ans);
	}
	return 0;
}


// ZOJ3228(AC自动机).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 100005
const int maxnode=600005;
const int sigma_size=26;
char T[MAXN],s[7];
bool flag[MAXN];
int pos[MAXN];
struct  Triegragh
{
	int ch[maxnode][sigma_size];
	int fail[maxnode];
	int deep[maxnode];
	int cnt[maxnode][2];
	int end[maxnode];
	int last[maxnode];
	int val[maxnode];
	int sz;
	void init()
	{
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
		memset(end,-1,sizeof(end));
		memset(val,0,sizeof(val));
	}
	int idx(char c){return c-'a';}
	int insert(char *s)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=0;
				deep[sz]=i+1;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]++;
		return u;
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
				last[u]=val[fail[u]]?fail[u]:last[fail[u]];
			}
		}
	}
	void count(int j,int i)
	{
		if(j)
		{
			cnt[j][0]++;
			if(i-end[j]>=deep[j])
			{
				cnt[j][1]++;
				end[j]=i;
			}
			count(last[j],i);
		}
	}
	void find(char *T)
	{
		int j=0,n=strlen(T);
		for(int i=0;i<n;i++)
		{
			int c=idx(T[i]);
			j=ch[j][c];
			if(val[j])
				count(j,i);
			else 
				if(last[j]) count(last[j],i);
		}
	}
};
Triegragh ac;
int main()
{
	int kase=0; 
	while(scanf("%s",T)!=EOF)
	{
		printf("Case %d\n",++kase);
		int n;
		scanf("%d",&n);
		ac.init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%s",&flag[i],s);
			pos[i]=ac.insert(s);
		}
		ac.getfail();
		ac.find(T);
		for(int i=1;i<=n;i++)
			printf("%d\n",ac.cnt[pos[i]][flag[i]]);
		printf("\n");
	}
	return 0;
}


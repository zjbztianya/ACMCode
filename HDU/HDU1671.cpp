// HDU1671.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxnode=111111;
const int sigma_size=11;
bool flag;
int ans;
struct Trie
{
	int ch[maxnode][sigma_size];
	int  val[maxnode];
	int sz;
	void clear(){sz=1;memset(val,0,sizeof(val));memset(ch[0],0,sizeof(ch[0]));}
	int idx(char c){return c-'0';}
	void insert(char *s)
	{
		int u=0,n=strlen(s),ans=0;
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				ch[u][c]=sz++;
				ans++;
			}
			else
				if(val[ch[u][c]])
					flag=true;
			u=ch[u][c];
		}
		if(!ans) flag=true;
		val[u]++;
	}
};
Trie trie;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		trie.clear();
		char num[15];
		int n;
		flag=false;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",num);
			if(flag) continue;
			trie.insert(num);
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}

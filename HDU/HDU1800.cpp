// HDU1800.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxnode=3000*30+100;
const int sigma_size=11;
int ans;
struct Trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	void clear(){sz=1;memset(ch[0],0,sizeof(ch[0]));memset(val,0,sizeof(val));}
	int idx(char c){return c-'0';}
	void insert(char *s)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]++;
		ans=max(ans,val[u]);
	}
};
Trie trie;
int getpos(char *str)
{
	int len=strlen(str),i=0;
	while(i<len&&str[i]=='0') i++;
	if(i<len) return i;
	return len-1;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		trie.clear();
		char num[35];
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",num);
			trie.insert(num+getpos(num));
		}
		printf("%d\n",ans);
	}
	return 0;
}



// HDU1247.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define  MAXN 50005
char s[MAXN][30];
const int maxnode=MAXN*25+100;
const int sigma_size=26;
struct  Trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	Trie(){sz=1;val[0]=0;memset(ch[0],0,sizeof(ch[0]));}
	int idx(char c){return c-'a';}
	void insert(char *s,int v)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(sz));
				val[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]=v;
	}
	bool find_prefix(const char *s,int len)
	{
		int u=0;
		for(int i=0;i<len;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
				return false;
			u=ch[u][c];
		}
		if(val[u]) return true;
		return false;
	}

};
Trie trie;
int main()
{
	//freopen("sb.txt","r",stdin);
	//freopen("hehe.txt","w",stdout);
	int cnt=0;
	while(scanf("%s",s[cnt])!=EOF)
		trie.insert(s[cnt++],cnt);
	for(int i=0;i<cnt;i++)
	{
		int size=strlen(s[i]);
		for(int j=1;j<size-1;j++)
		{
			if(trie.find_prefix(s[i],j)&&trie.find_prefix(s[i]+j,size-j))
			{
				printf("%s\n",s[i]);
				break;
			}
		}
	}
	return 0;
}




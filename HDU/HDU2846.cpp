// HDU2846.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxnode=3000000+100;
const int sigma_size=26;
struct Trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int id[maxnode];
	int sz;
	void clear(){sz=1;memset(val,0,sizeof(val));memset(ch[0],0,sizeof(ch[0]));}
	int idx(int c){return c-'a';}
	void insert(char *s,int p)
	{
		 int u=0,n=strlen(s);
		 for(int i=0;i<n;i++)
		 {
			 int c=idx(s[i]); 
			 if(!ch[u][c])
			 {
				  memset(ch[sz],0,sizeof(ch[sz]));
				  val[sz]++;
				  id[sz]=p;
				  ch[u][c]=sz++;
			 }
			 else
			 {
			      if(id[ch[u][c]]!=p) val[ch[u][c]]++;
				  id[ch[u][c]]=p;
			 }
			 u=ch[u][c];
		 }
	}
	int find(const char *s)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			 int c=idx(s[i]);
			 if(!ch[u][c]) return 0;
			 u=ch[u][c];
		}
		return val[u];
	}
};
Trie trie;
int main()
{
	int n;
	char name[25];
	while(scanf("%d",&n)!=EOF)
	{
		trie.clear();
		for(int t=0;t<n;t++)
		{
			scanf("%s",name);
			int len=strlen(name);
			for(int i=0;i<len;i++)
			trie.insert(name+i,t);
		}
		int m;
		scanf("%d",&m);
		while(m--)
		{
			char s[25];
			scanf("%s",s);
			printf("%d\n",trie.find(s));
		}
	}
	return 0;
}


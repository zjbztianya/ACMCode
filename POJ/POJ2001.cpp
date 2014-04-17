// POJ2001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxnode=22222;
const int sigma_size=26;
char s[1005][sigma_size];
struct Trie
{
	int ch[maxnode][sigma_size];
	int cnt[maxnode];
	int sz;
	Trie()
	{
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
	}
	int idx(char c){ return c-'a';}
	void insert(char *s,int v)
	{
		   int u=0,n=strlen(s);
		   for(int i=0;i<n;i++)
		   {
			   int c=idx(s[i]);
			   if(!ch[u][c])
			   {
				   memset(ch[sz],0,sizeof(ch[sz]));
				   cnt[sz]++;
				   ch[u][c]=sz++;
			   }
			   else
				   cnt[ch[u][c]]++;
			   u=ch[u][c];
		   }
	}
	void find_prifix(const char *ss,int x)
	{
		  int u=0,n=strlen(ss),pos=x;
		  for(int i=0;i<n;i++)
		  {
			  int c=idx(ss[i]);
			    if(cnt[ch[u][c]]==1&&i<n-1) 
				{
					pos=-1;
					for(int j=0;j<=i;j++)
						printf("%c",ss[j]);
					printf("\n");
					break;
				}
				u=ch[u][c];
		  }
		  if(pos!=-1) printf("%s\n",s[pos]);
	}
};
Trie trie;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cnt=0;
	while(scanf("%s",s[cnt])!=EOF)
	{
	 trie.insert(s[cnt],cnt);
	 cnt++;
	}
	for(int i=0;i<cnt;i++)
	{
		printf("%s ",s[i]);
	    trie.find_prifix(s[i],i);
	}
	return 0;
}


// HDU1251.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxnode=3000005;
const int sigma_size=26;
struct Trie
{
	   int ch[maxnode][sigma_size];
	   int  val[maxnode];
	   int sz;
	   Trie(){sz=1;memset(val,0,sizeof(val));memset(ch[0],0,sizeof(ch[0]));}
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
						val[sz]++;
						ch[u][c]=sz++;
					}
					else
					val[ch[u][c]]++;
					u=ch[u][c];
			 }
	   }
	   int find_prefixes(const char *s)
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
	char word[15];
	while(gets(word)&&word[0]!='\0')
		 trie.insert(word);
	while(scanf("%s",word)!=EOF)
		  printf("%d\n",trie.find_prefixes(word));
	return 0;
}


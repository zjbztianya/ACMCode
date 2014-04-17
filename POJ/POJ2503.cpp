// POJ2503.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxnode=1000000+100;
const int sigma_size=26;
char s[100005][15];
struct Trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	Trie(){sz=1;memset(ch[sz],0,sizeof(ch[sz]));val[0]=0;}
	int idx(char c){return c-'a';}
	void insert(char *s,int v)
	{
		  int u=0,n=strlen(s);
		  for(int i=0;i<n;i++)
		  {
			  int c=idx(s[i]);
			  if(!ch[u][c])
			  {
				  val[sz]=0;
				  memset(ch[sz],0,sizeof(ch[sz]));
				  ch[u][c]=sz++;
			  }
			  u=ch[u][c];
		  }
		  val[u]=v;
	}
	int find(const char *s)
	{
		  int u=0,n=strlen(s);
		  for(int i=0;i<n;i++)
		  {
			    int c=idx(s[i]);
				if(!ch[u][c])
					return -1;
				u=ch[u][c];
		  }
		  return val[u];
	}

};
Trie trie;
int main()
{
	char word[50];
	int cnt=0;
	while(gets(word)&&word[0]!='\0')
	{
		int len=strlen(word),i;
 		    for(i=0;word[i]!=' ';i++)
			s[cnt][i]=word[i];
		    s[cnt][i]='\0';
			trie.insert(word+i+1,cnt);
			cnt++;
	}
	while(scanf("%s",word)!=EOF)
	{
		  int pos=trie.find(word);
		  if(pos!=-1)
			  printf("%s\n",s[pos]);
		  else
		      printf("eh\n");
	}
	return 0;
}


// HDU1075.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int maxnode = 3000005;
const int sigma_size = 26;
char dic[maxnode][15];
struct Trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	Trie(){sz=1;memset(ch[0],0,sizeof(ch[0]));val[0]=-1;}
	int idx(char c){return c-'a';}
	void insert(char *s,int v)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=-1;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]=v;
	}
	int find(const char *s)
	{
		int u=0;
		for(int i=0;s[i]!='\0';i++)
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
	char word[15];
	int cnt=0;
	scanf("%s",word);
	while(scanf("%s",word)!=EOF)
	{
		if(word[0]=='E') break;
		strcpy(dic[cnt],word);
		scanf("%s",word);
		trie.insert(word,cnt);
		cnt++;
	}
	scanf("%s",word);
	getchar();
	char ch;
	int len=0;
	while(scanf("%c",&ch)!=EOF&&ch!='E')
	{
		if(islower(ch))
			word[len++]=ch;
		else
		{
			word[len]='\0';
			int pos=trie.find(word);
			if(pos>=0)
				printf("%s",dic[pos]);
			else
				if(word[0]!='\0')
					printf("%s",word);
			 printf("%c",ch);
			 len=0;
		}
	}
	return 0;
}


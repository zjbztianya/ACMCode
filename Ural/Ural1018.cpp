// Ural1018.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 105
typedef struct
{

	int l,r;
	int num;
}TreeNode;
TreeNode tree[MAXN];
int dp[MAXN][MAXN],n,q;
bool visit[MAXN];
int apple[MAXN][MAXN];
void build(int root)
{
	visit[root]=true;
	for(int i=1;i<=n;i++)
	{
		if(!visit[i]&&apple[root][i])
		{
			if(!tree[root].l)
				tree[root].l=i;
			else
				tree[root].r=i;
			tree[i].num=apple[root][i];
			build(i);
		}
	}
}
void TreeDp(int root,int s)
{
	if(dp[root][s]!=-1) return;  
	if(root==0||s==0)
	{
		dp[root][s]=0;
		return;
	}
	for(int i=0;i<s;i++)
	{
		   TreeDp(tree[root].l,i);
		   TreeDp(tree[root].r,s-i-1);
		   dp[root][s]=max(dp[root][s],dp[tree[root].l][i]+dp[tree[root].r][s-i-1]+tree[root].num);
	}
}
int main()
{
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		memset(visit,false,sizeof(visit));
		memset(apple,false,sizeof(apple));
		memset(tree,0,sizeof(tree));
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n-1;i++)
		{
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			apple[a][b]=w;
			apple[b][a]=w;
		}
		build(1);
		TreeDp(1,q+1);
		printf("%d\n",dp[1][q+1]);
	}
	return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 105
vector<int> G[MAXN];
int dp[2][MAXN][MAXN*2],value[MAXN];
int n,m;
void dfs(int u,int fa)
{
	for(int i=0;i<=m;i++) 
	{
		dp[0][u][i]=dp[1][u][i]=value[u];
	}
	for(size_t i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(fa==v) continue;
		dfs(v,u);
		for(int j=m-1;j>=0;j--)
		{
			for(int k=0;k<=j;k++)
			{
				dp[0][u][j+2]=max(dp[0][u][j+2],dp[0][u][j-k]+dp[0][v][k]);
				dp[1][u][j+2]=max(dp[1][u][j+2],dp[1][u][j-k]+dp[0][v][k]);
				dp[1][u][j+1]=max(dp[1][u][j+1],dp[0][u][j-k]+dp[1][v][k]);
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++) 
			scanf("%d",&value[i]);
		for(int i=0;i<MAXN;i++) G[i].clear();
			memset(dp,0,sizeof(dp));
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,-1);
		printf("%d\n",max(dp[0][1][m],dp[1][1][m]));
	}
	return 0;
}
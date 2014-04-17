#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define MAXN 105
vector<int>G[MAXN];
int dp[MAXN][MAXN*5],value[MAXN],p[MAXN][MAXN];
int n,T,V;
bool dfs1(int rt,int u,int fa)
{
	if(rt==u)
       return true;
	for(size_t i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		int w=p[u][v];
		if(fa==v) continue;
		if(dfs1(rt,v,u))
		{
			V+=w;
			p[u][v]=0;
			p[v][u]=0;
			return true;
		}
	}
	return false;
}
void dfs2(int u,int fa)
{
	 for(int i=0;i<=T;i++) dp[u][i]=value[u];
	 for(size_t i=0;i<G[u].size();i++)
	 {
	 	int v=G[u][i];
	 	int w=2*p[u][v];
        if(v==fa) continue;
        dfs2(v,u);
        for(int j=T;j>=w;j--)
        for(int k=0;k<=j-w;k++)
        dp[u][j]=max(dp[u][j],dp[u][j-k-w]+dp[v][k]); 
	 }	
}
int main()
{
	while(scanf("%d%d",&n,&T)!=EOF)
	{
         for(int i=0;i<MAXN;i++)
         {
         	G[i].clear();
         }
         for(int i=1;i<n;i++)
         {
         	int u,v,w;
         	scanf("%d%d%d",&u,&v,&w);
         	G[u].push_back(v);
         	G[v].push_back(u);
         	p[u][v]=p[v][u]=w;
         }
         for(int i=1;i<=n;i++) scanf("%d",&value[i]);
         memset(dp,0,sizeof(dp));
         V=0;
         dfs1(n,1,-1);
         if(V>T) 
         	printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
         else
         {
         	 T-=V;
         	 dfs2(1,-1);
         	 printf("%d\n",dp[1][T]);
         }
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 205
vector<int>G[MAXN];
int value[MAXN],dp[MAXN][MAXN];
int n,m;
void dfs(int u,int fa)
{
    dp[u][1]=value[u];
    int len=G[u].size();
    for(int i=0; i<len; i++)
    {
        int v=G[u][i];
        if(fa==v) continue;
        dfs(v,u);
        for(int j=m; j>1; j--)
            for(int k=1; k<j; k++)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=0; i<MAXN; i++) G[i].clear();
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            int u;
            scanf("%d%d",&u,&value[i]);
            G[u].push_back(i);
        }
        m++;
        dfs(0,-1);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}

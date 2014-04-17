#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 12
#define INF 0x3f3f3f3f
int dp[1<<MAXN][MAXN];
int dis[MAXN][MAXN];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                scanf("%d",&dis[i][j]);
        memset(dp,INF,sizeof(dp));
        n++;
        dp[(1<<n)-1][0]=0;
        for(int s=(1<<n)-1; s>=0; s--)
            for(int v=0; v<n; v++)
                for(int u=0; u<n; u++)
                    //if(!(s>>u&1))
                    dp[s][v]=min(dp[s][v],dp[s|1<<u][u]+dis[v][u]);
        printf("%d\n",dp[0][0]);
    }
    return 0;
}

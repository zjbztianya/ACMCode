#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 205
#define V 400
int p[MAXN],d[MAXN];
int dp[MAXN][25][MAXN*4];
int path[MAXN][25][MAXN*4];
int n,m,kase;
void DP()
{
    memset(dp,-1,sizeof(dp));
    dp[0][0][V]=0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=min(i,m); j++)
            for(int k=-V; k<=V; k++)
            {
                dp[i][j][k+V]=dp[i-1][j][k+V];
                path[i][j][k+V]=0;
                int ds=k-d[i]+p[i];
                if(j>=1&&ds+V>=0&&ds-V<=0)
                {
                    int ans=dp[i-1][j-1][ds+V];
                    if(ans!=-1&&ans+p[i]+d[i]>dp[i][j][k+V])
                    {
                        dp[i][j][k+V]=ans+p[i]+d[i];
                        path[i][j][k+V]=1;
                    }
                }
            }
}
void dfs(int l,int r,int c)
{
    if(l==0&&r==0&&c==0) return;
    if(path[l][r][c+V]==0)
        dfs(l-1,r,c);
    else
    {
        dfs(l-1,r-1,c-d[l]+p[l]);
        printf(" %d",l);
    }

}
void output()
{
    for(int i=0; i<=V; i++)
        if(dp[n][m][V+i]>dp[n][m][V-i])
        {
            printf("Jury #%d\n",++kase);
            printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[n][m][i+V]-i)/2,(dp[n][m][i+V]+i)/2);
            dfs(n,m,i);
            break;
        }
        else if(dp[n][m][V-i]!=-1)
        {
            printf("Jury #%d\n",++kase);
            printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[n][m][-i+V]+i)/2,(dp[n][m][-i+V]-i)/2);
            dfs(n,m,-i);
            break;
        }
    printf("\n\n");

}
int main()
{
    kase=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=1; i<=n; i++) scanf("%d%d",&p[i],&d[i]);
        DP();
        output();
    }
    return 0;
}




#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 105
int dp[MAXN][MAXN],w[MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) scanf("%d",&w[i][j]);
        for(int i=1;i<=n;i++) dp[i][i]=dp[i-1][i-1]+w[i][i];
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=m; j++)
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+w[i][j]);
    printf("%d\n",dp[n][m]);
    return 0;
}

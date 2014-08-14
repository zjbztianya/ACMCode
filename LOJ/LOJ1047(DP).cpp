/*************************************************************************
	> File Name: LOJ1047.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 20时16分16秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 25
#define INF 0x3f3f3f3f
int cost[maxn][3];
int dp[maxn][3];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=0; j<3; j++) scanf("%d",&cost[i][j]);
        memset(dp,INF,sizeof(INF));
        dp[0][0]=dp[0][1]=dp[0][2]=0;
        for(int i=1; i<=n; i++)
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+cost[i][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+cost[i][1];
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+cost[i][2];
        }
        int ans=INF;
        for(int i=0;i<3;i++) ans=min(ans,dp[n][i]);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}

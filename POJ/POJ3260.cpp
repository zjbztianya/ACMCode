#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000005
#define INF 0x3f3f3f3f
int dp[2][MAXN],sum[MAXN];
int  cnt[105],value[105];
int cash;
void ZeroOnePack(int c,int k)
{
    for(int i=cash; i>=c; i--)
        if(dp[0][i]>dp[0][i-c]+k)
            dp[0][i]=dp[0][i-c]+k;
}
void MultiplePack(int c,int m)
{
    int k=1;
    while(k<m)
    {
        ZeroOnePack(k*c,k);
        m-=k;
        k*=2;
    }
    if(m>0) ZeroOnePack(c*m,m);
}
int main()
{
    int n,T;
    while(scanf("%d%d",&n,&T)!=EOF)
    {
        cash=0;
        int maxv=-INF;
        memset(dp,INF,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&value[i]);
            maxv=max(maxv,value[i]);
        }
        for(int i=1; i<=n; i++) scanf("%d",&cnt[i]);
        cash=maxv*maxv;
        dp[0][0]=dp[1][0]=0;
        for(int i=1; i<=n; i++) MultiplePack(value[i],cnt[i]);
        for(int i=1; i<=n; i++)
            for(int j=value[i]; j<=cash; j++)
                dp[1][j]=min(dp[1][j],dp[1][j-value[i]]+1);
        int ans=INF;
        for(int i=T; i<=cash; i++)
            ans=min(ans,dp[0][i]+dp[1][i-T]);
        if(ans==INF) printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}


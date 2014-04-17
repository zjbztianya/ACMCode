#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1005
#define INF 0x3f3f3f3f
int dp[MAXN][MAXN],a[MAXN],sum[MAXN];
int L,C;
int count(int n)
{
    int cnt=1,sums=0;
    for(int i=1; i<=n; i++)
    {
        if(sums+a[i]>L)
        {
            cnt++;
            sums=a[i];
        }
        else
            sums+=a[i];
    }
    return cnt;
}
int cal(int t)
{
    if(!t) return 0;
    else if(t<=10) return -C;
    else
        return (t-10)*(t-10);
}
int main()
{
    int n,kase=0;
    bool first=true;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d%d",&L,&C);
        sum[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        int cnt=count(n);
        memset(dp,INF,sizeof(dp));
        for(int i=0; i<=n; i++)   dp[0][i]=cal(L)*i;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=i&&j<=cnt; j++)
            {
                for(int k=i-1; k>=0&&sum[i]-sum[k]<=L ; k--)
                {
                    int t=cal(L-(sum[i]-sum[k]));
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+t);
                }
            }
        if(!first) printf("\n");
        else  first=false;
        printf("Case %d:\n\n",++kase);
        printf("Minimum number of lectures: %d\n",cnt);
        printf("Total dissatisfaction index: %d\n",dp[n][cnt]);
    }
    return 0;
}


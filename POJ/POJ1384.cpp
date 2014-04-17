#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 10005
#define INF 0x3f3f3f3f
int dp[MAXN],w[505],p[505];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
           int e,h;
           scanf("%d%d",&e,&h);
           int n,m=h-e;
           memset(dp,INF,sizeof(dp));
           dp[0]=0;
           scanf("%d",&n);
           for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&w[i]);
           for(int i=1;i<=n;i++)
           for(int j=w[i];j<=m;j++)
           dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
           if(dp[m]!=INF)
                    printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
                    else
                    printf("This is impossible.\n");
    }
    return 0;
}

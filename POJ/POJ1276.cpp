#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 100005
int dp[MAXN];
int  value[15],cnt[15];
int cash,n;
void CompletePack(int c,int w)
{
    for(int i=c; i<=cash; i++)
        dp[i]=max(dp[i],dp[i-c]+w);
}
void ZeroOnePack(int c,int w)
{
    for(int i=cash; i>=c; i--)
        dp[i]=max(dp[i],dp[i-c]+w);
}
void MultiplePack(int c,int w,int m)
{
    if(c*m>=cash)
    {
        CompletePack(c,w);
        return;
    }
    int k=1;
    while(k<m)
    {
        ZeroOnePack(k*c,k*w);
        m-=k;
        k*=2;
    }
    if(m>0) ZeroOnePack(c*m,w*m);
}
int main()
{

    while(scanf("%d",&cash)!=EOF)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d%d",&cnt[i],&value[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            MultiplePack(value[i],value[i],cnt[i]);
        printf("%d\n",dp[cash]);
    }
    return 0;
}

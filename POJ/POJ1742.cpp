/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 100005
bool dp[MAXN];
int  value[105],cnt[105];
int  n,cash,ans;
void CompletePack(int c)
{
    for(int i=c; i<=cash; i++)
        if(!dp[i]&&dp[i-c])
        {
            dp[i]=true;
            ans++;
        }
}
void ZeroOnePack(int c)
{
    for(int i=cash; i>=c; i--)
        if(!dp[i]&&dp[i-c])
        {
            dp[i]=true;
            ans++;
        }
}
void MultiplePack(int c,int m)
{
    if(c*m>=cash)
    {
        CompletePack(c);
        return;
    }
    int k=1;
    while(k<m)
    {
        ZeroOnePack(k*c);
        m-=k;
        k*=2;
    }
    if(m>0) ZeroOnePack(c*m);
}
int main()
{
    while(scanf("%d%d",&n,&cash)!=EOF)
    {
        if(!(n+cash)) break;
        for(int i=1; i<=n; i++) scanf("%d",&value[i]);
        for(int i=1; i<=n; i++) scanf("%d",&cnt[i]);
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        ans=0;
        for(int i=1; i<=n; i++)
            MultiplePack(value[i],cnt[i]);
        printf("%d\n",ans);
    }
    return 0;
}*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 100005
bool dp[MAXN];
int cnt[MAXN];
int  value[105],sum[105];
int  n,m,ans;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=1; i<=n; i++) scanf("%d",&value[i]);
        for(int i=1; i<=n; i++) scanf("%d",&sum[i]);
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        ans=0;
        for(int i=1; i<=n; i++)
        {
            memset(cnt,0,sizeof(cnt));
            for(int j=value[i]; j<=m; j++)
                if(!dp[j]&&dp[j-value[i]]&&cnt[j-value[i]]<sum[i])
                {
                    dp[j]=true;
                    ans++;
                    cnt[j]=cnt[j-value[i]]+1;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}


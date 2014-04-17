#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 105
int dp[MAXN];
struct node
{
    int t,p,s;
};
node a[MAXN];
bool cmp(const node x,const node y)
{
    return x.t<y.t;
}
int main()
{
    int n,k,T;
    while(scanf("%d%d%d",&n,&k,&T)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++) scanf("%d",&a[i].t);
        for(int i=1; i<=n; i++) scanf("%d",&a[i].p);
        for(int i=1; i<=n; i++) scanf("%d",&a[i].s);
        sort(a+1,a+n+1,cmp);
        for(int i=1; i<=n; i++) if(a[i].t<=T&&a[i].t>0&&a[i].t>=a[i].s) dp[i]=a[i].p;
        for(int i=1; i<=n&&a[i].t<=T; i++)
        {
            if(a[i].t<=0||a[i].t<a[i].s) continue;
            for(int j=1; j<i; j++)
                if((a[i].t-a[j].t)>=abs(a[i].s-a[j].s))
                    dp[i]=max(dp[i],dp[j]+a[i].p);
        }
        printf("%d\n",*max_element(dp+1,dp+n+1));
    }
    return 0;
}

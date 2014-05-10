#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 100005
typedef long long LL;
LL a[maxn],b[maxn],dp[maxn];
int q[maxn];
double h(int x,int y)
{
    return (dp[x]-dp[y])/(b[x]-b[y]);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
        for(int i=1; i<=n; i++) scanf("%lld",&b[i]);
        memset(dp,0,sizeof(dp));
        int head=0,tail=0;
        q[0]=1;
        for(int i=2; i<=n; i++)
        {
            while(head<tail&&(dp[q[head+1]]+a[i]*b[q[head+1]])<(dp[q[head]]+b[q[head]]*a[i])) head++;
            dp[i]=dp[q[head]]+a[i]*b[q[head]];
            while(head<tail&&(h(i,q[tail])>h(q[tail],q[tail-1]))) tail--;
            q[++tail]=i;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}

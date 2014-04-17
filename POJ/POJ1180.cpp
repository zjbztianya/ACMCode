#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define INF 0x3f3f3f3f
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
LL minv[MAXN<<2],sum[MAXN];
int a[MAXN],que[MAXN];
LL dp[MAXN];
void PushUp(int s)
{
    minv[s]=min(minv[s<<1],minv[s<<1|1]);
}
void update(int p,int l,int r,int s,LL value)
{
    if(l==r)
    {
        minv[s]=value;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,lson,value);
    if(p>m) update(p,rson,value);
    PushUp(s);
}

int main()
{
    int n;
    LL m;
    scanf("%d%lld",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>m)
        {
            printf("-1\n");
            return 0;
        }
        sum[i]=sum[i-1]+a[i];
    }
    memset(minv,INF,sizeof(minv));
    int head=1,tail=0,k=0;
    for(int i=1; i<=n; i++)
    {
        while(sum[i]-sum[k]>m) k++;
        while(head<=tail&&que[head]<k+1)  update(head++,1,n,1,INF);
        while(head<=tail&&a[que[tail]]<=a[i])    update(tail--,1,n,1,INF);
        que[++tail]=i;
        if(head<tail) update(tail-1,1,n,1,dp[que[tail-1]]+a[i]);
        dp[i]=min(dp[k]+a[que[head]],minv[1]);
    }
    printf("%lld\n",dp[n]);
    return 0;
}



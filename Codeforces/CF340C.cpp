#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100005
typedef long long LL;
LL sum[MAXN],a[MAXN];
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
    LL ans=0;
    for(int i=1; i<=n; i++)
        ans+=sum[n]-2*sum[i]+(2*i-n+1)*a[i];
    LL d=gcd(ans,n);
    printf("%I64d %I64d\n",ans/d,n/d);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;
LL check(LL k,LL n,LL m)
{
    LL ret=0;
    for(LL i=1; i<=n; i++)
        if(k/i<=m) ret+=k/i;
        else ret+=m;
    return ret;
}
int main()
{
    LL n,m,k;
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)!=EOF)
    {
        LL l=1,r=n*m,ans;
        while(l<=r)
        {
            LL mid=(l+r)>>1;
            if(check(mid,n,m)>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%I64d\n",ans);
    }
}
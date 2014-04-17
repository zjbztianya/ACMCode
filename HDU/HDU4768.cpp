#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 20005
#define INF 0x3f3f3f3f
typedef long long LL;
LL a[MAXN],b[MAXN],c[MAXN];
LL n;
LL check(LL r)
{
    LL ret=0;
    for(int i=0; i<n; i++)
    {
        LL rr=min(r,b[i]);
        if(a[i]<=rr)
            ret+=(rr-a[i])/c[i]+1;
    }
    return ret;
}
int main()
{
    while(scanf("%I64d",&n)!=EOF)
    {
        LL l=INF,r=-INF;
        for(int i=0; i<n; i++)
        {
            scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
            l=min(l,a[i]);
            r=max(r,b[i]);
        }
        LL pos=-1;
        while(l<=r)
        {
            LL m=(l+r)>>1;
            if(check(m)&1)
            {
                r=m-1;
                pos=m;
            }
            else
                l=m+1;
        }
        if(pos==-1) printf("DC Qiang is unhappy.\n");
        else
        {
            LL ans=0;
            for(int i=0; i<n; i++)
                if(a[i]<=pos&&pos<=b[i]&&(pos-a[i])%c[i]==0)ans++;
            printf("%I64d %I64d\n",pos,ans);
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define MAXN 100005
int sum[MAXN];
int main()
{
    int n,ans=0;
    LL m;
    scanf("%d%I64d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        sum[i]=sum[i-1]+num;
    }
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n,t=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(sum[mid]-sum[i-1]<=m)
            {
                l=mid+1;
                t=mid-i+1;
            }
            else r=mid-1;
        }
        ans=max(ans,t);
    }
    printf("%d\n",ans);
    return 0;
}

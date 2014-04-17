#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    LL sum=0,l=0,r,ans,a;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&a);
        sum+=a;
        l=max(l,a);
    }
    r=sum;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(mid*(n-1)>=sum)
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    printf("%I64d\n",ans);
    return 0;
}

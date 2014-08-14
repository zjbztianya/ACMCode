/*************************************************************************
	> File Name: LOJ1005.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月07日 星期四 11时12分34秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL go(LL k,LL n)
{
    LL ret=1;
    for(LL i=k;i<=n;i++) ret*=i;
    return ret;
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        LL n,k,ans=0;
        scanf("%lld%lld",&n,&k);
        if(k>n) ans=0;
        else
        {
            LL t=go(n-k+1,n);
            ans=t/go(1,k)*t;
        }
        printf("Case %d: %lld\n",++kase,ans);
    }
}


#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    LL n,m,a;
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    LL ans=((n+a-1)/a)*((m+a-1)/a);
    printf("%I64d\n",ans);
    return 0;
}

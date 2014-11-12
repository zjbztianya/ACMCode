#include <bits/stdc++.h>
using namespace std;
#define maxn 5555
int pow_mod(int a,int n,int m)
{
    int ret=1;
    while(n)
    {
        if(n&1) ret=(ret*a)%m;
        n>>=1;
        a*=a;
        a%=m;
    }
    return ret;
}
int main()
{
    int n,k,m;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            ans+=(pow_mod(x,m,k))==0?1:0;
        }
        printf("%d\n",ans);
    }
    return 0;
}

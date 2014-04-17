#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MAXN 10000005
typedef long long LL;
int a[MAXN];
LL sum[MAXN];
int prime[MAXN],cnt=0;
int check[MAXN];
void get_prime()
{
    memset(check,0,sizeof(check));
    for(int i=2; i<MAXN; i++)
    {
        if(!check[i])
        {
            prime[cnt++]=i;
            check[i]=i;
        }
        for(int j=0; j<cnt&&i*prime[j]<MAXN; j++)
        {
            check[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}
void fac(int n)
{
    for(int i=0; i<n; i++)
    {
        int d=a[i];
        int pre=-1;
        while(d!=1)
        {
            if(pre!=check[d])
                sum[check[d]]++;
            pre=check[d];
            d/=check[d];
        }
    }
}
int main()
{
    int n,m;
    get_prime();
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    fac(n);
    for(int i=1; i<MAXN; i++) sum[i]+=sum[i-1];
    scanf("%d",&m);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        r=min(r,10000000);
        if(l>r) printf("0\n");
        else
            printf("%I64d\n",sum[r]-sum[l-1]);
    }
    return 0;
}

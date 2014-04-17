#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 100005
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
LL maxv[MAXN<<2],sumv[MAXN<<2];
void PushUp(int s)
{
    sumv[s]=sumv[s<<1]+sumv[s<<1|1];
    maxv[s]=max(maxv[s<<1],maxv[s<<1|1]);
}
void build(int l,int r,int s)
{
    if(l==r)
    {
        scanf("%lld",&sumv[s]);
        maxv[s]=sumv[s];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(s);
}
void update(int ql,int qr,int l,int r,int s)
{
    if(maxv[s]==0||maxv[s]==1) return;
    if(l==r)
    {
        sumv[s]=(LL)sqrt(sumv[s]+0.5);
        maxv[s]=sumv[s];
        return;
    }
    int m=(l+r)>>1;
    if(ql<=m) update(ql,qr,lson);
    if(qr>m) update(ql,qr,rson);
    PushUp(s);
}
LL query(int ql,int qr,int l,int r,int s)
{
      if(ql<=l&&r<=qr) return sumv[s];
      int m=(l+r)>>1;
      LL ans=0;
      if(ql<=m) ans+=query(ql,qr,lson);
      if(qr>m) ans+=query(ql,qr,rson);
      return ans;
}
int main()
{
    int n,m,kase=0;
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case #%d:\n",++kase);
        build(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            int op,a,b;
            scanf("%d%d%d",&op,&a,&b);
            if(a>b) swap(a,b);
            if(op==1)
                printf("%lld\n",query(a,b,1,n,1));
            else
                update(a,b,1,n,1);
        }
    }
    return 0;
}



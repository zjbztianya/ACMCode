#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 50005
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
#define INF 0x3f3f3f3f
int lsum[MAXN<<2],rsum[MAXN<<2],msum[MAXN<<2],sum[MAXN<<2];
int ans,rans;
void PushUp(int s)
{
    sum[s]=sum[s<<1]+sum[s<<1|1];
    msum[s]=max(msum[s<<1],msum[s<<1|1]);
    lsum[s]=max(lsum[s<<1],sum[s<<1]+max(0,lsum[s<<1|1]));
    rsum[s]=max(rsum[s<<1|1],sum[s<<1|1]+max(0,rsum[s<<1]));
    msum[s]=max(msum[s],rsum[s<<1]+lsum[s<<1|1]);
}
void build(int l,int r,int s)
{
    if(l==r)
    {
        scanf("%d",&msum[s]);
        sum[s]=lsum[s]=rsum[s]=msum[s];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(s);
}
void query(int ql,int qr,int l,int r,int s)
{
    if(ql<=l&&r<=qr)
    {
        ans=max(ans,msum[s]);
        ans=max(ans,rans+lsum[s]);
        rans=max(rsum[s],rans+sum[s]);
        return;
    }
    int m=(l+r)>>1;
    if(ql<=m) query(ql,qr,lson);
    if(qr>m)  query(ql,qr,rson);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {

        build(1,n,1);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ans=rans=-INF;
            query(a,b,1,n,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}

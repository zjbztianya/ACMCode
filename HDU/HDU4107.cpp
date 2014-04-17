#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 200005
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
int P,n,m;
int add[MAXN<<2],maxv[MAXN<<2],minv[MAXN<<2];
void PushUp(int s)
{
    maxv[s]=max(maxv[s<<1],maxv[s<<1|1]);
    minv[s]=min(minv[s<<1],minv[s<<1|1]);
}
void PushDown(int s)
{
    if(add[s])
    {
        add[s<<1]+=add[s],add[s<<1|1]+=add[s];
        minv[s<<1]+=add[s],maxv[s<<1]+=add[s];
        minv[s<<1|1]+=add[s],maxv[s<<1|1]+=add[s];
        add[s]=0;
    }
}
void build(int l,int r,int s)
{
    add[s]=0;
    maxv[s]=minv[s]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int ql,int qr,int c,int l,int r,int s)
{
    if(ql<=l&&r<=qr)
    {
        if(maxv[s]<P)
        {
            add[s]+=c;
            maxv[s]+=c;
            minv[s]+=c;
            return;
        }
        else if(minv[s]>=P)
        {
            add[s]+=2*c;
            minv[s]+=2*c;
            maxv[s]+=2*c;
            return;
        }
    }
    PushDown(s);
    int m=(l+r)>>1;
    if(ql<=m) update(ql,qr,c,lson);
    if(qr>m) update(ql,qr,c,rson);
    PushUp(s);
}
void query(int l,int r,int s)
{
    if(l==r)
    {
        l==1?printf("%d",add[s]):printf(" %d",add[s]);
        return;
    }
    PushDown(s);
    int m=(l+r)>>1;
    query(lson);
    query(rson);
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&P)!=EOF)
    {
        build(1,n,1);
        for(int i=0; i<m; i++)
        {
            int l,r,c;
            scanf("%d%d%d",&l,&r,&c);
            update(l,r,c,1,n,1);
        }
        query(1,n,1);
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define lson l,m,ls[s]
#define rson m+1,r,rs[s]
typedef long long LL;
int ls[80*MAXN],rs[80*MAXN],add[80*MAXN];
LL sum[80*MAXN];
int T[MAXN];
bool mark[80*MAXN];
int tot;
void PushUp(int s)
{
    sum[s]=sum[ls[s]]+sum[rs[s]];
}
void PushDown(int s,int l,int r)
{
    if(mark[s])
    {
        ++tot;
        sum[tot]=sum[ls[s]],add[tot]=add[ls[s]];
        ls[tot]=ls[ls[s]],rs[tot]=rs[ls[s]],ls[s]=tot;
        ++tot;
        sum[tot]=sum[rs[s]],add[tot]=add[rs[s]];
        ls[tot]=ls[rs[s]],rs[tot]=rs[rs[s]],rs[s]=tot;
        mark[ls[s]]=mark[rs[s]]=true;
        mark[s]=false;
    }
    if(add[s])
    {
        int m=(l+r)>>1;
        add[ls[s]]+=add[s];
        add[rs[s]]+=add[s];
        sum[ls[s]]+=(LL)add[s]*(m-l+1);
        sum[rs[s]]+=(LL)add[s]*(r-m);
        add[s]=0;
    }
}
void build(int l,int r,int &s)
{
    s=++tot;
    mark[s]=false;
    add[s]=0;
    if(l==r)
    {
        scanf("%lld",&sum[s]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(s);
}
void update(int last,int ql,int qr,int d,int l,int r,int &s)
{
    s=++tot;
    if(ql<=l&&r<=qr)
    {
        ls[s]=ls[last],rs[s]=rs[last];
        sum[s]=sum[last]+(LL)d*(r-l+1);
        add[s]=add[last]+d;
        mark[s]=true;
        return;
    }
    add[s]=sum[s]=0;
    mark[s]=false;
    PushDown(last,l,r);
    int m=(l+r)>>1;
    ls[s]=ls[last],rs[s]=rs[last];
    if(ql<=m) update(ls[last],ql,qr,d,lson);
    if(qr>m) update(rs[last],ql,qr,d,rson);
    PushUp(s);
}
LL query(int s,int ql,int qr,int l,int r)
{
    if(ql<=l&&r<=qr)
        return sum[s];
    PushDown(s,l,r);
    int m=(l+r)>>1;
    LL ans=0;
    if(ql<=m) ans+=query(ls[s],ql,qr,l,m);
    if(qr>m) ans+=query(rs[s],ql,qr,m+1,r);
    return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        tot=0;
        build(1,n,T[0]);
        int tm=0;
        for(int i=0; i<m; i++)
        {
            char op[10];
            int l,r,t;
            scanf("%s",op);
            if(op[0]=='Q')
            {
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(T[tm],l,r,1,n));
            }
            else if(op[0]=='C')
            {
                int d;
                tm++;
                scanf("%d%d%d",&l,&r,&d);
                update(T[tm-1],l,r,d,1,n,T[tm]);
            }
            else if(op[0]=='H')
            {
                scanf("%d%d%d",&l,&r,&t);
                printf("%lld\n",query(T[t],l,r,1,n));
            }
            else
            {
                scanf("%d",&t);
                tm=t;
            }
        }
    }
    return 0;
}

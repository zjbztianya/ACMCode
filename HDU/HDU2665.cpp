#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100005
#define lson l,m,ls[s]
#define rson m+1,r,rs[s]
int ls[20*MAXN],rs[20*MAXN];
int cnt[20*MAXN],T[MAXN];
int a[MAXN],num[MAXN],tot;
void build(int l,int r,int &s)
{
    s=++tot;
    cnt[s]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int last,int p,int l,int r,int &s)
{
    s=++tot;
    ls[s]=ls[last],rs[s]=rs[last];
    cnt[s]=cnt[last]+1;
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m) update(ls[last],p,lson);
    else     update(rs[last],p,rson);
}
int query(int ss,int tt,int l,int r,int k)
{
    if(l==r) return r;
    int sum=cnt[ls[ss]]-cnt[ls[tt]];
    int m=(l+r)>>1;
    if(sum>=k) return query(ls[ss],ls[tt],l,m,k);
    else       return query(rs[ss],rs[tt],m+1,r,k-sum);
}
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            a[i]=num[i];
        }
        sort(a+1,a+n+1);
        int len=unique(a+1,a+n+1)-a-1;
        tot=0;
        build(1,len,T[0]);
        for(int i=1; i<=n; i++) num[i]=lower_bound(a+1,a+len+1,num[i])-a;
        for(int i=1; i<=n; i++) update(T[i-1],num[i],1,len,T[i]);
        while(m--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",a[query(T[r],T[l-1],1,len,k)]);
        }
    }
    return 0;
}

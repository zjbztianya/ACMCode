#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100005
int ls[20*MAXN],rs[20*MAXN];
int T[MAXN],cnt[20*MAXN];
int a[MAXN],num[MAXN];
int tot;
void build(int l,int r,int &s)
{
    s=++tot;
    cnt[s]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(l,m,ls[s]);
    build(m+1,r,rs[s]);
}
void update(int last,int p,int l,int r,int &s)
{
    s=++tot;
    cnt[s]=cnt[last]+1;
    ls[s]=ls[last],rs[s]=rs[last];
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m) update(ls[last],p,l,m,ls[s]);
    else     update(rs[last],p,m+1,r,rs[s]);
}
int query(int ss,int tt,int l,int r,int k)
{
    if(l==r) return r;
    int m=(l+r)>>1;
    int sum=cnt[ls[ss]]-cnt[ls[tt]];
    if(sum>=k) return query(ls[ss],ls[tt],l,m,k);
    else       return query(rs[ss],rs[tt],m+1,r,k-sum);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            num[i]=a[i];
        }
        sort(a+1,a+n+1);
        int total=unique(a+1,a+n+1)-a-1;
        tot=0;
        build(1,total,T[0]);
        for(int i=1; i<=n; i++) num[i]=lower_bound(a+1,a+total+1,num[i])-a;
        for(int i=1; i<=n; i++) update(T[i-1],num[i],1,total,T[i]);
        while(m--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",a[query(T[r],T[l-1],1,total,k)]);
        }
    }
    return 0;
}

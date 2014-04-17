#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define lson l,m,ls[s]
#define rson m+1,r,rs[s]
int ls[20*MAXN],rs[20*MAXN];
int cnt[20*MAXN],T[MAXN];
int a[2*MAXN],num[MAXN],tot;
int L[MAXN],R[MAXN],K[MAXN];
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
    else
        update(rs[last],p,rson);
}
int query(int ss,int tt,int ql,int qr,int l,int r)
{
    if(ql<=l&&r<=qr)
        return cnt[tt]-cnt[ss];
    int m=(l+r)>>1,ans=0;
    if(ql<=m) ans+=query(ls[ss],ls[tt],ql,qr,l,m);
    if(qr>m) ans+=query(rs[ss],rs[tt],ql,qr,m+1,r);
    return ans;
}
int main()
{
    int kase,p=0;
    scanf("%d",&kase);
    while(kase--)
    {
        int n,m,len=0;
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            a[++len]=num[i];
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&L[i],&R[i],&K[i]);
            a[++len]=K[i];
        }
        sort(a+1,a+len+1);
        len=unique(a+1,a+len+1)-a-1;
        build(1,len,T[0]);
        for(int i=1; i<=n; i++) num[i]=lower_bound(a+1,a+len+1,num[i])-a;
        for(int i=1; i<=n; i++) update(T[i-1],num[i],1,len,T[i]);
        printf("Case %d:\n",++p);
        for(int i=1; i<=m; i++)
        {
            int k=lower_bound(a+1,a+len+1,K[i])-a;
            printf("%d\n",query(T[L[i]],T[R[i]+1],1,k,1,len));
        }
    }
    return 0;
}

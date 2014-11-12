#include<bits/stdc++.h>
using namespace std;
#define maxn 111111
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
#define INF 0x3f3f3f3f
typedef long long LL;
int num[maxn];
int minv[maxn<<2],cnt[maxn<<2],gcd[maxn<<2];
struct node
{
    int minv,gcd,cnt;
};
int _gcd(int a,int b)
{
    return b==0?a:_gcd(b,a%b);
}
void pushup(int s)
{
    minv[s]=min(minv[s<<1],minv[s<<1|1]);
    gcd[s]=_gcd(gcd[s<<1],gcd[s<<1|1]);
    cnt[s]=0;
    if(minv[s<<1]==minv[s]) cnt[s]+=cnt[s<<1];
    if(minv[s<<1|1]==minv[s]) cnt[s]+=cnt[s<<1|1];
}
void build(int l,int r,int s)
{
    if(l==r)
    {
        gcd[s]=minv[s]=num[r];
        cnt[s]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(s);
}
node query(int ql,int qr,int l,int r,int s)
{
    if(ql<=l&&r<=qr)
    {
        node t;
        t.gcd=gcd[s];
        t.minv=minv[s];
        t.cnt=cnt[s];
        return t;
    }
    int m=(l+r)>>1;
    node ll,rr,ret;
    ret.cnt=0;
    ll.gcd=rr.gcd=0;
    ll.minv=rr.minv=INF;
    ll.cnt=rr.cnt=0;
    if(ql<=m) ll=query(ql,qr,lson);
    if(qr>m) rr=query(ql,qr,rson);
    ret.minv=min(ll.minv,rr.minv);
    if(ll.minv==ret.minv) ret.cnt+=ll.cnt;
    if(rr.minv==ret.minv) ret.cnt+=rr.cnt;
    ret.gcd=_gcd(ll.gcd,rr.gcd);
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&num[i]);
    build(1,n,1);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        node t=query(l,r,1,n,1);
        int ans=r-l+1;
        if(t.gcd==t.minv)
        {
            ans-=t.cnt;
        }
        printf("%d\n",ans);
    }
    return 0;
}

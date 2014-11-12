#include<bits/stdc++.h>
using namespace std;
#define maxn 111111
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
LL num[maxn],a[maxn];
int dp[maxn];
int maxv[maxn<<2],path[maxn];
void pushup(int s)
{
    maxv[s]=max(maxv[s<<1],maxv[s<<1|1]);
}
void update(int p,int val,int l,int r,int s)
{
    if(l==r)
    {
        maxv[s]+=val;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,val,lson);
    if(p>m) update(p,val,rson);
    pushup(s);
}
int  query(int ql,int qr,int l,int r,int s)
{
    if(ql<=l&&r<=qr) return maxv[s];
    int m=(l+r)>>1,ret=0;
    if(ql<=m) ret=max(ret,query(ql,qr,lson));
    if(qr>m)  ret=max(ret,query(ql,qr,rson));
    return ret;
}
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&num[i]);
        a[i]=num[i];
    }
    sort(a+1,a+n+1);
    dp[1]=1;
    update(lower_bound(a+1,a+n+1,num[1])-a,1,1,n,1);
    for(int i=2; i<=n; i++)
    {
        int l=upper_bound(a+1,a+n+1,num[i]-d)-a;
        int r=lower_bound(a+1,a+n+1,num[i]+d)-a;
        int  mx,ll,rr;
        ll=rr=0;
        if(l-1>=1) ll=query(1,l-1,1,n,1);
        if(r<=n) rr=query(r,n,1,n,1);
        if(ll>rr) mx=ll; else mx=rr;
        int pos=lower_bound(a+1,a+n+1,num[i])-a;
        int  t=query(pos,pos,1,n,1);
        dp[i]=mx+1;
        update(pos,mx+1-t,1,n,1);
    }
    int ans=query(1,n,1,n,1),cnt=0,pre=-1;
    printf("%d\n",ans);
    for(int i=n;i>=1;i--)
    {
        if(ans==dp[i]&&(pre==-1||abs(num[i]-num[pre])>=d))
        {
            path[cnt++]=i;
            ans--;
            pre=i;
        }
        if(ans==0) break;
    }
    for(int i=cnt-1;i>=0;i--) printf("%d ",path[i]);
    puts("");
    return 0;
}

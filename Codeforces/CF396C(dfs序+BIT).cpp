#include <bits/stdc++.h>
using namespace std;
#define maxn 333333
#define MOD 1000000007
typedef long long LL;
LL sum[maxn],sk[maxn];
int deg[maxn],lo[maxn],hi[maxn];
char str[maxn];
vector<int>G[maxn];
int dis,n;
void dfs(int u,int d)
{
    lo[u]=++dis;
    deg[u]=d;
    for(int i=0; i<G[u].size(); i++)
    {
        dfs(G[u][i],d+1);
    }
    hi[u]=dis;
}
int lowbit(int x)
{
    return x&-x;
}
void add(LL *c,int x,LL d)
{
    while(x<=n)
    {
        c[x]=(c[x]+d)%MOD;
        x+=lowbit(x);
    }
}
LL query(LL *c,int x)
{
    LL ret=0;
    while(x>0)
    {
        ret=(ret+c[x])%MOD;
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        memset(sk,0,sizeof(sk));
        memset(deg,0,sizeof(deg));
        for(int i=1; i<=n; i++) G[i].clear();
        for(int i=2; i<=n; i++)
        {
            int fa;
            scanf("%d",&fa);
            G[fa].push_back(i);
        }
        dis=0;
        dfs(1,0);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int op,v;
            LL k,x;
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%I64d%I64d",&v,&x,&k);
                add(sum,lo[v],x+k*deg[v]);
                add(sum,hi[v]+1,-(x+k*deg[v]));
                add(sk,lo[v],k);
                add(sk,hi[v]+1,-k);
            }
            else
            {
                scanf("%d",&v);
                LL ans=query(sum,lo[v])-query(sk,lo[v])*deg[v];
                printf("%I64d\n",(ans%MOD+MOD)%MOD);
            }
        }
    }
    return 0;
}

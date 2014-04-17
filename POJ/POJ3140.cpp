#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100005
#define INF 0x7fffffffffffffff
typedef long long LL;
struct  node
{
    int  v,next;
};
node edge[2*MAXN];
LL sum[MAXN],head[MAXN],cnt[MAXN];
bool visit[MAXN];
LL ans;
inline LL absl(LL a)
{
    if(a<0) return -a;
    else return a;
}
void addedge(int u,int v,int &k)
{
    edge[k].v=v;
    edge[k].next=head[u];
    head[u]=k++;
}
void dfs1(int u)
{
    visit[u]=true;
    sum[u]=cnt[u];
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(!visit[v])
        {
            dfs1(v);
            sum[u]+=sum[v];
        }
    }
}
void dfs2(int u,LL total)
{
    visit[u]=true;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(!visit[v])
            dfs2(v,total);
    }
    ans=min(ans,absl(2*sum[u]-total));
}
int main()
{
    int  n,m,kase=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        LL total=0;
        memset(head,-1,sizeof(head));
        memset(visit,false,sizeof(visit));
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&cnt[i]);
            total+=cnt[i];
        }
        int k=1;
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v,k);
            addedge(v,u,k);
        }
        dfs1(1);
        memset(visit,false,sizeof(visit));
        ans=INF;
        dfs2(1,total);
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}

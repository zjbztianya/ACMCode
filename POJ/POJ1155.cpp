#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 3005
#define INF 0x3f3f3f3f
struct  node
{
    int  v,next,w;
};
node edge[2*MAXN];
int head[MAXN],dp[MAXN][MAXN],cnt[MAXN],value[MAXN];
void add_edge(int u,int v,int w,int &k)
{
    edge[k].v=v;
    edge[k].w=w;
    edge[k].next=head[u];
    head[u]=k++;
}
void dfs(int u)
{
    if(head[u]==-1)
    {
        dp[u][1]=value[u];
        cnt[u]=1;
        return;
    }
    dp[u][0]=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        int w=edge[i].w;
        dfs(v);
        cnt[u]+=cnt[v];
        for(int j=cnt[u]; j>=1; j--)
            for(int k=0; k<=cnt[v]&&k<=j; k++)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]-w);
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int k=1;
        memset(head,-1,sizeof(head));
        memset(cnt,0,sizeof(cnt));
        memset(dp,-INF,sizeof(dp));
        for(int u=1; u<=n-m; u++)
        {
            int t;
            scanf("%d",&t);
            while(t--)
            {
                int v,w;
                scanf("%d%d",&v,&w);
                add_edge(u,v,w,k);
            }
        }
        for(int i=n-m+1; i<=n; i++)
            scanf("%d",&value[i]);
        dfs(1);
        for(int i=cnt[1]; i>=0; i--)
            if(dp[1][i]>=0)
            {
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}

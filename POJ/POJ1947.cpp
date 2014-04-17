#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 155
#define INF 0x3f3f3f3f
struct node
{
    int v,next;
};
node edge[MAXN];
int head[MAXN],dp[MAXN][MAXN],p;
void add_edge(int u,int v,int &k)
{
    edge[k].v=v;
    edge[k].next=head[u];
    head[u]=k++;
}
void dfs(int u)
{
    if(head[u]==-1)
    {
        dp[u][1]=0;
        return;
    }
    int cnt=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        dfs(v);
        cnt++;
    }
    dp[u][1]=cnt;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        for(int j=p; j>=2; j--)
            for(int k=1; k<=j; k++)
                dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]-1);
    }
}
int main()
{
    int n;
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        int k=1;
        memset(head,-1,sizeof(head));
        memset(dp,INF,sizeof(dp));
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v,k);
        }
        dfs(1);
        int ans=dp[1][p];
        for(int i=2; i<=n; i++)
            ans=min(ans,dp[i][p]+1);
        printf("%d\n",ans);
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 105
struct node
{
    int v,next;
};
node edge[MAXN*2];
int cnt[MAXN],head[MAXN];
int dp[MAXN][MAXN],value[MAXN];
bool visit[MAXN];
int n,m;
void add_edge(int u,int v,int &k)
{
    edge[k].v=v;
    edge[k].next=head[u];
    head[u]=k++;
}
void dfs(int u)
{
    visit[u]=true;
    for(int i=cnt[u]; i<=m; i++)
        dp[u][i]=value[u];
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(visit[v]) continue;
        dfs(v);
        for(int j=m; j>=cnt[u]; j--)
            for(int k=0; k<=j&&j-k>=cnt[u]; k++)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
    if(dp[u][0]>0)
    {
        dp[u][1]=max(dp[u][1],dp[u][0]);
        dp[u][0]=0;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==-1&&m==-1) break;
        for(int i=1; i<=n; i++)
        {
            int bugs;
            scanf("%d%d",&bugs,&value[i]);
            cnt[i]=(bugs+19)/20;
        }
        memset(dp,0,sizeof(dp));
        memset(head,-1,sizeof(head));
        memset(visit,false,sizeof(visit));
        int k=1;
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v,k);
            add_edge(v,u,k);
        }
        dfs(1);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}


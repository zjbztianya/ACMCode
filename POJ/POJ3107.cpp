#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 50005
#define INF 0x3f3f3f3f
typedef struct
{
    int adv;
    int next;
} NODE;
NODE edg[2*MAXN];
int head[MAXN],sum[MAXN],dp[MAXN];
bool visit[MAXN];
int ans;
void addege(int u,int v,int &k)
{
    edg[k].adv=v;
    edg[k].next=head[u];
    head[u]=k++;
}
void dfs1(int u)
{
    visit[u]=true;
    sum[u]=1;
    for(int i=head[u]; i!=-1; i=edg[i].next)
    {
        int v=edg[i].adv;
        if(!visit[v])
        {
            dfs1(v);
            sum[u]+=sum[v];
        }
    }
}
void dfs2(int u,int n)
{
    visit[u]=true;
    for(int i=head[u]; i!=-1; i=edg[i].next)
    {
        int v=edg[i].adv;
        if(!visit[v])
        {
            dp[u]=max(dp[u],sum[v]);
            dfs2(v,n);
        }
    }
    dp[u]=max(dp[u],n-sum[u]);
    ans=min(ans,dp[u]);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
        memset(visit,false,sizeof(visit));
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        int k=1;
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addege(u,v,k);
            addege(v,u,k);
        }
        ans=INF;
        dfs1(1);
        memset(visit,false,sizeof(visit));
        dfs2(1,n);
        for(int i=1; i<=n; i++)
            if(dp[i]==ans) printf("%d ",i);
        printf("\n");
    }
    return 0;
}


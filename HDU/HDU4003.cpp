#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 10005
struct node
{
    int v,next,w;
};
node edge[2*MAXN];
int n,s,cnt;
int dp[MAXN][15],head[MAXN];
bool visit[MAXN];
void add_edge(int u,int v,int w,int &k)
{
    edge[k].v=v;
    edge[k].w=w;
    edge[k].next=head[u];
    head[u]=k++;
}
void dfs(int u)
{
    visit[u]=true;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        int w=edge[i].w;
        if(visit[v]) continue;
        dfs(v);
        for(int j=cnt; j>=1; j--)
            for(int k=1; k<=j; k++)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]+2*w-k*w);
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&s,&cnt)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(head,-1,sizeof(head));
        memset(visit,false,sizeof(visit));
        int sum=0,k=1;
        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            sum+=w;
            add_edge(u,v,w,k);
            add_edge(v,u,w,k);
        }
        dfs(s);
        printf("%d\n",2*sum-dp[s][cnt]);
    }
    return 0;
}
//http://blog.csdn.net/shuangde800/article/details/10217167

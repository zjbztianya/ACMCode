#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 10005
struct node
{
    int next,to;
};
node edge[MAXN*2];
int head[MAXN],tot;
void add_edge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
struct qnode
{
    int next,to,lca;
};
qnode qedge[MAXN*2];
int qhead[MAXN],cnt;
void add_qedge(int u,int v)
{
    qedge[cnt].to=v;
    qedge[cnt].next=qhead[u];
    qhead[u]=cnt++;
}
int p[MAXN],in[MAXN];
bool visit[MAXN];
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
void LCA(int u)
{
    p[u]=u;
    visit[u]=true;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(!visit[v])
        {
            LCA(v);
            p[v]=u;
        }
    }
    for(int i=qhead[u]; i!=-1; i=qedge[i].next)
    {
        int v=qedge[i].to;
        if(visit[v])
        {
            qedge[i].lca=find(v);
            qedge[i^1].lca=qedge[i].lca;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,u,v;
        memset(visit,false,sizeof(visit));
        memset(head,-1,sizeof(head));
        memset(qhead,-1,sizeof(qhead));
        memset(in,0,sizeof(in));
        scanf("%d",&n);
        tot=cnt=0;
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            in[v]++;
        }
        scanf("%d%d",&u,&v);
        add_qedge(u,v);
        add_qedge(v,u);
        for(int i=1; i<=n; i++)
            if(in[i]==0)
            {
                LCA(i);
                break;
            }
        for(int i=0; i<cnt; i+=2)
            printf("%d\n",qedge[i].lca);
    }
    return 0;
}

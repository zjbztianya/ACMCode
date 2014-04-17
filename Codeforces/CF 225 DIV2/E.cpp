#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 200055
int a[MAXN];
typedef struct
{
    int adv;
    int next;
} NODE;
NODE edg[2*MAXN];
int head[MAXN],c[2][MAXN];
int low[MAXN],high[MAXN],deg[MAXN];
bool visit[MAXN];
int n,m,k,step=0;
void addege(int u,int v)
{
    edg[k].adv=v;
    edg[k].next=head[u];
    head[u]=k++;
}
void dfs(int u,int dg)
{
    int i;
    low[u]=++step;
    deg[u]=dg;
    visit[u]=true;
    for(i=head[u]; i!=-1; i=edg[i].next)
        if(!visit[edg[i].adv])
            dfs(edg[i].adv,(dg+1)%2);
    high[u]=step;
}
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int d,int fg)
{
    while(x<=n)
    {
        c[fg][x]+=d;
        x+=lowbit(x);
    }
}
int query(int x,int fg)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[fg][x];
        x-=lowbit(x);
    }
    return ret;
}
int main(void)
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    k=1;
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addege(u,v);
    }
    dfs(1,0);
    while(m--)
    {
        int op,x,v;
        scanf("%d%d",&op,&x);
        if(op==1)
        {
            scanf("%d",&v);
            add(low[x],v,deg[x]);
            add(high[x]+1,-v,deg[x]);
            add(low[x],-v,(deg[x]+1)%2);
            add(high[x]+1,v,(deg[x]+1)%2);
        }
        else
            printf("%d\n",a[x]+query(low[x],deg[x]));
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 100005
struct node
{
    int next,to,w;
};
node edge[maxn*2];
int head[maxn],tot,ans;
void add_edge(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].w=w;
    head[u]=tot++;
}
void dfs(int u,int fa)
{
    int sum=0,maxv=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        int w=edge[i].w;
        sum+=w;
        maxv=max(maxv,w);
        if(v==fa) continue;
        dfs(v,u);
    }
    if(maxv*2>=sum) ans-=sum-maxv;//sum/2¾Í´íÁË¡£¡£ÀıÈçmaxv=2,sum=5
    else ans-=sum/2;
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        ans=tot=0;
        memset(head,-1,sizeof(head));
        scanf("%d",&n);
        for(int i=0; i<n-1; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
            ans+=w;
        }
        dfs(1,-1);
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}

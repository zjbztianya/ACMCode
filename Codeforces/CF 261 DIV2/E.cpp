#include<bits/stdc++.h>
using namespace std;
#define maxn 333333
struct node
{
    int x,y,w;
    node(int _x,int _y,int _w)
    {
        x=_x,y=_y,w=_w;
    }
    node() {}
};
vector<node>edge;
int temp[maxn];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int dp[maxn],tmp[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        edge.clear();
        memset(dp,0,sizeof(dp));
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge.push_back(node(u,v,w));
        }
        sort(edge.begin(),edge.end(),cmp);
        for(int i=0; i<m; i++)
        {
            for(int j=i; edge[j].w==edge[i].w; j++)
                tmp[edge[j].y]=max(tmp[edge[j].y],dp[edge[j].x]+1);
            for(int j=i; edge[j].w==edge[i].w; j++)
            {
                dp[edge[j].y]=max(dp[edge[j].y],tmp[edge[j].y]);
                i=j;
            }
        }
        int ans=*max_element(dp,dp+maxn);
        printf("%d\n",ans);
    }
    return 0;
}

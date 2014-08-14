/*************************************************************************
	> File Name: LOJ1057.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 21时18分12秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 25
#define INF 0x3f3f3f3f
bool vis[maxn][maxn];
struct node
{
    int x,y,d;
    node(int _x,int _y,int _d)
    {
        x=_x,y=_y,d=_d;
    }
    node() {}
};
struct ND
{
    int x,y;
};
ND pos[maxn];
int dis[maxn][maxn];
int dx[8]= {0,0,-1,1,-1,-1,1,1};
int dy[8]= {-1,1,0,0,-1,1,-1,1};
int n,m;
int dp[1<<16][16];
int BFS(int s,int e)
{
    queue<node> que;
    que.push(node(pos[s].x,pos[s].y,0));
    memset(vis,false,sizeof(vis));
    vis[pos[s].x][pos[s].y]=true;
    while(!que.empty())
    {
        node t=que.front();
        if(t.x==pos[e].x&&t.y==pos[e].y) return t.d;
        for(int i=0; i<8; i++)
        {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if(x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y])
            {
                vis[x][y]=true;
                que.push(node(x,y,t.d+1));
            }
        }
        que.pop();
    }
}
int DP(int n)
{
    memset(dp,INF,sizeof(dp));
    for(int i=0; i<n; i++)
        dp[1<<i][i]=dis[n][i];
    for(int s=0; s<(1<<n); s++)
        for(int i=0; i<n; i++)
            if((s&(1<<i))&&dp[s][i]!=INF)
            {
                for(int j=0; j<n; j++)
                    if(!(s&(1<<j)))
                        dp[s|(1<<j)][j]=min(dp[s|(1<<j)][j],dp[s][i]+dis[i][j]);
            }
    int ret=INF;
    for(int i=0; i<n; i++)
        ret=min(ret,dp[(1<<n)-1][i]+dis[i][n]);
    return ret;
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int cnt=0,sx,sy;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            char s[30];
            scanf("%s",s+1);
            for(int j=1; j<=m; j++)
                if(s[j]=='x')
                {
                    sx=i;
                    sy=j;
                }
                else if(s[j]=='g')
                {
                    pos[cnt].x=i;
                    pos[cnt++].y=j;
                }
        }
        pos[cnt].x=sx;
        pos[cnt].y=sy;
        memset(dis,INF,sizeof(dis));
        for(int i=0; i<=cnt; i++) dis[i][i]=0;
        for(int i=0; i<cnt; i++)
            for(int j=i+1; j<=cnt; j++)
            {
                int d=BFS(i,j);
                dis[i][j]=dis[j][i]=d;
            }
        int ans=DP(cnt);
        printf("Case %d: %d\n",++kase,ans==INF?0:ans);
    }
}

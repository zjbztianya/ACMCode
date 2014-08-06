#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 25
int dx[4]= {0,0,-1,1};
int dy[4]= {1,-1,0,0};
int G[maxn][maxn];
bool vis[maxn][maxn];
char s[maxn];
int ans,n,m;
void dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=0; i<4; i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]&&G[tx][ty])
        {
            ans++;
            dfs(tx,ty);
        }
    }
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF&&n+m)
    {
        memset(G,0,sizeof(G));
        int x,y;
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            for(int j=0; j<m; j++)
                if(s[j]=='@')
                {
                    x=i;
                    y=j+1;
                }
                else if(s[j]=='.') G[i][j+1]=1;
        }
        memset(vis,false,sizeof(vis));
        ans=1;
        dfs(x,y);
        printf("%d\n",ans);
    }
    return 0;
}

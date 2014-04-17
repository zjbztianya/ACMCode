#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 105
int g[MAXN][MAXN];
bool visit[MAXN][MAXN];
char s[MAXN];
void dfs(int i,int j)
{
    if(g[i][j]!=1||visit[i][j]) return;
    visit[i][j]=true;
    dfs(i-1,j),dfs(i,j-1);
    dfs(i+1,j),dfs(i,j+1);
    dfs(i-1,j-1),dfs(i+1,j-1);
    dfs(i-1,j+1),dfs(i+1,j+1);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(g,-1,sizeof(g));
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s+1);
            int len=strlen(s+1);
            for(int j=1; j<=len; j++)
                if(s[j]=='W') g[i][j]=1;
                else  g[i][j]=0;
        }
        memset(visit,false,sizeof(visit));
        int ans=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(!visit[i][j]&&g[i][j])
                {
                    dfs(i,j);
                    ans++;
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}

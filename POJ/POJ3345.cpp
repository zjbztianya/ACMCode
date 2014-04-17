#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MAXN  205
#define INF 0x3f3f3f3f
vector<string>ivec[MAXN];
int value[MAXN],cnt[MAXN];
map<string,int>ms;
char s[MAXN*100],str[MAXN*100];
vector<int>G[MAXN];
bool flag[MAXN];
int  n,m,dp[MAXN][MAXN];
void  dfs(int u)
{

    int len=G[u].size();
    cnt[u]=1;
    for(int i=0; i<len; i++)
    {
        int v=G[u][i];
        dfs(v);
        cnt[u]+=cnt[v];
    }
    dp[u][0]=0;
    for(int i=0; i<len; i++)
    {
        int v=G[u][i];
        for(int j=n; j>=1; j--)
            for(int k=1; k<=j; k++)
                dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
    dp[u][cnt[u]]=value[u];
}
int main()
{
    while(gets(str)&&str[0]!='#')
    {
        sscanf(str,"%d%d",&n,&m);
        memset(flag,false,sizeof(flag));
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<MAXN; i++)
        {
            ivec[i].clear();
            G[i].clear();
        }
        ms.clear();
        for (int i = 1; i <= n; ++i)
        {
            cin>>s>>value[i];
            ms[s]=i;
            char ch;
            scanf("%c",&ch);
            while(ch!='\n')
            {
                cin>>s;
                ivec[i].push_back(s);
                scanf("%c",&ch);
            }
        }
        for(int i=1; i<=n; i++)
        {
            int len=ivec[i].size();
            for(int j=0; j<len; j++)
            {
                G[i].push_back(ms[ivec[i][j]]);
                flag[ms[ivec[i][j]]]=true;
            }
        }
        for(int i=1; i<=n; i++)
            if(!flag[i])
                G[0].push_back(i);
        memset(dp,INF,sizeof(dp));
        value[0]=INF;
        dfs(0);
        int ans=INF;
        for(int i=m; i<=n; i++)
            ans=min(ans,dp[0][i]);
        printf("%d\n",ans);
    }
    return 0;
}

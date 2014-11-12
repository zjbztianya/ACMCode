/*************************************************************************
	> File Name: LOJ1086.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月15日 星期五 15时38分10秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 16
#define INF 0x3f3f3f3f
int deg[maxn];
int dis[maxn][maxn];
vector<int>vec;
int dp[1<<maxn];
int DP()
{
    int sz=vec.size();
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    for(int s=0; s<(1<<sz); s++)
    {
        for(int i=0; i<sz; i++)
            if((s&(1<<i))==0)
            {
                for(int j=0; j<sz; j++)
                    if((s&(1<<j))==0)
                    {
                        dp[s|(1<<i)|(1<<j)]=min( dp[s|(1<<i)|(1<<j)],dp[s]+dis[vec[i]][vec[j]]);
                    }
            }
    }
    return dp[(1<<sz)-1];
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        memset(deg,0,sizeof(deg));
        memset(dis,INF,sizeof(dis));
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dis[u][v]=dis[v][u]=min(w,dis[v][u]);
            deg[u]++;
            deg[v]++;
            ans+=w;
        }
        vec.clear();
        for(int i=1; i<=n; i++) if(deg[i]&1) vec.push_back(i);
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                {
                    if(i==j||j==k||i==k) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
        ans+=DP();
        printf("Case %d: %d\n",++kase,ans);
    }
}


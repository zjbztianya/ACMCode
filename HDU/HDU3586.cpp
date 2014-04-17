#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1005
#define INF 1000010
typedef long long LL;
vector<int>ivec[MAXN],w[MAXN];
int dp[MAXN];
void dfs(int u,int limit,int fa)
{
    int len=ivec[u].size();
    bool flag=false;
    dp[u]=0;
    for(int i=0; i<len; i++)
    {
        if(fa==ivec[u][i]) continue;
        flag=true;
        dfs(ivec[u][i],limit,u);
        if(w[u][i]<=limit) dp[u]+=min(dp[ivec[u][i]],w[u][i]);
        else    dp[u]+=dp[ivec[u][i]];
    }
    if(!flag) dp[u]=INF;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=1; i<=n; i++)
        {
            ivec[i].clear();
            w[i].clear();
        }
        int l=1,r=0;
        for(int i=1; i<n; i++)
        {
            int  a,b,cost;
            scanf("%d%d%d",&a,&b,&cost);
            ivec[a].push_back(b),w[a].push_back(cost);
            ivec[b].push_back(a),w[b].push_back(cost);
            r=max(r,cost);
        }
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            dfs(1,mid,0);
            if(dp[1]<=m)
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}


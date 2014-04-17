#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 6005
int dp[MAXN][2],num[MAXN];
vector<int>ivec[MAXN];
bool visit[MAXN];
int dfs(int root,int state)
{
    if(dp[root][state]) return dp[root][state];
    if(ivec[root].empty())
    {
        if(state) return dp[root][state]=num[root];
        else  return dp[root][state]=0;
    }
    if(state)
    {
        dp[root][state]=num[root];
        for(size_t i=0; i<ivec[root].size(); i++)
            dp[root][state]+=dfs(ivec[root][i],0);
    }
    else
    {
        for(size_t i=0; i<ivec[root].size(); i++)
            dp[root][state]+=max(dfs(ivec[root][i],0),dfs(ivec[root][i],1));
    }
    return dp[root][state];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            ivec[i].clear();
        }
        memset(visit,false,sizeof(visit));
        int a,b;
        while(scanf("%d%d",&a,&b),a+b)
        {
            ivec[b].push_back(a);
            visit[a]=true;
        }
        int root;
        for(int i=1; i<=n; i++)
            if(!visit[i])
            {
                root=i;
                break;
            }
        memset(dp,0,sizeof(dp));
        printf("%d\n",max(dfs(root,0),dfs(root,1)));
    }
    return 0;
}




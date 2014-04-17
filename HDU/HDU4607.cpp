#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define  MAXN 100005
vector<int>ivec[MAXN];
int ret,sum;
void dfs(int k,int fa,int dis)
{
    if(dis>sum)
    {
        sum=dis;
        ret=k;
    }
    int len=ivec[k].size();
    for(int i=0; i<len; i++)
        if(ivec[k][i]!=fa) dfs(ivec[k][i],k,dis+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) ivec[i].clear();
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            ivec[u].push_back(v);
            ivec[v].push_back(u);
        }
        ret=1;
        sum=0;
        dfs(ret,0,0);
        dfs(ret,0,0);
        while(m--)
        {
            int k;
            scanf("%d",&k);
            if(k-1<=sum) printf("%d\n",k-1);
            else
                printf("%d\n",sum+(k-1-sum)*2);
        }
    }
    return 0;
}

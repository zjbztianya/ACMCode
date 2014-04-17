#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define  MAXN 10005
vector<int>ivec[MAXN],value[MAXN];
int  f[MAXN],g[MAXN],h[MAXN];
int son[MAXN];
int dfs1(int root)
{
    if(f[root]) return f[root];
    if(ivec[root].empty()) return 0;
    int len=ivec[root].size();
    for(int i=0; i<len; i++)
        if(dfs1(ivec[root][i])+value[root][i]>f[root])
        {
            f[root]=f[ivec[root][i]]+value[root][i];
            son[root]=ivec[root][i];
        }
    for(int i=0; i<len; i++)
        if(ivec[root][i]!=son[root]&&f[ivec[root][i]]+value[root][i]>g[root])
            g[root]=f[ivec[root][i]]+value[root][i];
    return f[root];
}
void dfs2(int root)
{
    if(ivec[root].empty()) return;
    int len=ivec[root].size();
    for(int i=0; i<len; i++)
    {
        if(ivec[root][i]!=son[root])
            h[ivec[root][i]]=value[root][i]+max(f[root],h[root]);
        else
            h[ivec[root][i]]=max(g[root],h[root])+value[root][i];
        dfs2(ivec[root][i]);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            ivec[i].clear();
            value[i].clear();
        }
        for(int i=2; i<=n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ivec[a].push_back(i);
            value[a].push_back(b);
        }
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(h,0,sizeof(h));
        f[1]=dfs1(1);
        dfs2(1);
        for(int i=1; i<=n; i++)
            printf("%d\n",max(f[i],h[i]));
    }
    return 0;
}


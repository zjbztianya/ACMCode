#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 50005
vector<int>e[MAXN],value[MAXN];
int ret = 1,sum=0;
void dfs(int k,int dis,int fa)
{
    if(dis>sum)
    {
        sum=dis;
        ret=k;
    }
    size_t len=e[k].size();
    for (size_t i=0; i<len; ++i)
        if (e[k][i]!=fa) dfs(e[k][i],dis+value[k][i],k);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            e[i].clear();
            value[i].clear();
        }
        while(m--)
        {
            int a,b,w;
            char s[3];
            scanf("%d%d%d%s",&a,&b,&w,s);
            e[a].push_back(b),value[a].push_back(w);
            e[b].push_back(a),value[b].push_back(w);
        }
        dfs(ret,0,0);
        dfs(ret,0,0);
        printf("%d\n",sum);
    }
    return 0;
}


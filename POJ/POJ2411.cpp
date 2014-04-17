#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 15
typedef long long LL;
LL dp[MAXN][1<<MAXN];
int n,m;
void dfs(int step,int s1,int s2,int line)
{
    if(step==m)
    {
        dp[line][s1]+=dp[line-1][s2];
        return;
    }
    dfs(step+1,s1<<1|1,s2<<1,line);
    dfs(step+1,s1<<1,s2<<1|1,line);
    if(step+2<=m)
        dfs(step+2,s1<<2|3,s2<<2|3,line);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m))
    {
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1]=1;
        for(int i=1; i<=n; i++)
            dfs(0,0,0,i);
        printf("%I64d\n",dp[n][(1<<m)-1]);
    }
    return 0;
}

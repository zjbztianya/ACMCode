#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 20
typedef long long LL;
LL dp[maxn][10];
int num[maxn];
LL dfs(int i,int s,int e)
{
    if(i==-1) return s==0;
    if(!e&&~dp[i][s]) return dp[i][s];
    int u=e?num[i]:9;
    LL ret=0;
    for(int d=0; d<=u; d++)
        ret+=dfs(i-1,(s+d)%10,e&&d==u);
    return e?ret:dp[i][s]=ret;
}
LL cal(LL n )
{
    int cnt=0;
    while(n)
    {
        num[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,0,1);
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        LL  x,y;
        scanf("%I64d%I64d",&x,&y);
        printf("Case #%d: %I64d\n",++kase,cal(y)-cal(x-1));
    }
}

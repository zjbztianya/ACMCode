/*************************************************************************
	> File Name: LOJ1032.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 14时59分48秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 32
LL dp[maxn][2][32];
int num[maxn];
LL dfs(int i,int s,int e,int st)
{
    if(i==-1) return st;
    if(!e&&~dp[i][s][st]) return dp[i][s][st];
    int u=e?num[i]:1;
    LL ret=0;
    for(int d=0; d<=u; d++)
    {
        int news=st;
        if(d==1&&s==1) news++;
        ret+=dfs(i-1,d,e&&d==u,news);
    }
    return e?ret:dp[i][s][st]=ret;
}
LL cal(LL n)
{
    int cnt=0;
    while(n)
    {
        num[cnt++]=n%2;
        n/=2;
    }
    return dfs(cnt-1,0,1,0);
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        LL n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",++kase,cal(n));
    }
    return 0;
}


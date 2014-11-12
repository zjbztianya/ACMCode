/*************************************************************************
	> File Name: LOJ1084.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月15日 星期五 11时01分42秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 111111
#define INF 0x3f3f3f3f
int dp[maxn],num[maxn];
int n,k;
int dfs(int i)
{
    if(i>=n) return 0;
    if(~dp[i]) return dp[i];
    int x=upper_bound(num,num+n,num[i]+k)-num;
    int ret=INF;
    if(x-i>=3) ret=min(ret,dfs(x)+1);
    if(x-i>=4) ret=min(ret,dfs(x-1)+1);
    if(x-i>=5) ret=min(ret,dfs(x-2)+1);
    return dp[i]=ret;
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        k*=2;
        for(int i=0; i<n; i++) scanf("%d",&num[i]);
        sort(num,num+n);
        memset(dp,-1,sizeof(dp));
        int ans=dfs(0);
        printf("Case %d: %d\n",++kase,ans==INF?-1:ans);
    }
    return 0;
}


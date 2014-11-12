/*************************************************************************
	> File Name: LOJ1068.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月14日 星期四 20时54分49秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 95
int dp[15][maxn][maxn];
int num[15];
int dfs(int i,int sum,int div,int e,int k)
{
    if(i==-1) return  sum==0&&div==0;
    if(!e&&~dp[i][sum][div]) return dp[i][sum][div];
    int u=e?num[i]:9;
    int ret=0;
    for(int d=0; d<=u; d++)
        ret+=dfs(i-1,(sum+d)%k,(div*10+d)%k,e&&d==u,k);
    return e?ret:dp[i][sum][div]=ret;
}
int cal(int n,int k)
{
    if(k>90&&n) return 0;
    if(k>90&&n==0) return 1;
    int cnt=0;
    while(n)
    {
        num[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,0,0,1,k);
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++kase,cal(y,k)-cal(x-1,k));
    }
}


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 10
#define INF 0x3f3f3f3f
int dp[MAXN*2][MAXN][MAXN][MAXN][MAXN];
int sum[MAXN][MAXN];
int num[MAXN][MAXN];
int sums(int x1,int y1,int x2,int y2)
{
    int ans=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
    return ans*ans;
}
int dfs(int k,int x1,int y1,int x2,int y2)
{
    if(dp[k][x1][y1][x2][y2]!=-1) return dp[k][x1][y1][x2][y2];
    if(k==0)
        return dp[k][x1][y1][x2][y2]=sums(x1,y1,x2,y2);
    int ans=INF;
    for(int a=x1; a<x2; a++)
    {
        ans=min(ans,dfs(k-1,x1,y1,a,y2)+sums(a+1,y1,x2,y2));
        ans=min(ans,dfs(k-1,a+1,y1,x2,y2)+sums(x1,y1,a,y2));
    }
    for(int b=y1; b<y2; b++)
    {
        ans=min(ans,dfs(k-1,x1,y1,x2,b)+sums(x1,b+1,x2,y2));
        ans=min(ans,dfs(k-1,x1,b+1,x2,y2)+sums(x1,y1,x2,b));
    }
    return dp[k][x1][y1][x2][y2]=ans;
}

int main()
{
    int n;
    double x=0;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
        {
            scanf("%d",&num[i][j]);
            x+=num[i][j];
        }
    x/=n;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+num[i][j];
    int tt=dfs(n-1,1,1,8,8);
    double ans=sqrt(tt*1.0/n-x*x);
    printf("%.3lf\n",ans);
    return 0;
}

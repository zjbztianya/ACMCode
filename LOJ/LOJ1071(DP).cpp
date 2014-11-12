/*************************************************************************
	> File Name: LOJ1071.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月14日 星期四 21时54分38秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 111
int dp[2*maxn][maxn][maxn];
int num[maxn][maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&num[i][j]);
        for(int k=1; k<=n+m-1; k++)
            for(int i=1; i<=k; i++)
            {
                for(int j=1; j<=k; j++)
                {
                    int s1=dp[k-1][i-1][j-1];
                    int s2=dp[k-1][i][j-1];
                    int s3=dp[k-1][i-1][j];
                    int s4=dp[k-1][i][j];
                    int sum=0;
                    sum+=num[i][k-i+1];
                    if(i!=j) sum+=num[j][k-j+1];
                    dp[k][i][j]=max(max(s1,s2),max(s3,s4))+sum;
                }
            }
        printf("Case %d: %d\n",++kase,dp[n+m-1][n][n]);
    }
    return 0;
}


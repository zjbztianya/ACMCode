/*************************************************************************
	> File Name: LOJ1033.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 16时06分43秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 111
#define INF 0x3f3f3f3f
int dp[maxn][maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        char s[maxn];
        memset(dp,0,sizeof(dp));
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=n; i>=1; i--)
            for(int j=i+1; j<=n; j++)
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i][j-1],dp[i+1][j])+1;
                }
        printf("Case %d: %d\n",++kase,dp[1][n]);
    }
}


/*************************************************************************
	> File Name: LOJ1025.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 11时03分53秒
 ************************************************************************/

#include<bits/stdc++.h>
#define maxn 66
typedef long long LL;
LL dp[maxn][maxn];
using namespace std;
char s[maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++) dp[i][i]=1;
        for(int i=n;i>=1;i--)
            for(int j=i+1;j<=n;j++)
           {
                 dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                 if(s[i]==s[j]) dp[i][j]+=dp[i+1][j-1]+1;
           }
           printf("Case %d: %lld\n",++kase,dp[1][n]);
    }
}


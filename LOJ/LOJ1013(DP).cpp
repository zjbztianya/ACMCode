/*************************************************************************
	> File Name: LOJ1013.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 08时07分36秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define maxn 33
typedef long long LL;
LL dp[maxn][maxn];
int lcs[maxn][maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        char a[maxn],b[maxn];
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),m=strlen(b+1);
        memset(lcs,0,sizeof(lcs));
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=n; i++) dp[i][0]=1;
        for(int i=0; i<=m; i++) dp[0][i]=1;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(a[i]==b[j])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    if(lcs[i-1][j]>=lcs[i][j-1])
                    {
                        lcs[i][j]=lcs[i-1][j];
                        dp[i][j]+=dp[i-1][j];
                    }
                    if(lcs[i-1][j]<=lcs[i][j-1])
                    {
                        lcs[i][j]=lcs[i][j-1];
                        dp[i][j]+=dp[i][j-1];
                    }
                }
        printf("Case %d: %d %lld\n",++kase,n+m-lcs[n][m],dp[n][m]);
    }
    return 0;
}


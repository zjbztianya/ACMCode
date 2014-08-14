/*************************************************************************
	> File Name: LOJ1110.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月07日 星期四 21时31分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 111
int dp[maxn][maxn];
string path[maxn][maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        char a[maxn],b[maxn];
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),m=strlen(b+1);
        for(int i=0; i<maxn; i++)
            for(int j=0; j<maxn; j++)
                path[i][j]="";
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(a[i]==b[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    path[i][j]=path[i-1][j-1]+a[i];
                }
                else
                {
                    if(dp[i-1][j]>dp[i][j-1])
                    {
                        dp[i][j]=dp[i-1][j];
                        path[i][j]=path[i-1][j];
                    }
                    else
                    if(dp[i-1][j]==dp[i][j-1])
                    {
                        dp[i][j]=dp[i-1][j];
                        path[i][j]=min(path[i-1][j],path[i][j-1]);
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1];
                        path[i][j]=path[i][j-1];
                    }
                }
            }
        cout<<"Case "<<++kase<<":"<<" ";
        if(dp[n][m]==0) cout<<":("<<"\n";
        else cout<<path[n][m]<<"\n";
    }
    return 0;
}


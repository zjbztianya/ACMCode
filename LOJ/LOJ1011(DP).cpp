/*************************************************************************
	> File Name: LOJ1011.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月07日 星期四 10时11分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[17][1<<17];
int num[20][20];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) scanf("%d",&num[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int s=0; s<(1<<n); s++)
            {
                int t=s,cnt=0;
                while(t)
                {
                    cnt+=t&1;
                    t>>=1;
                }
                if(cnt==i-1)
                {
                    t=s;
                    for(int j=0; j<16; j++)
                        if(!(s&(1<<j))) dp[i][s|(1<<j)]=max(dp[i][s|(1<<j)],dp[i-1][s]+num[i][j+1]);
                }
            }
        }
        printf("Case %d: %d\n",++kase,dp[n][(1<<n)-1]);
    }
    return 0;
}

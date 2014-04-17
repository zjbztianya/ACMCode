// POJ1185.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 11
int dp[MAXN*10][100][100];
int line[MAXN*10],sum[MAXN*10],s[MAXN*10];
string str[MAXN*10];
int t;
bool OK(int x)
{
    if(x&(x>>1)) return false;
    if(x&(x>>2)) return false;
    return true;
}
int getsum(int x)
{
    int ret=0;
    while(x)
    {
        ret+=(x&1);
        x>>=1;
    }
    return ret;
}
void pre_solve(int m)
{
    for(int i=0; i<(1<<m); i++)
        if(OK(i))
        {
            s[t]=i;
            sum[t]=getsum(i);
            t++;
        }
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(dp,0,sizeof(dp));
        memset(line,0,sizeof(line));
        for(int i=1; i<=n; i++) cin>>str[i];
        for(int i=1; i<=n; i++)
            for(int j=0; j<m; j++)
                line[i]|=(str[i][j]=='P'?1:0)<<j;
        t=0;
        pre_solve(m);
        for(int i=0; i<t; i++)
            if((s[i]&line[1])==s[i])
                dp[1][i][0]=sum[i];
        for(int i=2; i<=n; i++)
            for(int a=0; a<t; a++)
                if((s[a]&line[i])==s[a])
                {
                    for(int b=0; b<t; b++)
                        if((s[b]&line[i-1])==s[b])
                            for(int c=0; c<t; c++)
                                if((s[c]&line[i-2])==s[c])
                                {
                                    if(!(s[a]&s[b])&&!(s[a]&s[c])&&!(s[b]&s[c]))
                                    {
                                        dp[i][a][b]=max(dp[i][a][b],dp[i-1][b][c]+sum[a]);
                                    }
                                }
                }
        int ans=0;
        for(int a=0; a<t; a++)
            for(int b=0; b<t; b++)
                ans=max(ans,dp[n][a][b]);
        cout<<ans<<endl;
    }
    return 0;
}


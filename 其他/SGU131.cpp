// SGU131.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10
typedef long long LL;
LL dp[MAXN][1<<MAXN];
int n,m;
void dfs(int step,int s1,int s2,int u1,int u2,int line)
{
    if(step==m)
    {
        if(!u1&&!u2) dp[line][s2]+=dp[line-1][s1];
        return;
    }
    if(!u2)
    {
        if(!u1)
        {
            dfs(step+1,s1<<1,s2<<1|1,0,0,line);
            dfs(step+1,s1<<1,s2<<1|1,1,0,line);
            dfs(step+1,s1<<1,s2<<1|1,0,1,line);
        }
        dfs(step+1,(s1<<1|1)-u1,s2<<1|1,0,1,line);
        dfs(step+1,(s1<<1|1)-u1,s2<<1|1,1,1,line);
    }
    if(!u1)dfs(step+1,s1<<1,s2<<1|u2,1,1,line);
    dfs(step+1,(s1<<1|1)-u1,s2<<1|u2,0,0,line);
}
int main ()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1]=1;
        for(int i=1; i<=n; i++)
            dfs(0,0,0,0,0,i);
        printf("%I64d\n",dp[n][(1<<m)-1]);
    }
    return 0;
}

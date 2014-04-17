#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 200000
bool dp[MAXN];
int  cnt[10];
int cash,n;
void ZeroOnePack(int c)
{
    for(int i=cash; i>=c; i--)
        if(dp[i-c]) dp[i]=true;
}
void MultiplePack(int c,int m)
{
    int k=1;
    while(k<m)
    {
        ZeroOnePack(k*c);
        m-=k;
        k*=2;
    }
    if(m>0) ZeroOnePack(c*m);
}
int main()
{
    int kase=0;
    bool first=true;
    while(scanf("%d",&cnt[1])!=EOF)
    {
        cash=cnt[1];
        for(int i=2; i<=6; i++)
        {
            scanf("%d",&cnt[i]);
            cash+=cnt[i]*i;
        }
        if(!cash) break;
        if(first) first=false;
        else
            printf("\n");
        printf("Collection #%d:\n",++kase);
        if(cash&1)
        {
            printf("Can't be divided.\n");
            continue;
        }
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=1; i<=6; i++) MultiplePack(i,cnt[i]);
        if(dp[cash/2])
            printf("Can be divided.\n");
        else
            printf("Can't be divided.\n");
    }
    return 0;
}

/*************************************************************************
	> File Name: LOJ1205.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月07日 星期四 17时34分07秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 20
typedef long long LL;
int num[maxn],tmp[maxn];
LL dp[maxn][maxn];
LL dfs(int i,int len,int e,int zero)
{
    if(i==-1) return 1;
    if(!e&&~dp[i][len]) return dp[i][len];
    int u=e?num[i]:9;
    LL ret=0;
    for(int d=0; d<=u; d++)
    {
        if(zero)
        {
            tmp[i]=d;
            ret+=dfs(i-1,d==0?len-1:len,e&&d==u,zero&&d==0);
        }
        else
        {
            if(i>=len/2)
            {
                tmp[i]=d;
                ret+=dfs(i-1,len,e&&d==u,0);
            }
            else
            {
                if(d!=tmp[len-i-1]) continue;
                tmp[i]=d;
                ret+=dfs(i-1,len,e&&d==u,0);
            }
        }
    }
    return e?ret:dp[i][len]=ret;
}
LL cal(LL n)
{
    int cnt=0;
    while(n)
    {
        num[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,cnt,1,1);
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        LL l,r;
        scanf("%lld%lld",&l,&r);
        if(l>r) swap(l,r);
        printf("Case %d: %lld\n",++kase,cal(r)-cal(l-1));
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 25
int dp[MAXN][MAXN][MAXN];
int dfs(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0) return 1;
    if(dp[a][b][c]) return dp[a][b][c];
    if(a<b&&b<c)
        dp[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
    else
        dp[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
    return dp[a][b][c];
}
int main()
{
    int a,b,c;
    memset(dp,0,sizeof(dp));
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a==-1&&b==-1&&c==-1) break;
        int ans;
        if(a<=0||b<=0||c<=0) ans=1;
        else if(a>20||b>20||c>20) ans=dfs(20,20,20);
        else  ans=dfs(a,b,c);
        printf("w(%d, %d, %d) = %d\n",a,b,c,ans);
    }
    return 0;
}

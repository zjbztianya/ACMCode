#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 15
int dp[2][60000],pre[MAXN],now[MAXN];
int mp[MAXN*10+5][MAXN];
int  s[MAXN],n,m;
int To_ten(int *a)
{
    int ret=0;
    for(int i=1; i<=m; i++)
        ret+=a[i]*s[i];
    return ret;
}
void To_three(int *a,int x)
{
    for(int i=1; i<=m; i++)
    {
        a[i]=x%3;
        x/=3;
    }
}
void dfs(int sum,int x,int y,int status)
{
    dp[x][status]=max(dp[x][status],sum);
    if(y>=m) return;
    if(!pre[y]&&!pre[y+1]&&!now[y]&&!now[y+1])
    {
        now[y]=2,now[y+1]=2;
        int st=To_ten(now);
        dfs(sum+1,x,y+2,st);
        now[y]=0,now[y+1]=0;
    }
    if((y+2<=m)&&!now[y]&&!now[y+1]&&!now[y+2])
    {
        now[y]=2,now[y+1]=2,now[y+2]=2;
        int st=To_ten(now);
        dfs(sum+1,x,y+3,st);
        now[y]=0,now[y+1]=0,now[y+2]=0;
    }
    dfs(sum,x,y+1,status);
}
int main()
{
    int T;
    s[0]=0,s[1]=1;
    for(int i=2; i<=12; i++)
        s[i]=s[i-1]*3;
    scanf("%d",&T);
    while(T--)
    {
        int k;
        scanf("%d%d%d",&n,&m,&k);
        memset(dp,-1,sizeof(dp));
        memset(mp,0,sizeof(mp));
        while(k--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x][y]=1;
        }
        for(int i=1; i<=m; i++)
            pre[i]=mp[1][i]+1;
        int temp=To_ten(pre);
        dp[0][temp]=0;
        for(int i=2; i<=n; i++)
        {
            memset(dp[(i+1)&1],-1,sizeof(dp[(i+1)&1]));
            for(int j=0; j<s[m+1]; j++)
                if(dp[i&1][j]!=-1)
                {
                    To_three(pre,j);
                    for(int p=1; p<=m; p++)
                        if(mp[i][p])
                            now[p]=2;
                        else
                            now[p]=max(0,pre[p]-1);
                    temp=To_ten(now);
                    dfs(dp[i&1][j],(i+1)&1,1,temp);
                }
        }
        int ans=0;
        for(int i=0; i<s[m+1]; i++)
            ans=max(ans,dp[(n+1)&1][i]);
        printf("%d\n",ans);
    }
    return 0;
}

/*************************************************************************
	> File Name: LOJ1044.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 19时51分04秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 1111
#define INF 0x3f3f3f3f
int dp[maxn],flag[maxn][maxn];
char s[maxn];
void go(int l,int r,int n)
{
    while(l>=1&&r<=n)
    {
            if(s[l]==s[r])
            {
                flag[l][r]=1;
                l--; r++;
            }
            else break;
    }
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
          scanf("%s",s+1);
          int n=strlen(s+1);
          memset(flag,0,sizeof(flag));
          for(int i=1;i<=n;i++)
          {
              go(i,i,n);
              go(i,i+1,n);
          }
          for(int i=0;i<=n;i++) dp[i]=i;
          for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            if(flag[j][i])
          {
              dp[i]=min(dp[i],dp[j-1]+1);
          }
          printf("Case %d: %d\n",++kase,dp[n]);
    }
    return 0;
}


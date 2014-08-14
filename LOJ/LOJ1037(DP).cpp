/*************************************************************************
	> File Name: LOJ1037.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 16时59分11秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 16
#define INF 0x3f3f3f3f
int dp[1<<maxn];
int num[maxn],a[maxn][maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        memset(dp,INF,sizeof(dp));
        for(int i=0; i<n; i++) scanf("%d",&num[i]);
        for(int i=0; i<n; i++)
        {
            char s[maxn];
            scanf("%s",s);
            for(int j=0; j<n; j++)
            {
                a[i][j]=s[j]-'0';
                if(!a[i][j]) a[i][j]=1;
            }
        }
        for(int i=0; i<n; i++) dp[1<<i]=num[i];
        for(int s=1; s<(1<<n); s++)
        {
            for(int i=0; i<n; i++)
                if(!(s&(1<<i)))
                {
                       int fk=0;
                       for(int j=0;j<n;j++)
                        if(s&(1<<j)) fk=max(fk,a[j][i]);
                        dp[s|(1<<i)]=min(dp[s|(1<<i)],dp[s]+(num[i]+fk-1)/fk);
                }
        }
        printf("Case %d: %d\n",++kase,dp[(1<<n)-1]);
    }
}


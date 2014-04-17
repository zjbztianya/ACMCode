#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 10005
bool dp[MAXN][105];
int num[MAXN];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1; i<=n; i++) scanf("%d",&num[i]);
        memset(dp,false,sizeof(dp));
        dp[1][(num[1]%k+k)%k]=true;
        for(int i=2; i<=n; i++)
            for(int j=k-1; j>=0; j--)
            {
                int a=((j-num[i])%k+k)%k;
                int b=((j+num[i])%k+k)%k;
                if(dp[i-1][j])
                {
                    dp[i][a]=true;
                    dp[i][b]=true;
                }
            }
        if(dp[n][0]) printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
    return 0;
}

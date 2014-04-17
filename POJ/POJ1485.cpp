#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXN 205
#define INF 0x3f3f3f3f
int dp[35][MAXN],dis[MAXN][MAXN];
int a[MAXN],m,n,path[35][MAXN];
void count()
{
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
        {
            dis[i][j]=0;
            int mid=(i+j)>>1;
            for(int k=i; k<=j; k++)
                dis[i][j]+=abs(a[mid]-a[k]);
        }
}
void dfs(int i,int j)
{
    if(i==0) return;
    dfs(i-1,path[i][j]);
    printf("Depot %d at restaurant %d serves ",i,(j+path[i][j]+1)/2);
    if(path[i][j]+1!=j)
        printf("restaurants %d to %d\n",path[i][j]+1,j);
    else
        printf("restaurant %d\n",j);
}
int main()
{
    int kase=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        count();
        memset(dp,INF,sizeof(dp));
        for(int i=1; i<=n; i++)
            dp[1][i]=dis[1][i];
        for(int i=2; i<=m; i++)
            for(int j=i; j<=n; j++)
            {
                dp[i][i]=0;
                path[i][i]=i-1;
                for(int k=i-1; k<j; k++)
                    if(dp[i-1][k]+dis[k+1][j]<dp[i][j])
                    {
                        dp[i][j]=dp[i-1][k]+dis[k+1][j];
                        path[i][j]=k;
                    }
            }
        printf("Chain %d\n",++kase);
        dfs(m,n);
        printf("Total distance sum = %d\n\n",dp[m][n]);
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
#define MAXN 10005
int dp[MAXN];
pair<int,int>a[MAXN];
bool cmp(const pair<int,int>x,const pair<int,int>y)
{
     if(x.first==y.first) return x.second<y.second;
     return x.first<y.first;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
           if(!n)
           {
                  printf("*\n");
                  break;
           }
           memset(dp,0,sizeof(dp));
           for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second);
           sort(a+1,a+n+1,cmp);
           dp[1]=1;
           for(int i=2;i<=n;i++)
           {
                 dp[i]=1;
                 for(int j=1;j<i;j++)
                 if(a[j].first<=a[i].first&&a[j].second<=a[i].second&&dp[j]+1>dp[i])
                 dp[i]=dp[j]+1;
           }
           printf("%d\n",*max_element(dp+1,dp+n+1));
    }
    return 0;
}

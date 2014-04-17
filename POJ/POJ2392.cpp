#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 100005
#define N 405
bool dp[MAXN];
struct node
{
    int  h,a,c;
};
node pack[N];
int cnt[MAXN];
int  n,m,ans;
bool cmp(const node x,const node y)
{
    return x.a<y.a;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++) scanf("%d%d%d",&pack[i].h,&pack[i].a,&pack[i].c);
        sort(pack+1,pack+1+n,cmp);
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            memset(cnt,0,sizeof(cnt));
            for(int j=pack[i].h; j<=pack[i].a; j++)
                if(!dp[j]&&dp[j-pack[i].h]&&cnt[j-pack[i].h]<pack[i].c)
                {
                    dp[j]=true;
                    cnt[j]=cnt[j-pack[i].h]+1;
                    if(j>ans) ans=j;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 105
int sum[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    int ans=0,x,y;
    scanf("%d%d",&x,&y);
    for(int i=1;i<=n;i++)
    {
        if(sum[i]>=x&&sum[i]<=y&&(sum[n]-sum[i])>=x&&(sum[n]-sum[i])<=y)
        {
            if(i+1<=n){
             ans=i+1;
             break;
            }
        }

    }
    printf("%d\n",ans);
    return 0;
}

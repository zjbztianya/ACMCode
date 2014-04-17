#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 505
#define INF 0x3f3f3f3f
int num[MAXN];
bool pos[MAXN];
int n,m;
bool check(int d)
{
    int sum=0,cnt=1;
    for(int i=1; i<=n; i++)
    {
        if(num[i]>d) return false;
        if(sum+num[i]>d)
        {
            cnt++;
            sum=num[i];
        }
        else
            sum+=num[i];
    }
    if(cnt<=m) return true;
    else
        return false;
}
void print(int d)
{
    memset(pos,false,sizeof(pos));
    int sum=0,cnt=1;
    for(int i=n; i>=1; i--)
    {
        if(sum+num[i]>d)
        {
            sum=num[i];
            pos[i]=true;
            cnt++;
        }
        else sum+=num[i];
        if(i==m-cnt)
        {
            for(int j=1; j<=i; j++)     pos[j]=true;
            break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d ",num[i]);
        if(pos[i]) printf("/ ");
    }
    printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int sum=0;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        int l=0,r=sum,ans=num[1];
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid))
            {
                r=mid-1;
                ans=mid;
            }
            else  l=mid+1;
        }
        print(ans);
    }
    return 0;
}

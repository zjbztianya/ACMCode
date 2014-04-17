#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 100005
int a[MAXN];
int main()
{
    int n,k,cnt=0,t=0;
    scanf("%d%d",&n,&k);
    cnt=n-k;
    if(n==k)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1; i<=cnt/2; i++)
    {
        a[++t]=2*i;
        a[++t]=2*i-1;
    }
    if(cnt%2)
    {
        a[++t]=cnt;
        swap(a[1],a[t]);
    }
    for(int i=1; i<=t; i++) printf(" %d",a[i]);
    for(int i=cnt+1; i<=n; i++)
        printf(" %d",i);
    return 0;
}
